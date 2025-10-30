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

int main(void) {
	/* --- HSE BOOT/GATE --- */
	WaitForHSEFWInitToFinish();

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

	uint8_t *ca_der;
	size_t ca_der_len;
	pem_cert_to_der(ca_pem, &ca_der, &ca_der_len);

	SimpleCert c;
	int rc = simple_x509_parse_der(ca_der, ca_der_len, &c);
	if (rc) {
		/* If this fails, the certificate is malformed or unsupported. */
	}

	const uint8_t *ca_spki_bits;
	size_t ca_spki_len;
	simple_x509_locate_spki_bits(ca_der, ca_der_len, &ca_spki_bits,
			&ca_spki_len);

	// Extract RSA (n,e) from ca_spki_bits
	rsa_pub_t ca_pub;
	rsa_pub_init(&ca_pub);
	int r = rsa_pub_from_spki_bits(ca_spki_bits, ca_spki_len, &ca_pub);
	if (r != RSAK_OK) { /* handle error */
	}

	rsa_pub_free(&ca_pub);

//    hseKeyHandle_t ca_key_handle = HSE_RAM_PUBKEY_SLOT_0; // pick a free RAM slot
//    hse_import_rsa_pubkey(ca_key_handle, /*modulus n*/, /*exp e*/); // wrapper around HSE_SRV_IMPORT_KEY

	/* Demo end: stay alive (if you want to attach a debugger/RTT, etc.) */
	for (;;) {
		/* Idle loop; in a real app you would proceed to Step-2/3/4 from here. */
	}

	/* Unreachable */
	/* return 0; */
}
