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
#include "hse_interface.h"
#include "hse_demo_app_services.h"
#include "hse_host_format_key_catalogs.h"
#include "hse_keys_allocator.h"
#include "hse_host_import_key.h"
#include "hse_host_cipher.h"
#include "hse_b_catalog_formatting.h"
#include "hse_host_sign.h"
#include "hse_host_ecc.h"
#include "hse_host_kdf.h"
#include "hse_host_aead.h"
#include "hse_monotonic_cnt.h"
#include "hse_host_cmac_with_counter.h"
#include "hse_host_mac.h"
#include <string.h>
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/



/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
const uint8_t demoapp_msg[] = "HSE Demo App Session Keys related example, this is the example message for the demo";
const uint8_t demoapp_msg_2[] = "Another example message for Demo App";

static const uint8_t iv_demo[] =
{ 0xff, 0xbc, 0x51, 0x6a, 0x8f, 0xbe, 0x61, 0x52, 0xaa, 0x42, 0x8c, 0xdd, 0x80,
        0x0c, 0x06, 0x2d
};
const uint8_t KdfSP800_108_FixedInfo_1_0[] = { 0x5a, 0xc3, 0x73, 0xd4, 0x2e, 0xd9, 0x24, 0x27, 0xd8,
0xff, 0x6c, 0xff, 0xf7, 0xea, 0xe1, 0x3d, 0x66, 0xd3, 0xc7, 0xe5, 0x36, 0xcc, 0x74, 0x98, 0x59,
0xe2, 0xa4, 0x9e, 0x3e, 0xea, 0x2a, 0xd8, 0x46, 0xc9, 0xfb, 0xb7, 0xdd, 0xd9, 0x9a, 0x1e, 0x6a,
0x54, 0xa8, 0x9a, 0x87, 0xdb, 0x98, 0xdb, 0x6b, 0x82, 0x29, 0xf5, 0x77, 0xb5, 0x52, 0xe0, 0x9a, 0xee,
0xd5, 0xe6 };

const uint8_t KdfSP800_108_SrcKey_1_0[] = { 0x00, 0x93, 0x00, 0xd2, 0x65, 0xd1, 0xf1, 0xb2, 0x8b, 0x50, 0x5d, 0xcc, 0xc1, 0x62, 0xf4, 0xf8 };

const hseKeyGroupCfgEntry_t NVM_Catalog [] =
{
        /*  keyType                 numOfKeySlots   maxKeyBitLen  */                                                                      \
        /* CUST keys */                                                                                                                   \
        {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_SHE, 12U, HSE_KEY128_BITS}, /* MASTER_ECU_KEY, BOOT_MAC_KEY, KEY_1 to KEY_10 */ \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_AES, 4U, HSE_KEY128_BITS},                                                 \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_AES, 7U, HSE_KEY256_BITS},  /* HMAC key */                                 \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_HMAC, 2U, HSE_KEY512_BITS}, /* ECC keys */                                 \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, WRP_KEY_TYPE_ECC_PAIR, 3U, WRP_ECC_KEY_SIZE},                                           \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, WRP_KEY_TYPE_ECC_PUB, 1U, WRP_ECC_KEY_SIZE},                                            \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, WRP_KEY_TYPE_ECC_PUB_EXT, 1U, WRP_ECC_KEY_SIZE}, /* RSA keys */                         \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_RSA_PAIR, 2U, HSE_KEY4096_BITS},                                           \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_RSA_PUB, 1U, HSE_KEY4096_BITS},                                            \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_CUST, HSE_KEY_TYPE_RSA_PUB_EXT, 1U, HSE_KEY4096_BITS}, /* OEM keys */                         \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_AES, 3U, HSE_KEY128_BITS},                                                  \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_AES, 3U, HSE_KEY256_BITS},   /* HMAC key */                                 \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_HMAC, 1U, HSE_KEY1024_BITS}, /* ECC keys */                                 \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, WRP_KEY_TYPE_ECC_PAIR, 1U, WRP_ECC_KEY_SIZE},                                            \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, WRP_KEY_TYPE_ECC_PUB, 1U, WRP_ECC_KEY_SIZE},                                             \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, WRP_KEY_TYPE_ECC_PUB_EXT, 1U, WRP_ECC_KEY_SIZE}, /* RSA keys */                          \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_RSA_PAIR, 1U, HSE_KEY4096_BITS},                                            \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_RSA_PUB, 1U, HSE_KEY4096_BITS},                                             \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_OEM, HSE_KEY_TYPE_RSA_PUB_EXT, 1U, HSE_KEY4096_BITS},                                         \
            {HSE_MU0_MASK, HSE_KEY_OWNER_OEM, WRP_KEY_TYPE_ECC_PUB, 1U, WRP_ECC_KEY_SIZE},                                                \
        {                                                                                                                                 \
                0U, 0U, 0U, 0U, 0U                                                                                                        \
        }

};


