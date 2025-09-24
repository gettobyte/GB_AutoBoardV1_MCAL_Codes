/*
 * RSA.c
 *
 * Created on: 24-Sep-2025
 * Author: RohanS002
 */

//==================================================================================================
//                                       INCLUDES
//==================================================================================================
#include "S32K344.h"                    // Core MCU register definitions.
#include "hse_host.h"                   // Main host-side interface for interacting with the HSE.
#include "hse_demo_app_services.h"      // Helper services for the demo application.
#include "hse_interface.h"              // Low-level definitions for the HSE interface.
#include "hse_host_rsa_cipher.h"        // Host-side functions specific to RSA encryption/decryption.
#include "hse_host_format_key_catalogs.h"// Host-side function for formatting HSE key catalogs.
#include "hse_keys_allocator.h"         // Host-side key management utilities.
#include "hse_host_sign.h"              // Host-side functions for signing and verification.
#include "hse_host_import_key.h"        // Host-side functions for importing keys into the HSE.

//==================================================================================================
//                                     GLOBAL CONSTANTS
//==================================================================================================

/**
 * @brief Buffer to hold the RSA modulus 'n'.
 *
 * The modulus is a core component of both the public and private RSA keys.
 * Its size [2048/8] allocates 256 bytes for a 2048-bit RSA key.
 * This buffer will be populated by the key generation function when the HSE
 * returns the public part of the key.
 */
uint8_t g2b_n_Common[256]; // The modulus 'n', which is part of both public and private keys.

/**
 * @brief The constant public exponent 'e' for RSA key generation.
 *
 * This value, {0x01, 0x00, 0x01}, represents the integer 65537. It is a
 * standard, computationally efficient choice for the public exponent and is
 * provided as an input to the key generation service.
 */
const uint8_t g2b_e_Public[] = { 0x01, 0x00, 0x01 };

/**
 * @brief Buffer to hold the RSA private exponent 'd'.
 *
 * NOTE: In this specific example, this buffer is NOT used because the private key
 * is generated securely inside the HSE and never exposed to the host application.
 * This buffer would be used if you were importing a pre-existing private key.
 */
uint8_t g2b_d_Private[256];

/* The message that will be digitally signed. */
const uint8_t msg[] = "Trying RSA Signature";

/* A buffer to store the generated signature. The size must be equal to the key size (256 bytes for RSA-2048).*/
uint8_t *rsa_signature_buffer[2] = { 0 };

/* An array specifying the length of the signature buffer. */
uint32_t signatureLengths[] = { 256 };

//==================================================================================================
//                                     GLOBAL VARIABLES
//==================================================================================================

/*
 * This section defines the "blueprints" for the HSE's secure key storage.
 */

/* NVM (Non-Volatile Memory) catalog format */
const hseKeyGroupCfgEntry_t g2b_nvmKeyCatalog_rsa[] = {
// Defines one group of keys in NVM.
		{
		HSE_MU0_MASK,           // Access granted to Host Core (Master Unit 0).
				HSE_KEY_OWNER_CUST, // The key is owned by the customer (as opposed to NXP).
				HSE_KEY_TYPE_RSA_PAIR, // The type of key to be stored: a full RSA key pair.
				10, // The number of key slots in this group (can store up to 10 keys).
				HSE_KEY2048_BITS // The size of each key in this group: 2048 bits.
		}, { 0, 0, 0, 0, 0 } // End of configuration marker.
};

/* RAM (Volatile Memory) catalog format */
const hseKeyGroupCfgEntry_t g2b_ramKeyCatalog_rsa[] = {
// Defines one group of keys in RAM.
		{
		HSE_MU0_MASK,           // Access granted to Host Core.
				HSE_KEY_OWNER_ANY,      // Can be used by any authorized user.
				HSE_KEY_TYPE_RSA_PUB, // The type of key to be stored: ONLY an RSA public key.
				10,                    // The number of key slots in this group.
				HSE_KEY2048_BITS // The size of each key in this group: 2048 bits.
		}, { 0, 0, 0, 0, 0 } // End of configuration marker.
};

/* Global variable to store the status response from HSE services. */
hseSrvResponse_t g2b_Status = HSE_SRV_RSP_OK;

