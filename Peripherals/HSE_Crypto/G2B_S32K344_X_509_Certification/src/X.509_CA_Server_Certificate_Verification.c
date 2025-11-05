/*
 * X.509_CA_Server_Certificate_Verification.c
 * Created on: 29-Oct-2025
 * Author: RohanS002 Gettobyte
 *
 * Purpose:
 *   Validate a CA (self-signed) X.509 certificate on S32K344 using HSE:
 *     - PEM → DER
 *     - Parse fields & locate core slices (TBS TLV, signature, SPKI)
 *     - Extract RSA public key (N,E) from SPKI
 *     - (Optionally) hash TBS for watch
 *     - Hardware verify (RSA PKCS#1 v1.5 + SHA-256) via HSE
 *
 * Debug/Presentation:
 *   A dedicated "WATCH EXPORTS" block exposes stable variables/arrays so the
 *   debugger watch looks like a readable mini-GUI of the certificate.
 */

#include "S32K344.h"
#include "hse_host.h"
#include "hse_demo_app_services.h"
#include "x.509_Certificate_Handling.h"
#include "mini_x509.h"
#include "rsa_key.h"
#include "sig_map.h"
#include "hse_host_hash.h"
#include "hse_srv_responses.h"
#include "hse_host_format_key_catalogs.h"
#include "hse_keys_allocator.h"
#include "hse_host_import_key.h"
#include "hse_host_sign.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* =============================================================================
 *                                 CONSTANTS
 * =============================================================================
 */
static hseTxOptions_t g_txOptions = { HSE_TX_SYNCHRONOUS, NULL, NULL };

/* NVM key catalog (RSA pair group) */
static const hseKeyGroupCfgEntry_t g_nvmKeyCatalog_rsa[] = { { HSE_MU0_MASK,
HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_RSA_PAIR, 10, HSE_KEY2048_BITS }, { 0, 0, 0, 0,
		0 } };

/* RAM key catalog (RSA public group) */
static const hseKeyGroupCfgEntry_t g_ramKeyCatalog_rsa[] = { { HSE_MU0_MASK,
HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_RSA_PUB, 10, HSE_KEY2048_BITS },
		{ 0, 0, 0, 0, 0 } };

/* Example CA certificate (PEM) */
static const char *g_ca_pem = "-----BEGIN CERTIFICATE-----\r\n"
		"MIIDhDCCAmygAwIBAgIINYKWbrYzIuEwDQYJKoZIhvcNAQELBQAwSDELMAkGA1UE\r\n"
		"BhMCSU4xJzAlBgNVBAoTHkdldHRvYnl0ZSBUZWNobm9sb2dpZXMgUHZ0IEx0ZDEQ\r\n"
		"MA4GA1UEAwwHUm9vdF9DQTAeFw0yNTEwMjgxMTQ0MDBaFw0zNTEwMjgxMTQ0MDBa\r\n"
		"MEgxCzAJBgNVBAYTAklOMScwJQYDVQQKEx5HZXR0b2J5dGUgVGVjaG5vbG9naWVz\r\n"
		"IFB2dCBMdGQxEDAOBgNVBAMMB1Jvb3RfQ0EwggEiMA0GCSqGSIb3DQEBAQUAA4IB\r\n"
		"DwAwggEKAoIBAQC5+qqEb+wIDQTG7mgAAgXdH9eM1PjuR34e4qDZDTW7aRukWt0I\r\n"
		"Whwef6NbfXV51N/CI+4+446sND4jW8Y4tK8h7i+QJBaTx3sdDyBO3JNthpp/uUtt\r\n"
		"+2EUGJP8tKNiP1GhhAjjCMmHwrY3kqyAzXKiCdRFGnWOdQvae6QfgTogDGoXwfEj\r\n"
		"IGRfOAXZYOLo/+PTm7AZvF+eWSGnXV3mnvP0FimE/NhBdJwL3T8AoxaMW+jNWRTf\r\n"
		"XV5NAZili62U7Va/BdGSw3Vrbf70O3S7nbnQWmHJTKrZT8CjUft2fVXpsNWJ+lAp\r\n"
		"cWqRrOtY5Ux5sO2ke5l52vXVrWckwSHESCCjAgMBAAGjcjBwMA8GA1UdEwEB/wQF\r\n"
		"MAMBAf8wHQYDVR0OBBYEFOaB3KdlqOw1UgifcfwjaAQmyoHjMAsGA1UdDwQEAwIB\r\n"
		"BjARBglghkgBhvhCAQEEBAMCAAcwHgYJYIZIAYb4QgENBBEWD3hjYSBjZXJ0aWZp\r\n"
		"Y2F0ZTANBgkqhkiG9w0BAQsFAAOCAQEAtkNO6oP39gHMzH6Zz53dOs6zqJbrZFab\r\n"
		"w1ekLN30hwAbC9v32zp9Elq1zFnZRQAeILOYTpeR2ejD2PgpZATeYhH9w93OgDgx\r\n"
		"/CWtDQAcYN/kOvIzAaFGBY3+QoRsOTzggLNNehhO4ZhevBjRS6QWsJDY1RaAp8ss\r\n"
		"9QWJnuYtkfUAtfqDD3jGC3VsE9h5dBQn4JG0REeC7go6S7D+ofzzgBDbK/gwdFcr\r\n"
		"YnS4e9Mse0D1RQjFEaEKibB0hX7L3uEAzVIDCS2lD/0jzwCLxQ1xhFooVzv5Tb4k\r\n"
		"nRr+v8ht/baCu3vtZEeGxM8/IeP3ttjavdNnb/IiCS2nVgj/YfzNDw==\r\n"
		"-----END CERTIFICATE-----\r\n";

