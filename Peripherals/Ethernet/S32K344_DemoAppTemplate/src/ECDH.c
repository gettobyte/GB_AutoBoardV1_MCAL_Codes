/*
 * EDCH.c
 *
 *  Created on: 24-Sep-2025
 *      Author: RohanS002
 */

//==================================================================================================
//                                       INCLUDES
//==================================================================================================
#include "S32K344.h"                    // Core MCU register definitions.
#include "hse_host.h"                   // Main host-side interface for interacting with the HSE.
#include "hse_demo_app_services.h"      // Helper services for the demo application.
#include "hse_interface.h"              // Low-level definitions for the HSE interface.



int main(void) {
	/* This function blocks until the HSE firmware has finished its startup and is ready to accept commands. */
	WaitForHSEFWInitToFinish();





	for (;;) {

	}
	return 0;
}
