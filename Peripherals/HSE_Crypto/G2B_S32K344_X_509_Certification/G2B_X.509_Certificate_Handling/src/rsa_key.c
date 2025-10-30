/*
 * rsa_key.c
 *
 *  Created on: 30-Oct-2025
 *      Author: singh
 */

#include "rsa_key.h"
#include <string.h>
#include <stdlib.h>

/* Secure zeroize */
static void rz(void *p, size_t n) {
    volatile uint8_t *v = (volatile uint8_t *)p;
    while (n--) *v++ = 0;
}

/* Minimal ASN.1 helpers for INTEGER and SEQUENCE (DER only) */
typedef struct { const uint8_t *p, *end; } asn1;

static int asn1_get_len(asn1 *a, size_t *L) {
    if (a->p >= a->end) return -1;
    uint8_t c = *a->p++;
    if ((c & 0x80) == 0) { *L = c; return (a->end - a->p) >= (ptrdiff_t)*L ? 0 : -1; }
    size_t n = c & 0x7F; if (n == 0 || n > 4 || (a->end - a->p) < (ptrdiff_t)n) return -1;
    size_t v = 0; for (size_t i=0;i<n;i++) v = (v<<8) | *a->p++;
    *L = v; return (a->end - a->p) >= (ptrdiff_t)*L ? 0 : -1;
}
static int asn1_enter_seq(asn1 *a, asn1 *out) {
    if (a->p >= a->end || *a->p++ != 0x30) return -1;
    size_t L; if (asn1_get_len(a, &L)) return -1;
    if ((size_t)(a->end - a->p) < L) return -1;
    out->p = a->p; out->end = a->p + L; a->p += L; return 0;
}
static int asn1_get_integer(asn1 *a, const uint8_t **val, size_t *val_len) {
    if (a->p >= a->end || *a->p++ != 0x02) return -1;
    size_t L; if (asn1_get_len(a, &L)) return -1;
    if ((size_t)(a->end - a->p) < L) return -1;
    *val = a->p; *val_len = L; a->p += L; return 0;
}

/* Strip a single leading 0x00 that was added to keep INTEGER positive */
int rsak_strip_leading_zero(const uint8_t **p, size_t *len) {
    if (!p || !*p || !len) return RSAK_BAD_INPUT;
    if (*len > 0 && **p == 0x00) { (*p)++; (*len)--; }
    return RSAK_OK;
}

/* Init / Free */
void rsa_pub_init(rsa_pub_t *k) {
    if (!k) return;
    memset(k, 0, sizeof(*k));
}
void rsa_priv_init(rsa_priv_t *k) {
    if (!k) return;
    memset(k, 0, sizeof(*k));
}
void rsa_pub_free(rsa_pub_t *k) {
    if (!k) return;
    if (k->N) { rz(k->N, k->N_len); free(k->N); }
    if (k->E) { rz(k->E, k->E_len); free(k->E); }
    memset(k, 0, sizeof(*k));
}
void rsa_priv_free(rsa_priv_t *k) {
    if (!k) return;
    uint8_t **bufs[] = { &k->N,&k->E,&k->D,&k->P,&k->Q,&k->DP,&k->DQ,&k->QP };
    size_t   lens[]  = {  k->N_len,k->E_len,k->D_len,k->P_len,k->Q_len,k->DP_len,k->DQ_len,k->QP_len };
    for (size_t i=0;i<sizeof(bufs)/sizeof(bufs[0]);++i) {
        if (*bufs[i]) { rz(*bufs[i], lens[i]); free(*bufs[i]); *bufs[i]=NULL; }
    }
    memset(k, 0, sizeof(*k));
}