const hseKeyGroupCfgEntry_t RAM_Catalog [] =
{
        /*  keyType                   numOfKeySlots maxKeyBitLen*/                                        \
        /* Symetric key */                                                                                \
        {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_SHE, 1U, HSE_KEY128_BITS}, /* KEY_RAM */        \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_AES, 10U, HSE_KEY128_BITS},                 \
            {HSE_MU0_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_AES, 10U, HSE_KEY256_BITS},     /* HMAC key */ \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_HMAC, 6U, HSE_KEY1024_BITS}, /* RSA key */  \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_RSA_PUB, 2U, HSE_KEY2048_BITS},             \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_RSA_PUB_EXT, 1U, HSE_KEY1024_BITS},         \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, WRP_KEY_TYPE_ECC_PAIR, 2U, WRP_ECC_KEY_SIZE},            \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, WRP_KEY_TYPE_ECC_PUB, 5U, WRP_ECC_KEY_SIZE},             \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_SHARED_SECRET, 2U, HSE_KEY638_BITS},        \
            {HSE_ALL_MU_MASK, HSE_KEY_OWNER_ANY, HSE_KEY_TYPE_SHARED_SECRET, 1U, HSE_KEY2048_BITS},       \
        {                                                                                                 \
                0U, 0U, 0U, 0U, 0U                                                                        \
        }
};

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#ifdef HSE_SPT_KDF_SP800_108
  hseKeyInfo_t KdfSP800_108_SECRET_KEY_INFO_1_0 =
{
    .keyType = HSE_KEY_TYPE_AES,
    .keyBitLen = 128UL,
    .keyFlags = (HSE_KF_USAGE_DERIVE | HSE_KF_ACCESS_EXPORTABLE)
};

hseKey_t KdfSP800_108_SECRET_KEY_1_0 = {
    .keyHandle = HSE_INVALID_KEY_HANDLE,
    .pKeyInfo = &KdfSP800_108_SECRET_KEY_INFO_1_0,
    .keyValue = {
        .pKey2 = (uint8_t *)KdfSP800_108_SrcKey_1_0,
        .keyLen2 = ARRAY_SIZE(KdfSP800_108_SrcKey_1_0),
    },
};

hseKeyImportParams_t KdfSP800_108_ImportSecret_1_0 =
{
    .pKey = &KdfSP800_108_SECRET_KEY_1_0
};

/* kdf */
hseKdfSP800_108Scheme_t KdfSP800_108_Scheme_1_0 =
{
    .mode = HSE_KDF_SP800_108_COUNTER,
    .counterByteLength = HSE_KDF_SP800_108_COUNTER_LEN_DEFAULT,
    .kdfCommon = {
        .srcKeyHandle = HSE_INVALID_KEY_HANDLE,
        .targetKeyHandle = HSE_INVALID_KEY_HANDLE,
        .keyMatLen = BITS_TO_BYTES(512UL),
        .kdfPrf = HSE_KDF_PRF_CMAC,
        .pInfo = (HOST_ADDR)KdfSP800_108_FixedInfo_1_0,
        .infoLength = ARRAY_SIZE(KdfSP800_108_FixedInfo_1_0)
    }
};

uint8_t aes_exported[64];
uint16_t aes_exported_len;
#endif
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
hseSrvResponse_t KdfSP800_108ReqTest_demo();
static hseSrvResponse_t KdfSP800_108Test_0(hseKeyImportParams_t *pImportSecretParams, hseKdfSP800_108Scheme_t *pKdfScheme);

uint8_t ECC_Public_key[64];