/* =============================================================================
 *                              WATCH EXPORTS (GUI-like)
 *   Add these in your Watch window for a clean, readable view.
 * =============================================================================
 */

/* Status / handles */
volatile hseSrvResponse_t watch_hse_status = HSE_SRV_RSP_GENERAL_ERROR;
volatile hseKeyHandle_t watch_key_pub_handle = 0U;
volatile uint16_t watch_rsa_bits = 0U;

/* DER objects & lengths */
volatile const uint8_t *watch_der_ptr = NULL;
volatile size_t watch_der_len = 0U;

volatile const uint8_t *watch_tbs_ptr = NULL; /* MUST start at 0x30 */
volatile size_t watch_tbs_len = 0U; /* MUST be TLV length (e.g., 624) */

volatile const uint8_t *watch_sig_ptr = NULL;
volatile size_t watch_sig_len = 0U;

volatile const uint8_t *watch_sig_oid_ptr = NULL;
volatile size_t watch_sig_oid_len = 0U;

volatile const uint8_t *watch_spki_bits_ptr = NULL;
volatile size_t watch_spki_bits_len = 0U;

volatile const uint8_t *watch_name_issuer_ptr = NULL;
volatile size_t watch_name_issuer_len = 0U;
volatile const uint8_t *watch_name_subject_ptr = NULL;
volatile size_t watch_name_subject_len = 0U;

/* Parsed RSA public key (copied as arrays for stable watch) */
static uint8_t watch_rsa_N[256]; /* RSA-2048 modulus */
volatile size_t watch_rsa_N_len = 0U;
static uint8_t watch_rsa_E[8]; /* typically 0x01 00 01 */
volatile size_t watch_rsa_E_len = 0U;

/* Signature & hash copies for watch */
static uint8_t watch_sig[256]; /* copy of signatureValue */
volatile size_t watch_sig_copy_len = 0U;
static uint8_t watch_tbs_sha256[32]; /* SHA-256(TBS TLV) */
volatile uint32_t watch_tbs_sha256_len = 0U;

/* Parsed certificate header */
volatile uint16_t watch_version = 0U; /* from SimpleCert (if populated) */

/* =============================================================================
 *                              LOCAL HELPERS
 * =============================================================================
 */

/* Copy with clamp for watch arrays */
static inline size_t clamp_copy(uint8_t *dst, size_t cap, const uint8_t *src,
		size_t len) {
	if (!dst || !src || cap == 0)
		return 0;
	size_t n = (len < cap) ? len : cap;
	memcpy(dst, src, n);
	return n;
}

/* =============================================================================
 *                                  MAIN
 * =============================================================================
 */