/* Derive n_bits from N: find first 1 bit in the first byte */
void rsa_pub_finalize(rsa_pub_t *k) {
    if (!k || !k->N || k->N_len == 0) { k->n_bits = 0; return; }
    uint8_t msb = k->N[0];
    uint8_t leading = (msb ? (uint8_t)__builtin_clz((unsigned)msb) - 24 : 8);
    /* __builtin_clz is UB for 0; handle msb==0 separately (shouldn’t happen after strip). */
    if (msb == 0) {
        /* fallback scan */
        size_t i=0; while (i<k->N_len && k->N[i]==0) i++;
        if (i==k->N_len) { k->n_bits=0; return; }
        msb = k->N[i];
        leading = (uint8_t)__builtin_clz((unsigned)msb) - 24;
        k->n_bits = (uint16_t)((k->N_len - i - 1)*8 + (8 - leading));
    } else {
        k->n_bits = (uint16_t)((k->N_len - 1)*8 + (8 - leading));
    }
}

/* Parse DER RSAPublicKey ::= SEQUENCE { N INTEGER, E INTEGER } */
int rsa_pub_from_der_rsapubkey(const uint8_t *der, size_t der_len, rsa_pub_t *out) {
    if (!der || der_len < 8 || !out) return RSAK_BAD_INPUT;
    rsa_pub_init(out);

    asn1 a = { der, der + der_len }, seq;
    if (asn1_enter_seq(&a, &seq)) return RSAK_DER_ERROR;

    const uint8_t *N; size_t N_len;
    const uint8_t *E; size_t E_len;
    if (asn1_get_integer(&seq, &N, &N_len)) return RSAK_DER_ERROR;
    if (asn1_get_integer(&seq, &E, &E_len)) return RSAK_DER_ERROR;

    /* Remove optional sign-protect 0x00 bytes */
    rsak_strip_leading_zero(&N, &N_len);
    rsak_strip_leading_zero(&E, &E_len);

    /* Copy to heap-owned buffers */
    out->N = (uint8_t*)malloc(N_len); if (!out->N) { rsa_pub_free(out); return RSAK_ALLOC_FAIL; }
    out->E = (uint8_t*)malloc(E_len); if (!out->E) { rsa_pub_free(out); return RSAK_ALLOC_FAIL; }
    memcpy(out->N, N, N_len); out->N_len = N_len;
    memcpy(out->E, E, E_len); out->E_len = E_len;

    rsa_pub_finalize(out);
    return RSAK_OK;
}

/* For RSA certificates, SPKI BIT STRING is the DER RSAPublicKey */
int rsa_pub_from_spki_bits(const uint8_t *spki_bits, size_t spki_len, rsa_pub_t *out) {
    if (!spki_bits || spki_len < 8 || !out) return RSAK_BAD_INPUT;
    /* Quick sanity: RSAPublicKey typically starts with SEQUENCE(0x30) */
    if (spki_bits[0] != 0x30) return RSAK_DER_ERROR;
    return rsa_pub_from_der_rsapubkey(spki_bits, spki_len, out);
}

/* ---- HSE bridge (dummy signature; implement with your HSE host libs) --- */
int hse_import_rsa_pubkey(const rsa_pub_t *k, uint32_t key_handle, bool usage_verify_only) {
    (void)usage_verify_only;
    if (!k || !k->N || !k->E || k->N_len == 0 || k->E_len == 0) return RSAK_BAD_INPUT;

    /* Pseudocode:
       - Fill hseImportKeySrv_t with RSA public components:
         . keyHandle = key_handle
         . keyInfo.algorithm = HSE_KEY_ALGO_RSA
         . keyInfo.keyBitLen = k->n_bits
         . keyInfo.keyFlags  = HSE_KF_USAGE_VERIFY (if usage_verify_only)
         . keyInfo.keyType   = HSE_KEY_TYPE_PUB
         . keyMaterial = { modulus pointer/len, exponent pointer/len }
       - Submit service descriptor and wait for status.
       - On success, you may mark the slot as occupied.
    */

    /* Return RSAK_OK here so you can link in your real implementation later. */
    (void)key_handle;
    return RSAK_OK;
}