const uint8_t CMAC_Plaintext[] =
{ 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73,
        0x93, 0x17, 0x2a
};

uint8_t CMAC_Tag_OutPut[512] = {0};
uint32_t CMAC_Tag_length = 16;

uint8_t Fast_CMAC_Tag_OutPut[512] = {0};
uint8_t Fast_CMAC_Tag_length = 16;

hseAttrSecureLifecycle_t lifecycle;

uint8_t keyBuf[2 * BITS_TO_BYTES(HSE_MAX_ECC_KEY_BITS_LEN)] = {0};//132
uint16_t keyBufLen = sizeof(keyBuf);//132

hseKdfSP800_108Scheme_t key_Derive_info;
hseKeyHandle_t targetSharedSecretKey_1 = HSE_INVALID_KEY_HANDLE;


int main(void)
{
	/*Check Fw Install Status*/
	WaitForHSEFWInitToFinish();
	hseSrvResponse_t HseResponse;

	//Format the key catalog
	HseResponse = FormatKeyCatalogs(NVM_Catalog, RAM_Catalog);
	ASSERT(HSE_SRV_RSP_OK == HseResponse);
	hseKeyInfo_t keyInfo;

	HseResponse = HKF_Init(NVM_Catalog, RAM_Catalog);
	ASSERT(HSE_SRV_RSP_OK == HseResponse);

	HseResponse = HSE_ReadLifecycle(&lifecycle);

	//For Session Keys example
    hseKeyHandle_t eccRAMKeyHandle = HSE_DEMO_RAM_ECC_PAIR_KEY_HANDLE;
	//hseKeyHandle_t eccRAMKeyHandle = HSE_DEMO_RAM_ECC_PUB_KEY_HANDLE;
    hseKeyHandle_t DHSharedSecretRAMKeyHandle = HSE_DEMO_DH_SHARED_SECRET_HANDLE;
   // hseKeyHandle_t AESDerivedKeyInfoHandle1 = HSE_DEMO_RAM_AES256_KEY1;
    hseKeyHandle_t AESDerivedKeyInfoHandle1 = HSE_DEMO_NVM_AES256_KEY2;

    /********* Key Exchange protocol ECDH for Shared Secret Key */
    // Key Exchange via ECDH protocol
    //generate the ecc private - public key and export the public key to application
    HseResponse = GenerateEccKeyAndExportPublic( eccRAMKeyHandle, HSE_EC_SEC_SECP256R1, HSE_KF_USAGE_EXCHANGE, ECC_Public_key);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);

    // transmit the exported public key to the other node via can and also receive the exported public key of other node and use that in next step to import it in public key handle

    /* Import ECC Key */
    // import the received public key from other node to the ecc key pair handle
    HseResponse = ImportEccKeyReq(HSE_DEMO_RAM_ECC_PUB_KEY_HANDLE, HSE_KEY_TYPE_ECC_PUB,(HSE_KF_USAGE_EXCHANGE | HSE_KF_ACCESS_EXPORTABLE), HSE_EC_SEC_SECP256R1, KeyBitLen(HSE_EC_SEC_SECP256R1), ECC_Public_key, NULL);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);

    HseResponse = ExportPlainFormattedEccPubKeyReq(HSE_DEMO_RAM_ECC_PUB_KEY_HANDLE, &keyInfo, &keyBufLen, keyBuf,  HSE_KEY_FORMAT_ECC_PUB_RAW);

    // now compute the shared secret from the public( having new public key from other node) and private key handles
    /*Compute DH Shared Secret (ECDH)*/
    HseResponse = DHSharedSecretCompute(HSE_DEMO_RAM_ECC_PUB_KEY_HANDLE,HSE_DEMO_RAM_ECC_PAIR_KEY_HANDLE,&DHSharedSecretRAMKeyHandle,RAM_KEY,KeyBitLen(HSE_EC_SEC_SECP256R1));
    ASSERT(HSE_SRV_RSP_OK == HseResponse);


    //HseResponse = ExportPlainFormattedEccPubKeyReq(HSE_DEMO_RAM_ECC_PUB_KEY_HANDLE, &keyInfo, &keyBufLen, keyBuf,  HSE_KEY_FORMAT_ECC_PUB_RAW);

    HKF_AllocKeySlot(RAM_KEY, HSE_KEY_TYPE_SHARED_SECRET, KdfSP800_108_Scheme_1_0.kdfCommon.keyMatLen * 8U, &targetSharedSecretKey_1);

    KdfSP800_108_Scheme_1_0.kdfCommon.srcKeyHandle = DHSharedSecretRAMKeyHandle ;
    KdfSP800_108_Scheme_1_0.kdfCommon.targetKeyHandle = targetSharedSecretKey_1;


    HseResponse =  HSEKdfSP800_108Req(&KdfSP800_108_Scheme_1_0);



  /***** Derive Key using SP800_108 KDF for AES Key*********/

    //HSEKdfSP800
   // HseResponse = KdfSP800_108ReqTest_demo();

    //Declare the information about the 256 bits AES key to be extracted
    hseKeyInfo_t aes256KeyInfo = {
        .keyType = HSE_KEY_TYPE_AES,                             //Will generate an AES key
        .keyFlags = (HSE_KF_USAGE_ENCRYPT |HSE_KF_USAGE_DECRYPT| //Usage flags for this key - Encrypt/Decrypt/Sign/Verify - AEAD
            HSE_KF_USAGE_SIGN|HSE_KF_USAGE_VERIFY | HSE_KF_ACCESS_EXPORTABLE ),
        .keyBitLen = 256U,                                       //256 bits key
    };

    //Extract the 256 bits AES key from the remaining derived key material
    HseResponse = HSEKeyDeriveExtractKeyReq
            (
                   KdfSP800_108_Scheme_1_0.kdfCommon.targetKeyHandle,
            	  //DHSharedSecretRAMKeyHandle,
            		BITS_TO_BYTES(aes256KeyInfo.keyBitLen),
                    &AESDerivedKeyInfoHandle1,
					//NVM_KEY,
					 RAM_KEY,
                    aes256KeyInfo
            );
    ASSERT(HSE_SRV_RSP_OK == HseResponse);


    HseResponse = ExportPlainSymKeyReq(AESDerivedKeyInfoHandle1,&aes256KeyInfo, aes_exported, aes_exported_len  );



    /****** MAC Generation and Verification ****************/

    //CMAC Generation using CMAC_Plaintext and AESDerivedKeyInfoHandle1 key handle( which is derived from KDF function).
    hseMacScheme_t macScheme;
    macScheme.macAlgo = HSE_MAC_ALGO_CMAC;
    macScheme.sch.cmac.cipherAlgo = HSE_CIPHER_ALGO_AES;
    HseResponse = AesCmacGenerate(AESDerivedKeyInfoHandle1, NUM_OF_ELEMS(CMAC_Plaintext), CMAC_Plaintext, &CMAC_Tag_length,  CMAC_Tag_OutPut, HSE_SGT_OPTION_NONE );
  		  //MacSignSrv(HSE_ACCESS_MODE_ONE_PASS, 0, macScheme, AESDerivedKeyInfoHandle1, NUM_OF_ELEMS(CMAC_Plaintext), CMAC_Plaintext, &CMAC_Tag_length,  CMAC_Tag_OutPut, HSE_SGT_OPTION_NONE );

    // Master will transmit the CMAC_PlainText & CMAC_Tag_OutPut to receiver and also AES Derived Key value to receiver.
    // Receiver will received the derived key handle and will import that into it for AES key handle in NVM.


   HseResponse = AesCmacVerify(AESDerivedKeyInfoHandle1, NUM_OF_ELEMS(CMAC_Plaintext), CMAC_Plaintext, &CMAC_Tag_length,  CMAC_Tag_OutPut, HSE_SGT_OPTION_NONE );


   /********* CMAC With Counter Demo Code ********************/

   uint32_t volatileCnt       = 0xFFFFFFFFUL;

    uint32_t rpBitSize          = 40UL;
    uint32_t TxnodecntIdx       = HSE_NUM_OF_MONOTONIC_COUNTERS - 3UL;
    uint32_t RxnodecntIdx       = HSE_NUM_OF_MONOTONIC_COUNTERS - 2UL;

    HseResponse =  MonotonicCnt_Config(TxnodecntIdx,rpBitSize);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);

    /* Configure Node B */
    HseResponse = MonotonicCnt_Config(RxnodecntIdx, rpBitSize);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);


    /* Configure Node A Counter as a default value */
    HseResponse = MonotonicCnt_Increment(TxnodecntIdx, 0x800000UL);
      ASSERT(HSE_SRV_RSP_OK == HseResponse);

      /* Configure Node B Counter as a default value */
      HseResponse = MonotonicCnt_Increment(RxnodecntIdx, 0x800000UL);
      ASSERT(HSE_SRV_RSP_OK == HseResponse);


    HseResponse = CmacWithCounter(AESDerivedKeyInfoHandle1, HSE_AUTH_DIR_GENERATE,TxnodecntIdx, 0,
    		NUM_OF_ELEMS(CMAC_Plaintext)*8U, CMAC_Plaintext, (16*8), CMAC_Tag_OutPut, &volatileCnt, HSE_SGT_OPTION_NONE);


    HseResponse = CmacWithCounter(AESDerivedKeyInfoHandle1, HSE_AUTH_DIR_VERIFY,RxnodecntIdx, 0,
    		NUM_OF_ELEMS(CMAC_Plaintext)*8U, CMAC_Plaintext, (16*8), CMAC_Tag_OutPut, &volatileCnt, HSE_SGT_OPTION_NONE);






    /***************Fast CMAC ***************************/

    HseResponse = AesFastCmacGenerate(AESDerivedKeyInfoHandle1, NUM_OF_ELEMS(CMAC_Plaintext)*8, CMAC_Plaintext, Fast_CMAC_Tag_length*8, Fast_CMAC_Tag_OutPut);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);


    //Sender will send, plaintext, aesderivekey info and
    HseResponse = AesFastCmacVerify(AESDerivedKeyInfoHandle1, NUM_OF_ELEMS(CMAC_Plaintext)*8, CMAC_Plaintext, Fast_CMAC_Tag_length*8, Fast_CMAC_Tag_OutPut);
    ASSERT(HSE_SRV_RSP_OK == HseResponse);



    uint8_t ciphermsg[NUM_OF_ELEMS(demoapp_msg)] = {0U};



    /* Finished session keys related example */
    for (;;) {

    }

    return 0;
}


