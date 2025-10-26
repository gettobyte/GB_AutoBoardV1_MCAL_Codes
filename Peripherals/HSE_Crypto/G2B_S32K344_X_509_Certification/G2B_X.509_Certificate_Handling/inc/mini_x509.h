/*
 * mini_x509.h
 *
 *  Created on: 26-Oct-2025
 *      Author: Rohan
 */

#ifndef INC_MINI_X509_H_
#define INC_MINI_X509_H_

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return codes */
#define SX_OK                   0
#define SX_BAD_INPUT           -1
#define SX_INVALID_FORMAT      -2
#define SX_UNSUPPORTED         -3
#define SX_OVERFLOW            -4

/* Tunable sizes for friendly strings */
#define SX_MAX_TEXT        256
#define SX_MAX_SERIAL       96
#define SX_MAX_ALG          40
#define SX_MAX_HASH         16
#define SX_MAX_CURVE        24
#define SX_MAX_HEX64       132
#define SX_MAX_URI          256
#define SX_MAX_LIST_ITEMS   16
#define SX_TIME_STR         24  /* "YYYY-MM-DD HH:MM:SS UTC" */

/* Very simple, watch-window-friendly view */
typedef struct {
    /* Core / General */
    int   version;                           /* 1..3 */
    char  serial_hex[SX_MAX_SERIAL];         /* hex string */
    char  sig_alg[SX_MAX_ALG];               /* "sha256WithRSA" / "ecdsa-with-SHA256" / "sig(oid)" */
    char  sig_hash[SX_MAX_HASH];             /* "sha256"/"sha384"/... when known */

    /* Names */
    char  issuer[SX_MAX_TEXT];               /* "C=US,O=...,CN=..." */
    char  subject[SX_MAX_TEXT];

    /* Validity (UTC) */
    char  not_before[SX_TIME_STR];           /* "YYYY-MM-DD HH:MM:SS UTC" */
    char  not_after [SX_TIME_STR];

    /* Public key */
    char  pubkey_type[8];                    /* "RSA" or "EC" */
    int   rsa_mod_bits;                      /* if RSA */
    int   rsa_exp;                           /* common 65537 fits; else 0 */
    char  curve[SX_MAX_CURVE];               /* if EC */
    char  ec_x_hex[SX_MAX_HEX64];            /* if EC */
    char  ec_y_hex[SX_MAX_HEX64];

    /* Basic Constraints & KU */
    int   is_ca;                             /* 0/1 */
    int   path_len;                          /* -1 if absent */
    unsigned key_usage;                      /* bitmap (low 16 bits) */

    /* Enhanced Key Usage: friendly names (subset) */
    int   eku_count;
    char  eku[SX_MAX_LIST_ITEMS][SX_MAX_ALG];/* "ServerAuth", "ClientAuth", ... */

    /* SAN (DNS/IP) */
    int   san_count;
    char  san[SX_MAX_LIST_ITEMS][SX_MAX_URI];

    /* IDs */
    char  skid_hex[SX_MAX_HEX64];            /* SubjectKeyIdentifier */
    char  akid_keyid_hex[SX_MAX_HEX64];      /* AuthorityKeyIdentifier.keyIdentifier */

    /* AIA */
    int   aia_ocsp_count;
    char  aia_ocsp[SX_MAX_LIST_ITEMS][SX_MAX_URI];
    int   aia_caissuers_count;
    char  aia_caissuers[SX_MAX_LIST_ITEMS][SX_MAX_URI];

    /* CRL Distribution Points */
    int   crl_dp_count;
    char  crl_dp[SX_MAX_LIST_ITEMS][SX_MAX_URI];

    /* Certificate Policies (OIDs as strings) */
    int   policy_count;
    char  policy_oid[SX_MAX_LIST_ITEMS][SX_MAX_ALG];

    /* (Optional) Thumbprints over the *raw DER* */
    char  sha1_thumb[41];                    /* 40 hex + NUL */
    char  sha256_thumb[65];                  /* 64 hex + NUL */
} SimpleCert;

/* Parse one DER-encoded certificate into SimpleCert (all strings are NUL-terminated). */
int simple_x509_parse_der(const uint8_t* der, size_t der_len, SimpleCert* out);

/* Enable built-in tiny SHA-1/SHA-256 (define SX_ENABLE_BUILTIN_HASH before including .c) */
/* Or, call this after parse with your own hashes to fill the thumbprints. */
void simple_x509_set_thumbprints(SimpleCert* out,
                                 const uint8_t* sha1,   size_t sha1_len,
                                 const uint8_t* sha256, size_t sha256_len);

#ifdef __cplusplus
}
#endif

#endif /* INC_MINI_X509_H_ */
