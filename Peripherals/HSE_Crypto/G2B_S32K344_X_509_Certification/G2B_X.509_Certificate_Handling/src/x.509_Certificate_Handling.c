/*
 * x.509_Certificate_Handling.c
 *
 *  Created on: 26-Oct-2025
 *      Author: RohanS002 Gettobyte
 */

/*
 * Simple, dependency-free PEM → DER converter (certificate only).
 *
 * This file is intentionally small and self-contained so it can be dropped
 * into embedded projects that don't want to pull in a full crypto/PERK stack.
 *
 * --------------------
 * Notes & extensions
 * --------------------
 * - Encrypted PEM:
 *     Returns P2D_ERR_ENCRYPTED_UNSUPPORTED if it sees "Proc-Type: 4,ENCRYPTED"
 *     before the footer. If you need support later, add an OpenSSL-compatible
 *     EVP_BytesToKey-style key derivation and AES/DES-CBC decrypt for the
 *     decoded Base64. For devices, it's common to forbid encrypted cert PEMs.
 *
 * - Multiple certs (chains):
 *     This function stops at the FIRST PEM block. To iterate a concatenated
 *     chain, expose an additional "next offset" out-parameter, or call this in
 *     a loop on progressively advanced pointers (find next BEGIN...).
 *
 * - Robustness:
 *     The Base64 decoder tolerates CR/LF and spaces anywhere, rejects invalid
 *     characters and illegal padding sequences.
 *
 * - Memory:
 *     Single malloc() of the exact decoded size. Caller must free().
 *
 * - Security hygiene:
 *     This file only handles public certificates (no private keys). For private
 *     keys, avoid storing in firmware; provision into HSE or other secure
 *     elements, and never keep decrypted key material in RAM longer than needed.
 */

#include "x.509_Certificate_Handling.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/* ======================
 * Small internal helpers
 * ====================== */

/* find_strn: bounded strstr(). Returns pointer to first occurrence or NULL. */
static const char* find_strn(const char* hay, size_t haylen, const char* needle) {
    size_t nlen = needle ? strlen(needle) : 0;
    if (!hay || !needle || nlen == 0 || haylen < nlen) return NULL;
    const char *end = hay + haylen - nlen + 1;
    for (const char *p = hay; p < end; ++p) {
        if (*p == *needle && memcmp(p, needle, nlen) == 0) return p;
    }
    return NULL;
}

/* skip_ws_crlf: advance over ' ', '\r', '\n' up to limit (returns limit if all skipped). */
static const char* skip_ws_crlf(const char* p, const char* limit) {
    if (!p || !limit) return NULL;
    while (p < limit && (*p == ' ' || *p == '\r' || *p == '\n')) p++;
    return p;
}

/*
 * Base64 decoding
 *  - Tolerates CR/LF/spaces anywhere.
 *  - Rejects invalid characters (ASCII > 127 or not in map).
 *  - Rejects non-padding after padding ('=' must be last in a 4-char quantum).
 *  - Size calculations avoid overflow (mirrors mbedTLS logic in spirit).
 *  - We implement only decoding (encoding not needed for this use-case).
 */

/* 128-entry decoding map: 127=invalid, 64=padding sentinel for '='. */
static const unsigned char b64map[128] = {
/* 0x00-0x0F */127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
/* 0x10-0x1F */127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
/* 0x20-0x2F */127,127,127,127,127,127,127,127,127,127,127, 62,127,127,127, 63,
/* 0x30-0x3F */ 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,127,127,127, 64,127,127,
/* 0x40-0x4F */127,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
/* 0x50-0x5F */ 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,127,127,127,127,127,
/* 0x60-0x6F */127, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
/* 0x70-0x7F */ 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,127,127,127,127,127
};

/* Compute decoded output length from a Base64 run (ignoring spaces/CR/LF). */
static int b64_decoded_len(const char* src, size_t slen, size_t* out_len) {
    if (!src || !out_len) return 0;
    size_t n = 0;
    unsigned pad = 0;
    for (size_t i = 0; i < slen; i++) {
        unsigned char c = (unsigned char)src[i];
        if (c == ' ' || c == '\r' || c == '\n') continue; /* ignore whitespace */
        if (c > 127) return 0;                              /* non-ASCII */
        unsigned char v = b64map[c];
        if (v == 127) return 0;                             /* invalid char */
        if (c == '=') {                                     /* padding */
            if (++pad > 2) return 0;
        } else if (pad) {
            /* Non-padding after '=' is illegal */
            return 0;
        }
        n++; /* count all base64 symbols including '=' */
    }

    if (n == 0) { *out_len = 0; return 1; }

    /* decoded = floor(n*6/8) - pad ; avoid overflow as in mbedTLS */
    size_t whole = (n >> 3);               /* n / 8 */
    size_t rem   = (n & 0x7);              /* n % 8 */
    size_t decoded = (6 * whole) + ((6 * rem + 7) >> 3);
    if (decoded < pad) return 0;
    decoded -= pad;

    *out_len = decoded;
    return 1;
}

