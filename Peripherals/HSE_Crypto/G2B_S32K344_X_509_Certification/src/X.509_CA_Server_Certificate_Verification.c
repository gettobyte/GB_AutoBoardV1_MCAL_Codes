/*
 * X.509_CA_Server_Certificate_Verification.c
 *
 *  Created on: 29-Oct-2025
 *      Author: RohanS002 Gettobyte
 */

#include "S32K344.h"                      // Device header for S32K344
#include "hse_host.h"                     // HSE host API (S32K3 HSE interface)
#include "hse_demo_app_services.h"        // HSE demo helpers (WaitForHSEFWInitToFinish, etc.)
#include "x.509_Certificate_Handling.h"   // Your PEM->DER helper (keep it)
#include "mini_x509.h"                    // Lightweight X.509/ASN.1 parser & locators
#include "rsa_key.h"
#include "sig_map.h"
#include "hse_host_hash.h"
#include "hse_srv_responses.h"
#include "hse_host_format_key_catalogs.h"
#include "hse_keys_allocator.h"
#include "hse_host_import_key.h"
#include "hse_host_sign.h"
#include <stdio.h>                        // Optional printf (not used explicitly below)
#include <stdlib.h>                       // free()

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/
hseSrvResponse_t g2b_HSE_Status;
uint8_t hash[32];
uint32_t hash_len = sizeof(hash);
rsa_pub_t ca_pub;
const uint8_t *spki_bits = NULL;
size_t spki_len = 0;
const uint8_t *tbs = NULL, *sig_oid = NULL, *sig = NULL;
size_t tbs_len = 0, sig_oid_len = 0, sig_len = 0;
SimpleCert c;
uint8_t *ca_der;
size_t ca_der_len;
char* out;
size_t outsize;

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
 ==================================================================================================*/
static hseTxOptions_t txOptions = { HSE_TX_SYNCHRONOUS, NULL, NULL };

/* NVM catalog format*/
const hseKeyGroupCfgEntry_t g2b_nvmKeyCatalog_rsa[] = { { HSE_MU0_MASK,
HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_RSA_PAIR, 10, HSE_KEY2048_BITS }, /* RSA Key Pair Group*/
{ 0, 0, 0, 0, 0 } };

/*RAM catalog format*/
const hseKeyGroupCfgEntry_t g2b_ramKeyCatalog_rsa[] = { { HSE_MU0_MASK,
HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_RSA_PUB, 10, HSE_KEY2048_BITS }, /* RSA Public Key Group*/
{ 0, 0, 0, 0, 0 } };

hseKeyInfo_t rsa_Certificate_PublicKey = { .keyFlags = HSE_KF_USAGE_VERIFY,
		.keyBitLen = 256U, .keyType = HSE_KEY_TYPE_RSA_PUB

};
/*==================================================================================================
 *                                     FUNCTION PROTOTYPES
 ==================================================================================================*/

int main(void) {
	/* ==========================================================
	 * 1.  Initialize environment and hardware security module
	 * ========================================================== */
	WaitForHSEFWInitToFinish();

	/*Key Handle for ECC key pair in NVM Catalog*/
	hseKeyHandle_t g2b_keyPairHandler = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_NVM,
			0, 0);
	/*Key Handle for Public Key in RAM catalog*/
	hseKeyHandle_t g2b_keyPubHandler = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_RAM, 0,
			0);

	/*Formats the Key catalogs */
	g2b_HSE_Status = FormatKeyCatalogs(g2b_nvmKeyCatalog_rsa,
			g2b_ramKeyCatalog_rsa);

	/*Initializes the Key Allocator Driver for Hanfdling Keys in the framework*/
	g2b_HSE_Status = HKF_Init(g2b_nvmKeyCatalog_rsa, g2b_ramKeyCatalog_rsa);

	/* ==========================================================
	 * 2.  Load the CA certificate (in PEM format)
	 * ========================================================== */
	static const char *ca_pem =
			"-----BEGIN CERTIFICATE-----\r\n"
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
	pem_cert_to_der(ca_pem, &ca_der, &ca_der_len);

	/* ==========================================================
	 * 3.  Parse CA certificate to extract important fields
	 * ========================================================== */

	int rc = simple_x509_parse_der(ca_der, ca_der_len, &c);
	if (rc) {
		/* If this fails, the certificate is malformed or unsupported. */
	}

	/* ==========================================================
	 * 4.  Locate critical ASN.1 slices for verification
	 * ========================================================== */

	if (simple_x509_locate_core(ca_der, ca_der_len, &tbs, &tbs_len, &sig_oid,
			&sig_oid_len, &sig, &sig_len) != SX_OK) {
		printf("Locate core failed\n");
		return -1;
	}

	/* ==========================================================
	 * 5.  Extract the CA's own public key (SPKI bits -> N, E)
	 * ========================================================== */

	simple_x509_locate_spki_bits(ca_der, ca_der_len, &spki_bits, &spki_len);
	rsa_pub_init(&ca_pub);
	if (rsa_pub_from_spki_bits(spki_bits, spki_len, &ca_pub) != RSAK_OK) {
		printf("RSA pub parse failed\n");
		return -1;
	}

	/* ==========================================================
	 * 6.  Map signatureAlgorithm OID → RSA + SHA256 scheme
	 * ========================================================== */

	sig_params_t scheme = map_sig_oid(sig_oid, sig_oid_len);
//	if (scheme != SIG_SCHEME_RSA_PKCS1_V15) {
//		printf("Unsupported OID or scheme\n");
//		return -1;
//	}

	g2b_HSE_Status = HashReq(HSE_ACCESS_MODE_ONE_PASS, 0U, 1U,
	HSE_HASH_ALGO_SHA2_256, 0U, (uint32_t) (tbs_len+4), (tbs-4), &hash_len, hash,
			txOptions, HSE_SGT_OPTION_NONE);

	g2b_HSE_Status = LoadRsaPublicKey(&g2b_keyPubHandler, 0U, ca_pub.n_bits,
			ca_pub.N, (uint16_t)ca_pub.E_len, ca_pub.E);

	g2b_HSE_Status = RsaPkcs1v15VerSrv(g2b_keyPubHandler, HSE_HASH_ALGO_SHA2_256,
			(uint32_t) (tbs_len+4), (tbs-4), FALSE, HSE_SGT_OPTION_NONE,
			(uint32_t) &sig_len, sig);

	rsa_pub_free(&ca_pub);

	/* Demo end: stay alive (if you want to attach a debugger/RTT, etc.) */
	for (;;) {
		/* Idle loop; in a real app you would proceed to Step-2/3/4 from here. */
	}

	/* Unreachable */
	/* return 0; */
}
