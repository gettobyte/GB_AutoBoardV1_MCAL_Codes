/*
 * x.509_Certificate_Handling.h
 *
 *  Created on: 26-Oct-2025
 *      Author: RohanS002 Gettobyte
 */

#ifndef INC_X_509_CERTIFICATE_HANDLING_H_
#define INC_X_509_CERTIFICATE_HANDLING_H_

/*
 * Simple PEM-to-DER decoder for X.509 certificates.
 *
 * What this does:
 * - Accepts a NUL-terminated PEM text that includes:
 *     -----BEGIN CERTIFICATE-----\r?\n
 *     <base64 body with optional CR/LF/spaces>
 *     -----END CERTIFICATE-----\r?\n
 * - Finds the first PEM CERTIFICATE block, strips header/footer/whitespace,
 *   rejects encrypted PEMs, Base64-decodes the body, and returns raw DER bytes.
 *
 * What this does NOT do (by design, to keep it tiny and dependency-free):
 * - Encrypted PEM (OpenSSL Proc-Type/DEK-Info) is NOT supported.
 * - Certificate chain iteration is not built-in (one block per call).
 * - No ASN.1 or X.509 parsing—this file ONLY converts PEM → DER.
 *
 * Typical usage:
 *   uint8_t *der = NULL; size_t der_len = 0;
 *   int rc = pem_cert_to_der(pem_text, &der, &der_len);
 *   if (rc == P2D_OK) {
 *       // der[0..der_len-1] is the certificate in DER
 *       // pass to your X.509 parser or hardware security engine (HSE), then:
 *       free(der);
 *   }
 */

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return codes */
#define P2D_OK                         0
#define P2D_ERR_NULL                  -1
#define P2D_ERR_NO_CERT               -2
#define P2D_ERR_BAD_PEM_FORMAT        -3
#define P2D_ERR_ENCRYPTED_UNSUPPORTED -4
#define P2D_ERR_BAD_BASE64            -5
#define P2D_ERR_ALLOC                 -6
#define P2D_ERR_TOO_LARGE             -7

/*
 * Decode the FIRST PEM certificate found in `pem_text` into DER.
 *
 * Parameters
 *   pem_text : NUL-terminated buffer with at least one CERTIFICATE block.
 *   der_out  : (out) On success, *der_out points to malloc'd DER bytes.
 *   der_len  : (out) On success, *der_len is the DER length in bytes.
 *
 * Returns
 *   P2D_OK on success, or a negative error code.
 *
 * Ownership
 *   Caller must free(*der_out) on success.
 */
int pem_cert_to_der(const char *pem_text, uint8_t **der_out, size_t *der_len);

#ifdef __cplusplus
}
#endif

#endif /* INC_X_509_CERTIFICATE_HANDLING_H_ */