/* Decode Base64 into dst. Returns 1 on success, 0 on failure. */
static int b64_decode(const char* src, size_t slen, uint8_t* dst, size_t dlen, size_t* out_len) {
    if (!src || !dst || !out_len) return 0;

    size_t need = 0;
    if (!b64_decoded_len(src, slen, &need)) return 0;
    if (dlen < need) return 0;

    uint32_t x = 0;       /* 24-bit accumulator for 4 symbols */
    unsigned block = 0;   /* symbols seen in current quartet */
    unsigned pad = 0;     /* '=' count */
    uint8_t* p = dst;

    for (size_t i = 0; i < slen; i++) {
        unsigned char c = (unsigned char)src[i];
        if (c == ' ' || c == '\r' || c == '\n') continue;

        unsigned char v = b64map[c];
        if (v == 127) return 0; /* invalid */

        if (c == '=') pad++;
        else if (pad) return 0; /* non-padding after '=' -> invalid */

        x = (x << 6) | (v & 0x3F); /* shift in 6 bits */

        if (++block == 4) {
            block = 0;
            /* Depending on how much padding we saw in this quartet, emit 1-3 bytes.
               pad=0 -> 3 bytes; pad=1 -> 2 bytes; pad=2 -> 1 byte. */
            if (pad <= 3) { if (pad <= 2) *p++ = (uint8_t)(x >> 16); }
            if (pad <= 2) { if (pad <= 1) *p++ = (uint8_t)(x >>  8); }
            if (pad == 0)               *p++ = (uint8_t)(x      );
            x = 0;
        }
    }

    *out_len = (size_t)(p - dst);
    return 1;
}

/* ==============================
 * Public API: PEM → DER (first)
 * ============================== */

int pem_cert_to_der(const char *pem_text, uint8_t **der_out, size_t *der_len) {
    if (!pem_text || !der_out || !der_len) return P2D_ERR_NULL;

    const char *HEAD = "-----BEGIN CERTIFICATE-----";
    const char *FOOT = "-----END CERTIFICATE-----";

    size_t pem_len = strlen(pem_text);

    /* 1) Find header. We look in the whole buffer to be robust against
          leading comments, other PEM blocks, etc. */
    const char* begin = find_strn(pem_text, pem_len, HEAD);
    if (!begin) return P2D_ERR_NO_CERT;

    /* 2) Advance just past the header, then skip optional spaces/CR/LF. */
    const char* after_head = begin + strlen(HEAD);
    const char* limit = pem_text + pem_len;
    const char* b64_start = skip_ws_crlf(after_head, limit);
    if (!b64_start) return P2D_ERR_BAD_PEM_FORMAT;

    /* 3) Find footer that terminates this certificate. */
    const char* foot = find_strn(b64_start, (size_t)(limit - b64_start), FOOT);
    if (!foot) return P2D_ERR_BAD_PEM_FORMAT;

    /* 4) Before accepting the block, reject OpenSSL-style encrypted PEM.
          This is a simple check; encrypted CERTS are uncommon, but if present,
          we bail out explicitly instead of mis-decoding. */
    {
        const char* enc = find_strn(b64_start, (size_t)(foot - b64_start), "Proc-Type: 4,ENCRYPTED");
        if (enc) return P2D_ERR_ENCRYPTED_UNSUPPORTED;
    }

    /* 5) Trim trailing whitespace right before the footer. */
    const char* b64_end = foot;
    while (b64_end > b64_start && (b64_end[-1] == ' ' || b64_end[-1] == '\r' || b64_end[-1] == '\n'))
        b64_end--;

    if (b64_end <= b64_start) return P2D_ERR_BAD_PEM_FORMAT;

    /* 6) Compute decoded length safely and allocate exact-sized buffer. */
    size_t body_len = (size_t)(b64_end - b64_start);
    size_t need = 0;
    if (!b64_decoded_len(b64_start, body_len, &need)) return P2D_ERR_BAD_BASE64;

    if (need == 0) { /* Empty body (weird, but handle gracefully) */
        *der_out = NULL;
        *der_len = 0;
        return P2D_OK;
    }

    if (need > (size_t)(SIZE_MAX - 16)) return P2D_ERR_TOO_LARGE; /* paranoia guard */

    uint8_t* out = (uint8_t*) malloc(need);
    if (!out) return P2D_ERR_ALLOC;

    /* 7) Decode Base64 into our buffer. */
    size_t got = 0;
    if (!b64_decode(b64_start, body_len, out, need, &got) || got != need) {
        free(out);
        return P2D_ERR_BAD_BASE64;
    }

    /* 8) Return to caller. Caller owns the buffer. */
    *der_out = out;
    *der_len = got;
    return P2D_OK;
}
