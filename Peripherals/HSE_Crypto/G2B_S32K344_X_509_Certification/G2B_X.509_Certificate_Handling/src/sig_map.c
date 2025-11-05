/*
 * sig_map.c
 *
 *  Created on: 31-Oct-2025
 *      Author: singh
 */

#include "sig_map.h"
#include <string.h>

/* Raw OID byte sequences (DER OID value, not the whole AlgId) */

/* RSA PKCS#1 v1.5 + SHA-2 */
static const uint8_t OID_RSA_SHA256[] = { 0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0B }; /* 1.2.840.113549.1.1.11 */
static const uint8_t OID_RSA_SHA384[] = { 0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0C }; /* 1.2.840.113549.1.1.12 */
static const uint8_t OID_RSA_SHA512[] = { 0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0D }; /* 1.2.840.113549.1.1.13 */

/* RSA-PSS (hash is in params; we can only mark scheme here) */
static const uint8_t OID_RSA_PSS[]    = { 0x2A,0x86,0x48,0x86,0xF7,0x0D,0x01,0x01,0x0A }; /* 1.2.840.113549.1.1.10 */

/* ECDSA + SHA-2 */
static const uint8_t OID_ECDSA_SHA256[] = { 0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x02 };     /* 1.2.840.10045.4.3.2 */
static const uint8_t OID_ECDSA_SHA384[] = { 0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x03 };     /* 1.2.840.10045.4.3.3 */
static const uint8_t OID_ECDSA_SHA512[] = { 0x2A,0x86,0x48,0xCE,0x3D,0x04,0x03,0x04 };     /* 1.2.840.10045.4.3.4 */

static int oid_eq(const uint8_t *a, size_t alen, const uint8_t *b, size_t blen) {
    return (alen == blen) && (0 == memcmp(a, b, alen));
}

sig_params_t map_sig_oid(const uint8_t *oid, size_t oid_len)
{
    sig_params_t r = { SIG_SCHEME_UNKNOWN, HASH_UNKNOWN };
    if (!oid || oid_len == 0) return r;

    /* RSA PKCS#1 v1.5 + SHA2 */
    if (oid_eq(oid, oid_len, OID_RSA_SHA256, sizeof(OID_RSA_SHA256))) { r.scheme = SIG_SCHEME_RSA_PKCS1_V15; r.hash = HASH_SHA256; return r; }
    if (oid_eq(oid, oid_len, OID_RSA_SHA384, sizeof(OID_RSA_SHA384))) { r.scheme = SIG_SCHEME_RSA_PKCS1_V15; r.hash = HASH_SHA384; return r; }
    if (oid_eq(oid, oid_len, OID_RSA_SHA512, sizeof(OID_RSA_SHA512))) { r.scheme = SIG_SCHEME_RSA_PKCS1_V15; r.hash = HASH_SHA512; return r; }

    /* RSA-PSS (needs AlgorithmIdentifier parameters to know which hash; not parsed here) */
    if (oid_eq(oid, oid_len, OID_RSA_PSS, sizeof(OID_RSA_PSS))) {
        r.scheme = SIG_SCHEME_RSA_PSS; r.hash = HASH_UNKNOWN; return r;
    }

    /* ECDSA + SHA2 */
    if (oid_eq(oid, oid_len, OID_ECDSA_SHA256, sizeof(OID_ECDSA_SHA256))) { r.scheme = SIG_SCHEME_ECDSA; r.hash = HASH_SHA256; return r; }
    if (oid_eq(oid, oid_len, OID_ECDSA_SHA384, sizeof(OID_ECDSA_SHA384))) { r.scheme = SIG_SCHEME_ECDSA; r.hash = HASH_SHA384; return r; }
    if (oid_eq(oid, oid_len, OID_ECDSA_SHA512, sizeof(OID_ECDSA_SHA512))) { r.scheme = SIG_SCHEME_ECDSA; r.hash = HASH_SHA512; return r; }

    return r; /* unknown */
}

const char* sig_scheme_str(sig_scheme_t s) {
    switch (s) {
        case SIG_SCHEME_RSA_PKCS1_V15: return "RSA-PKCS1v1.5";
        case SIG_SCHEME_RSA_PSS:       return "RSA-PSS";
        case SIG_SCHEME_ECDSA:         return "ECDSA";
        default:                       return "UNKNOWN";
    }
}
const char* hash_str(hash_id_t h) {
    switch (h) {
        case HASH_SHA256: return "SHA-256";
        case HASH_SHA384: return "SHA-384";
        case HASH_SHA512: return "SHA-512";
        default:          return "UNKNOWN";
    }
}

