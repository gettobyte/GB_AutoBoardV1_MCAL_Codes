/* Copyright 2022 NXP */
/* License: BSD 3-clause
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/
/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K344.h"
#include "hse_host.h"
#include "hse_demo_app_services.h"
#include "x.509_Certificate_Handling.h"
#include "mini_x509.h"
#include <stdio.h>

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/



/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/



/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/



/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/



/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/




int main(void) {
	/*Check Fw Install Status*/
	WaitForHSEFWInitToFinish();

    const char *pem =
		"-----BEGIN CERTIFICATE-----\r\n"
		"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\r\n"
		"-----END CERTIFICATE-----\r\n";

    // 1) Convert PEM to DER
    uint8_t *der = NULL; size_t der_len = 0;
    pem_cert_to_der(pem, &der, &der_len);

    // 2) Parse DER to extract fields
    SimpleCert c;
    int rc = simple_x509_parse_der(der, der_len, &c);
    if (rc) {
        printf("parse failed: %d\n", rc);
        return 1;
    }

//    simple_x509_set_thumbprints(&c, sha1_20bytes, 20, sha256_32bytes, 32);

    /* Super readable (and watchable) */
    printf("Version     : v%d\n", c.version);
    printf("Serial      : %s\n", c.serial_hex);
    printf("Sig Alg     : %s\n", c.sig_alg);
    printf("Issuer      : %s\n", c.issuer);
    printf("Subject     : %s\n", c.subject);
    printf("Not Before  : %s\n", c.not_before);
    printf("Not After   : %s\n", c.not_after);
    printf("PubKey Type : %s\n", c.pubkey_type);
    if (c.pubkey_type[0]=='E') {
        printf("Curve       : %s\n", c.curve);
        printf("EC X        : %s\n", c.ec_x_hex);
        printf("EC Y        : %s\n", c.ec_y_hex);
    } else {
        printf("RSA bits    : %d\n", c.rsa_mod_bits);
        printf("RSA e       : %d\n", c.rsa_exp);
    }
    printf("CA?         : %d\n", c.is_ca);
    printf("pathLen     : %d\n", c.path_len);
    printf("KeyUsage    : 0x%04X\n", c.key_usage);
    for (int i=0;i<c.san_count;i++)
        printf("SAN[%d]      : %s\n", i, c.san[i]);

	free(der);

    // 3) Pass what HSE needs (TBS, signature, alg, SPKI) to HSE verify.

    for (;;) {

    }

    return 0;
}