hseKeyHandle_t srcKey_0 = HSE_INVALID_KEY_HANDLE;
hseKeyHandle_t targetSharedSecretKey_0 = HSE_INVALID_KEY_HANDLE;

hseSrvResponse_t KdfSP800_108ReqTest_demo()
{
    hseSrvResponse_t hseResponse;

    HKF_AllocKeySlot(RAM_KEY, KdfSP800_108_ImportSecret_1_0.pKey->pKeyInfo->keyType,
                     KdfSP800_108_ImportSecret_1_0.pKey->pKeyInfo->keyBitLen, &srcKey_0);

    HKF_AllocKeySlot(RAM_KEY, HSE_KEY_TYPE_SHARED_SECRET, KdfSP800_108_Scheme_1_0.kdfCommon.keyMatLen * 8U, &targetSharedSecretKey_0);

    KdfSP800_108_ImportSecret_1_0.pKey->keyHandle = srcKey_0;
    KdfSP800_108_Scheme_1_0.kdfCommon.srcKeyHandle = srcKey_0;
    KdfSP800_108_Scheme_1_0.kdfCommon.targetKeyHandle = targetSharedSecretKey_0;
    hseResponse = KdfSP800_108Test_0(&KdfSP800_108_ImportSecret_1_0, &KdfSP800_108_Scheme_1_0);
    goto exit;
    exit:
    return hseResponse;
}


static hseSrvResponse_t KdfSP800_108Test_0
(hseKeyImportParams_t *pImportSecretParams, hseKdfSP800_108Scheme_t *pKdfScheme)
{
    hseSrvResponse_t hseResponse;

    pImportSecretParams->authParams.pKeyHandle = NULL;
    pImportSecretParams->cipherParams.pKeyHandle = NULL;
    hseResponse = ImportKeyReq(pImportSecretParams);
    if(HSE_SRV_RSP_OK != hseResponse)
    {
        goto exit;
    }

    hseResponse = HSEKdfSP800_108Req(pKdfScheme);
    if(HSE_SRV_RSP_OK != hseResponse)
    {
        goto exit;
    }
    exit:
    return hseResponse;
}