int main(void) {
	/* ───── 0) HSE init & catalogs ─────────────────────────────────────────── */
	WaitForHSEFWInitToFinish();

	/* Key handles (we use RAM for public key) */
	hseKeyHandle_t keyPairNvm = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_NVM, 0, 0);
	hseKeyHandle_t keyPubRam = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_RAM, 0, 0);
	watch_key_pub_handle = keyPubRam;

	/* Format catalogs + init allocator */
	watch_hse_status = FormatKeyCatalogs(g_nvmKeyCatalog_rsa,
			g_ramKeyCatalog_rsa);
	watch_hse_status = HKF_Init(g_nvmKeyCatalog_rsa, g_ramKeyCatalog_rsa);

	/* ───── 1) PEM → DER ───────────────────────────────────────────────────── */
	uint8_t *der = NULL;
	size_t der_len = 0;
	pem_cert_to_der(g_ca_pem, &der, &der_len);
	watch_der_ptr = der;
	watch_der_len = der_len;

	/* ───── 2) Parse (optional structure for info) ─────────────────────────── */
	SimpleCert cert = { 0 };
	(void) simple_x509_parse_der(der, der_len, &cert);
	/* If SimpleCert carries version: expose it (else leave 0) */
	/* watch_version = cert.version; // enable if your struct has it */

	/* ───── 3) Locate core TLVs & fields ───────────────────────────────────── */
	const uint8_t *tbs = NULL, *sig_oid = NULL, *sig = NULL;
	size_t tbs_len = 0, sig_oid_len = 0, sig_len = 0;

	if (simple_x509_locate_core(der, der_len, &tbs, &tbs_len, &sig_oid,
			&sig_oid_len, &sig, &sig_len) != SX_OK) {
		/* stay in idle loop for inspection */
		for (;;)
			;
	}
	watch_tbs_ptr = tbs;
	watch_tbs_len = tbs_len; /* TBS must be full TLV */
	watch_sig_oid_ptr = sig_oid;
	watch_sig_oid_len = sig_oid_len;
	watch_sig_ptr = sig;
	watch_sig_len = sig_len;

	/* Optional: issuer/subject raw Name DER (nice for watch) */
	(void) simple_x509_locate_names(der, der_len, &watch_name_issuer_ptr,
			&watch_name_issuer_len, &watch_name_subject_ptr,
			&watch_name_subject_len);

	/* SPKI BIT STRING (payload -> RSAPublicKey DER) */
	const uint8_t *spki_bits = NULL;
	size_t spki_len = 0;
	if (simple_x509_locate_spki_bits(der, der_len, &spki_bits,
			&spki_len) != SX_OK) {
		for (;;)
			; /* inspect in watch */
	}
	watch_spki_bits_ptr = spki_bits;
	watch_spki_bits_len = spki_len;

	/* ───── 4) Extract RSA public key (SPKI→RSAPublicKey→N,E) ─────────────── */
	rsa_pub_t ca_pub;
	rsa_pub_init(&ca_pub);
	if (rsa_pub_from_spki_bits(spki_bits, spki_len, &ca_pub) != RSAK_OK) {
		for (;;)
			;
	}
	watch_rsa_bits = ca_pub.n_bits; /* expect 2048 */
	watch_rsa_N_len = clamp_copy(watch_rsa_N, sizeof(watch_rsa_N), ca_pub.N,
			ca_pub.N_len);
	watch_rsa_E_len = clamp_copy(watch_rsa_E, sizeof(watch_rsa_E), ca_pub.E,
			ca_pub.E_len);

	/* ───── 5) HASH the TBS for watch ───────────────────────────── */
	/* We still let HSE hash inside verify; this is only to show digest in watch */
	watch_tbs_sha256_len = sizeof(watch_tbs_sha256);
	watch_hse_status = HashReq(
	HSE_ACCESS_MODE_ONE_PASS, 0U, 1U,
	HSE_HASH_ALGO_SHA2_256, 0U, (uint32_t) watch_tbs_len, watch_tbs_ptr,
			&watch_tbs_sha256_len, watch_tbs_sha256, g_txOptions,
			HSE_SGT_OPTION_NONE);

	/* Copy signature for a stable watch buffer */
	watch_sig_copy_len = clamp_copy(watch_sig, sizeof(watch_sig), watch_sig_ptr,
			watch_sig_len);

	/* ───── 6) Import RSA public key (normalized N/E) into HSE ─────────────── */
	watch_hse_status = LoadRsaPublicKey(&keyPubRam, 0U, /* isNvmKey = FALSE → RAM */
	ca_pub.n_bits, /* e.g., 2048 */
	ca_pub.N, (uint16_t) ca_pub.E_len, ca_pub.E);
	watch_key_pub_handle = keyPubRam;

	/* ───── 7) Verify signature in HSE (let HSE hash TBS internally) ───────── */
	uint32_t sig_len_u32 = (uint32_t) watch_sig_len;
	watch_hse_status = RsaPkcs1v15VerSrv(keyPubRam,
	HSE_HASH_ALGO_SHA2_256, (uint32_t) watch_tbs_len, watch_tbs_ptr, FALSE,
	HSE_SGT_OPTION_NONE, &sig_len_u32, watch_sig_ptr);

	/* Free dynamic RSA pub key buffers (N,E) */
	rsa_pub_free(&ca_pub);

	/* ───── 8) Idle loop for live inspection in Watch ─────────────────────── */
	for (;;) { /* open “WATCH EXPORTS” vars in your debugger */
	}

	/* not reached */
	/* return 0; */
}