int main(void) {
	/* This function blocks until the HSE firmware has finished its startup and is ready to accept commands. */
	WaitForHSEFWInitToFinish();

	/**
	 * @brief Create a handle for the RSA key pair in NVM.
	 * This handle points to the secure, persistent storage. It will be used for the
	 * signing operation, as signing requires the private key.
	 * GET_KEY_HANDLE(catalog, group_index, slot_index)
	 */
	hseKeyHandle_t g2b_keyPairHandler = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_NVM,
			0, 0);

	/**
	 * @brief Create a handle for the RSA public key in RAM.
	 * This handle points to the volatile storage. The public key will be loaded here
	 * from the host for the verification step.
	 */
	hseKeyHandle_t g2b_keyPubHandler = GET_KEY_HANDLE(HSE_KEY_CATALOG_ID_RAM, 0,
			0);

	/**
	 * @brief Formats the HSE's secure key storage areas.
	 * This command erases and configures the HSE's memory according to the
	 * layouts defined in `g2b_nvmKeyCatalog_rsa` and `g2b_ramKeyCatalog_rsa`.
	 * This must be done before any keys can be generated or loaded.
	 */
	g2b_Status = FormatKeyCatalogs(g2b_nvmKeyCatalog_rsa,
			g2b_ramKeyCatalog_rsa);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status); // Assert will halt if the operation fails.

	/**
	 * @brief Initializes the software-side key management framework.
	 * This function reads the same catalog blueprints to create a software map
	 * of the key layout, allowing the application to track key slots.
	 */
	g2b_Status = HKF_Init(g2b_nvmKeyCatalog_rsa, g2b_ramKeyCatalog_rsa);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status);

	/**
	 * @brief Command the HSE to generate an RSA key pair.
	 * @param &g2b_keyPairHandler - Handle indicating WHERE to store the generated pair in NVM.
	 * @param 1                   - The number of public key buffers (1, for 'n').
	 * @param 2048                - The desired key size in bits.
	 * @param sizeof(g2b_e_Public)- The length of the public exponent 'e'.
	 * @param &g2b_e_Public       - Pointer to the public exponent 'e' (65537).
	 * @param &g2b_n_Common       - Pointer to a buffer where the HSE will write the generated modulus 'n'.
	 *
	 * The private key is generated and stored securely within the HSE, never exposed.
	 */
	g2b_Status = GenerateRsaKeyPair(&g2b_keyPairHandler, 1, 2048,
			sizeof(g2b_e_Public), &g2b_e_Public, &g2b_n_Common);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status);

	/**
	 * @brief Load the public key into the RAM catalog for verification.
	 * This takes the public components ('n' and 'e') and imports them into a RAM slot.
	 * @param &g2b_keyPubHandler - Handle indicating WHERE to store the public key in RAM.
	 * @param 0                  - Key flags.
	 * @param 2048               - The key size in bits.
	 * @param g2b_n_Common       - The modulus 'n' that was just generated.
	 * @param sizeof(g2b_e_Public)- The length of the public exponent.
	 * @param g2b_e_Public       - The public exponent 'e'.
	 */
	g2b_Status = LoadRsaPublicKey(&g2b_keyPubHandler, 0, 2048, g2b_n_Common,
			sizeof(g2b_e_Public), g2b_e_Public);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status);

	// This function is commented out but shows how you would load a pre-existing private key if you had one.
	// g2b_Status = LoadRsaPrivateKey(&g2b_keyPairHandler, 1, 2048, g2b_n_Common, sizeof(g2b_e_Public), g2b_e_Public, g2b_d_Private);
	// ASSERT(HSE_SRV_RSP_OK == g2b_Status);

	/**
	 * @brief Perform an RSA signature operation using the PSS padding scheme.
	 * @param g2b_keyPairHandler     - Handle to the PRIVATE key pair in NVM.
	 * @param 20                     - The salt length for the PSS scheme.
	 * @param HSE_HASH_ALGO_SHA2_256 - The hash algorithm to use on the message before signing.
	 * @param sizeof(msg)            - The length of the message to sign.
	 * @param msg                    - Pointer to the message itself.
	 * @param FALSE                  - Whether the input is pre-hashed (it's not).
	 * @param HSE_SGT_OPTION_NONE    - Scatter-gather table options (not used here).
	 * @param signatureLengths       - An array containing the size of the output buffer.
	 * @param rsa_signature_buffer   - Pointer to the buffer where the HSE will write the signature.
	 */
	g2b_Status = RsaPssSignSrv(g2b_keyPairHandler, 20, HSE_HASH_ALGO_SHA2_256,
			sizeof(msg), msg, FALSE, HSE_SGT_OPTION_NONE, signatureLengths,
			rsa_signature_buffer);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status);

	/**
	 * @brief Perform an RSA verification operation.
	 * @param g2b_keyPubHandler    - Handle to the PUBLIC key in RAM.
	 * @param 20                   - The same salt length used during signing.
	 * @param HSE_HASH_ALGO_SHA2_256 - The same hash algorithm used during signing.
	 * @param sizeof(msg)          - The length of the original message.
	 * @param msg                  - Pointer to the original message.
	 * @param FALSE                - Whether the input is pre-hashed.
	 * @param HSE_SGT_OPTION_NONE  - SGT options.
	 * @param signatureLengths     - An array containing the length of the signature.
	 * @param rsa_signature_buffer - Pointer to the signature that needs to be verified.
	 *
	 * If the signature is valid for the given message and public key, this service will return HSE_SRV_RSP_OK.
	 */
	g2b_Status = RsaPssVerSrv(g2b_keyPubHandler, 20, HSE_HASH_ALGO_SHA2_256,
			sizeof(msg), msg, FALSE, HSE_SGT_OPTION_NONE, signatureLengths,
			rsa_signature_buffer);
	ASSERT(HSE_SRV_RSP_OK == g2b_Status); // If this assert passes, the signature is valid!

	/* Infinite loop to keep the processor running after the demo is complete. Typical for embedded systems. */
	for (;;) {

	}

	return 0;
}
