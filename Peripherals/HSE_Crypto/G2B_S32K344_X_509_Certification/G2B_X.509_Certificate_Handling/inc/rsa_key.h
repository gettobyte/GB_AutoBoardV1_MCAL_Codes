/*
 * rsa_key.h
 *
 *  Created on: 30-Oct-2025
 *      Author: singh
 */

#ifndef INC_RSA_KEY_H_
#define INC_RSA_KEY_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* Minimal return codes */
enum {
	RSAK_OK = 0, RSAK_BAD_INPUT = -1, RSAK_DER_ERROR = -2, RSAK_ALLOC_FAIL = -3,
};

/* -----------------------------------------------------------------------
 * Lightweight RSA PUBLIC key container (HSE/verify friendly)
 * -----------------------------------------------------------------------
 * All multi-precision integers are big-endian byte arrays.
 * We keep E as bytes to remain general (E is usually 0x010001 but not assumed).
 * Memory ownership: buffers are heap-owned by this struct and freed by rsa_pub_free().
 */
typedef struct {
	uint8_t *N; /* modulus, big-endian */
	size_t N_len; /* modulus length in bytes (e.g., 256 for RSA-2048) */
	uint8_t *E; /* public exponent, big-endian (often 0x01 0x00 0x01) */
	size_t E_len; /* exponent length in bytes (usually 3) */

	/* Convenience: derived bit length */
	uint16_t n_bits;

	/* Optional integration fields (don’t affect parsing/ownership) */
	uint32_t hse_key_handle; /* assigned when imported to HSE; 0 if not imported yet */
	uint32_t flags; /* bit0: in_HSE_RAM, bit1: in_HSE_NVM, etc. */
} rsa_pub_t;

/* -----------------------------------------------------------------------
 * Lightweight RSA PRIVATE key container (for Step-2 provisioning)
 * -----------------------------------------------------------------------
 * Only needed if you plan to import private keys into HSE (for signing, etc.).
 * Any field may be NULL if not provided (e.g., no CRT params); zeroized on free.
 */
typedef struct {
	uint8_t *N;
	size_t N_len;
	uint8_t *E;
	size_t E_len;
	uint8_t *D;
	size_t D_len;
	uint8_t *P;
	size_t P_len;
	uint8_t *Q;
	size_t Q_len;
	uint8_t *DP;
	size_t DP_len; /* D mod (P-1) */
	uint8_t *DQ;
	size_t DQ_len; /* D mod (Q-1) */
	uint8_t *QP;
	size_t QP_len; /* (Q^-1) mod P */
	uint16_t n_bits;
	uint32_t hse_key_handle;
	uint32_t flags;
} rsa_priv_t;

/* ---- Public API ------------------------------------------------------ */

/* Initialize empty containers (sets all to zero/NULL). */
void rsa_pub_init(rsa_pub_t *k);
void rsa_priv_init(rsa_priv_t *k);

/* Free + secure zeroize (where applicable). Safe on NULL fields. */
void rsa_pub_free(rsa_pub_t *k);
void rsa_priv_free(rsa_priv_t *k);

/* Parse DER-encoded RSAPublicKey (SEQUENCE { N INTEGER; E INTEGER })
 * into rsa_pub_t. Copies buffers (caller keeps source alive or not).
 */
int rsa_pub_from_der_rsapubkey(const uint8_t *der, size_t der_len,
		rsa_pub_t *out);

/* Convenience: Parse from SPKI BIT STRING (what mini_x509 gives you):
 * - For RSA, SPKI BIT STRING contains DER RSAPublicKey → call-through to the function above.
 * - Returns RSAK_DER_ERROR if SPKI doesn’t look like RSAPublicKey.
 */
int rsa_pub_from_spki_bits(const uint8_t *spki_bits, size_t spki_len,
		rsa_pub_t *out);

/* Compute derived fields (e.g., n_bits) if not filled yet. */
void rsa_pub_finalize(rsa_pub_t *k);

/* (Optional) Utility: strip leading 0x00 if INTEGER had a sign-protect byte. */
int rsak_strip_leading_zero(const uint8_t **p, size_t *len);

/* ---- HSE bridge (thin wrappers; implement with your HSE stack) -------- */

/* Import an RSA PUBLIC key into an HSE public-key slot.
 * - If want RAM slot for demo, pass a RAM handle; for NVM, an NVM handle.
 * - ‘usage_verify_only’ hints you’ll only verify with it (no sign).
 * Returns RSAK_OK on success (and sets k->hse_key_handle, flags).
 */
int hse_import_rsa_pubkey(const rsa_pub_t *k, uint32_t key_handle,
		bool usage_verify_only);

#endif /* INC_RSA_KEY_H_ */
