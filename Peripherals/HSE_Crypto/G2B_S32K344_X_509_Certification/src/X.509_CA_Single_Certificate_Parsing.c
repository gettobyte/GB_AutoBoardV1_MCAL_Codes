/*
 * X.509_CA_Single_Certificate_Parsing.c
 *
 *  Created on: 26-Oct-2025
 *      Author: RohanS002 Gettobyte
 */

#include "S32K344.h"                      // Device header for S32K344
#include "hse_host.h"                     // HSE host API (S32K3 HSE interface)
#include "hse_demo_app_services.h"        // HSE demo helpers (WaitForHSEFWInitToFinish, etc.)
#include "x.509_Certificate_Handling.h"   // Your PEM->DER helper (keep it)
#include "mini_x509.h"                    // Lightweight X.509/ASN.1 parser & locators
#include <stdio.h>                        // Optional printf (not used explicitly below)
#include <stdlib.h>                       // free()

/*==================================================================================================
 *                                       LOCAL MACROS
 *  (none needed here)
 ==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *  (none needed here)
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
 *  (none)
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 *  (none)
 ==================================================================================================*/

/*==================================================================================================
 *                                     FUNCTION PROTOTYPES
 *  (none beyond main())
 ==================================================================================================*/

int main(void)
{
    /* --- HSE BOOT/GATE --- */
    WaitForHSEFWInitToFinish();

    /* --- DEMO INPUT: Subject/leaf certificate in PEM form ---
     * For the demo we hard-code a PEM here; in your final flow you’ll:
     *  - receive a peer certificate over CAN/Ethernet/TLS handshake, or
     *  - read it from flash/NVM for your own node.
     * The PEM block must be unencrypted and include the exact header/footer lines.
     */
    static const char *pem =
        "-----BEGIN CERTIFICATE-----\r\n"
        "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\r\n"
        "-----END CERTIFICATE-----\r\n";

    /* --- 1) Convert PEM -> DER ---
     * pem_cert_to_der:
     *  - Strips the header/footer lines.
     *  - Base64-decodes the body.
     *  - Allocates a new buffer [der] that the caller must free().
     *  - Produces DER: exact bytes of the ASN.1 Certificate structure.
     *
     * Lifetime: Keep [der] alive as long as you need to reference tbs/sig/SPKI ranges,
     * because the locators return pointers into this buffer (zero-copy).
     */
    uint8_t *der = NULL;
    size_t der_len = 0;
    pem_cert_to_der(pem, &der, &der_len);      // Assumes success; add return check if desired

    /* --- 2) Parse DER to extract human-readable fields (already implemented) ---
     * simple_x509_parse_der:
     *  - Walks the TBSCertificate fields (version, serial, issuer, validity, subject, SPKI, etc.).
     *  - Decodes algorithm OIDs to friendly names when possible (RSA/ECDSA + SHA2 variants).
     *  - Populates SimpleCert for logs/UI/debug (non-critical for HSE input, but useful).
     * This is *not* used by the verifier directly; it’s for visibility and basic checks.
     */
    SimpleCert c;
    int rc = simple_x509_parse_der(der, der_len, &c);
    if (rc) {
        /* If this fails, the certificate is malformed or unsupported. */
        printf("parse failed: %d\n", rc);
        return 1;
    }

    /* --- 3) Locate core verification materials (zero-copy slices into [der]) ---
     * These three calls are lightweight re-walkers that do *no* heap alloc:
     *   - simple_x509_locate_core: gets TBS (hash input), outer signatureAlgorithm OID,
     *     and signatureValue bytes.
     *   - simple_x509_locate_spki_bits: gets the raw BIT STRING content of SPKI
     *     (subject public key). For RSA, this is a DER RSAPublicKey; for EC P-256,
     *     this is 65 bytes: 0x04 || X(32) || Y(32).
     *   - simple_x509_locate_names: captures issuer/subject DER slices (optional).
     *
     * IMPORTANT:
     *   The signatureValue returned here is the raw BIT STRING contents (the helper removes the
     *   1-byte "unused bits" header), which is exactly what mbedTLS/HSE will expect as input.
     *   Keep [der] alive until you are done with these pointers.
     */

    /* Core materials */
    const uint8_t *tbs       = NULL;  size_t tbs_len       = 0;  // Hash input
    const uint8_t *sig_oid   = NULL;  size_t sig_oid_len   = 0;  // OID for (PK algo + hash)
    const uint8_t *sig       = NULL;  size_t sig_len       = 0;  // Signature bytes

    if (simple_x509_locate_core(der, der_len, &tbs, &tbs_len,
                                &sig_oid, &sig_oid_len,
                                &sig, &sig_len) == SX_OK)
    {
        /* At this point you have:
         *   tbs[0..tbs_len)  -> feed to hash function implied by sig_oid (e.g., SHA-256).
         *   sig[0..sig_len)  -> signature to verify with issuer/CA public key.
         *   sig_oid          -> map to (RSA/ECDSA, SHA-2 variant). For Step-3 you can re-use the
         *                        same OID->name table you already have in mini_x509 to select hash.
         *
         * Typical lengths:
         *   - RSA-2048 signature: exactly 256 bytes (fixed length).
         *   - ECDSA P-256 signature: DER SEQUENCE of two INTEGERs (r,s), ~70-72 bytes, variable.
         */
    } else {
        /* If this fails, the top-level Certificate ASN.1 layout is off (invalid DER). */
    }

    /* SubjectPublicKeyInfo raw BIT STRING (public key bytes exactly as encoded in cert) */
    const uint8_t *spki_bits = NULL;  size_t spki_len = 0;
    if (simple_x509_locate_spki_bits(der, der_len, &spki_bits, &spki_len) == SX_OK)
    {
        /* For RSA:
         *   spki_bits points to DER RSAPublicKey ::= SEQUENCE { n INTEGER, e INTEGER }.
         *   Feed to an RSAPublicKey loader (mbedTLS or your own) to build a key context,
         *   or pass modulus/exponent to HSE key import depending on API.
         *
         * For EC P-256:
         *   spki_bits is 65 bytes: 0x04 || X(32) || Y(32) (uncompressed point).
         *   The curve (e.g., secp256r1) is not in spki_bits; it’s in the SPKI AlgorithmIdentifier.
         */
    } else {
        /* If this fails but parse succeeded, the SPKI section is malformed or unsupported. */
    }

    /* Optional raw issuer/subject names (DER slices of Name SEQUENCE) */
    const uint8_t *issuer_raw  = NULL; size_t issuer_len  = 0;
    const uint8_t *subject_raw = NULL; size_t subject_len = 0;
    if (simple_x509_locate_names(der, der_len, &issuer_raw, &issuer_len,
                                 &subject_raw, &subject_len) == SX_OK)
    {
        /* These raw Name blobs can be compared bytewise to match issuer->subject during
         * chain building, or re-encoded as needed. Not needed for signature verification itself,
         * but useful for future “who signed whom” checks.
         */
    } else {
        /* Name capture failure is rare if parse succeeded; indicates unusual encoding. */
    }

    bool self_signed = (issuer_len == subject_len) &&
                       (0 == memcmp(issuer_raw, subject_raw, issuer_len));
    /* If self_signed == true, you may verify with SPKI from the same cert.
       Otherwise, you MUST verify with the issuer/CA public key. */

    /* --- Lifetime note ---
     * Keep [der] alive until all verification operations that use tbs/sig/spki_bits are done,
     * because these pointers reference slices of [der]. After verification, it’s safe to free.
     */
    free(der);

    /* --- 4) (Next steps) Pass to HSE verify (or mbedTLS) ---
     *
     * With Step-1 complete, you now have all inputs required by a verifier:
     *   - Hash input  : tbs / tbs_len
     *   - Signature   : sig / sig_len
     *   - Algorithm   : sig_oid / sig_oid_len (map to hash+scheme)
     *   - Public key  : spki_bits / spki_len (either subject key for self-signed checks,
     *                  or CA/public key for cross-verification)
     *
     * HSE flow sketch (to implement in Step-3/4):
     *   1) Map sig_oid -> (hash: SHA-256/384/512, scheme: RSA/ECDSA).
     *   2) If you’ll verify with a *CA public key*, ensure that key exists in an HSE key slot:
     *        - Either import the CA public key into an HSE slot (once at setup),
     *          or maintain it as an mbedTLS software key for the demo.
     *   3) Compute hash of [tbs] with the mapped hash (if HSE verify API expects raw message,
     *      it may compute hash internally; otherwise compute hash and pass the digest).
     *   4) Issue HSE verify (RSA-PKCS#1 v1.5 / PSS or ECDSA) with:
     *        - key slot: CA public key (for peer certificate verification)
     *        - signature: [sig, sig_len]
     *        - message/digest: [tbs]/hash
     *   5) Validate certificate time window (notBefore/notAfter from SimpleCert),
     *      and any policy checks you want (Key Usage/Extended KU, etc.).
     *
     * Self-verify Note:
     *   Verifying a leaf certificate with its *own* public key proves integrity but *not trust*,
     *   unless the cert is truly self-signed (issuer==subject, and signature checks out).
     *   For your 2-board demo, the usual flow is: each node has a cert signed by the same CA.
     *   Each node verifies the peer’s cert using the CA public key (or CA cert).
     */

    /* Demo end: stay alive (if you want to attach a debugger/RTT, etc.) */
    for (;;) {
        /* Idle loop; in a real app you would proceed to Step-2/3/4 from here. */
    }

    /* Unreachable */
    /* return 0; */
}
