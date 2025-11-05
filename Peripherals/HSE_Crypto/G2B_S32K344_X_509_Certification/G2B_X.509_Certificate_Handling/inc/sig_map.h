/*
 * sig_map.h
 *
 *  Created on: 31-Oct-2025
 *      Author: singh
 */

#ifndef INC_SIG_MAP_H_
#define INC_SIG_MAP_H_

#include <stdint.h>
#include <stddef.h>
#include "hse_common_types.h"

/* What scheme was used to sign the cert? */
typedef enum {
    SIG_SCHEME_UNKNOWN = 0,
    SIG_SCHEME_RSA_PKCS1_V15,
    SIG_SCHEME_RSA_PSS,      /* needs params parsing – we mark as PSS but leave hash=UNKNOWN */
    SIG_SCHEME_ECDSA,
} sig_scheme_t;

/* Which hash was used with the scheme? */
typedef enum {
    HASH_UNKNOWN = 0,
    HASH_SHA256,
    HASH_SHA384,
    HASH_SHA512,
} hash_id_t;

typedef struct {
    sig_scheme_t scheme;
    hash_id_t    hash;
} sig_params_t;

/* Map the raw OID bytes (from simple_x509_locate_core) to {scheme, hash}. */
sig_params_t map_sig_oid(const uint8_t *oid, size_t oid_len);

/* Optional helpers for logs / assertions */
const char* sig_scheme_str(sig_scheme_t s);
const char* hash_str(hash_id_t h);

/* (Optional) tiny helpers to turn hash_id_t into your HSE enums */
static inline uint8_t to_hse_hash(hash_id_t h) {
    switch (h) {
        case HASH_SHA256: return (uint8_t)HSE_HASH_ALGO_SHA2_256;
        case HASH_SHA384: return (uint8_t)HSE_HASH_ALGO_SHA2_384;
        case HASH_SHA512: return (uint8_t)HSE_HASH_ALGO_SHA2_512;
        default:          return (uint8_t)HSE_HASH_ALGO_NULL;
    }
}


#endif /* INC_SIG_MAP_H_ */
