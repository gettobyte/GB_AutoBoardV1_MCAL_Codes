/*!
** Copyright 2019 NXP
** @file main.c
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */


/* Including necessary configuration files. */
#include "Mcal.h"
#include "Clock_Ip.h"
#include "FlexCAN_Ip.h"
#include "Port.h"
#include "Lpspi_Ip.h"
#include "ST7789_low_level.h"
#include "fonts.h"
#include "IntCtrl_Ip.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


extern void CAN4_ORED_0_31_MB_IRQHandler(void);


#define MSG_ID 800u
#define TX_MB_IDX 0


/* User includes */
uint8 dummyData[8] = {1,2,3,4,5,6,7};

uint8 dummyData_canfd[64] = {1,2,3,4,5,6,7, 8, 9, 10, 11,12, 13, 14, 15, 16, 17, 18 , 19, 20};

void TestDelay(uint32 delay);
void TestDelay(uint32 delay)
{
   static volatile uint32 DelayTimer = 0;
   while(DelayTimer<delay)
   {
       DelayTimer++;
   }
   DelayTimer=0;
}

const char* uint8_to_stringhex(uint8 uint8_val[], size_t len)
{
//	char formattedString[len * 5];

	char* formattedString = (char*) malloc(len *5);

	char* ptr = formattedString;
	for(size_t i = 0; i<len; i++)
	{
		if(i < len -1)
		{
			ptr += sprintf(ptr, "0x%02x, ", uint8_val[i]);
		} else {
			ptr += sprintf(ptr, "0x%02X", uint8_val[i]);
		}
	}

	const char* constFormattedString = formattedString;

	free(formattedString);

	return constFormattedString;


}


Flexcan_Ip_DataInfoType tx_info_polling_std = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = 8u,
        .is_polling = TRUE,
        .is_remote = FALSE
};

Flexcan_Ip_DataInfoType tx_info_inter_std = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = 8u,
        .is_polling = FALSE,
        .is_remote = FALSE
};

Flexcan_Ip_DataInfoType tx_info_polling_canfd = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = 64u,
		.fd_enable = TRUE,
		.fd_padding = 0xAA,
		.enable_brs = TRUE,
        .is_polling = TRUE,
        .is_remote = FALSE
};

Flexcan_Ip_DataInfoType tx_info_inter_canfd = {
        .msg_id_type = FLEXCAN_MSG_ID_STD,
        .data_length = 64u,
		.fd_enable = TRUE,
		.fd_padding = 0xAA,
		.enable_brs = TRUE,
        .is_polling = FALSE,
        .is_remote = FALSE
};


GB_MailBox_CallBack(uint8 instance, Flexcan_Ip_EventType eventType,
                  uint32 buffIdx, const Flexcan_Ip_StateType * flexcanState)
{
//#if GB_RxMailBox_CALLBACK
	Flexcan_Ip_StateType * state = flexcanState;
	state->mbs[buffIdx].state = FLEXCAN_MB_RX_BUSY;
//#else

	uint8_t callback = 0;
	/* Do Nothing */
#endif
}

const char* string1;

int main(void)
{
	Flexcan_Ip_StatusType FlexCAN_Api_Status;
    /* Write your code here */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    IntCtrl_Ip_EnableIrq(FlexCAN4_1_IRQn);
    IntCtrl_Ip_InstallHandler(FlexCAN4_1_IRQn, CAN4_ORED_0_31_MB_IRQHandler, NULL_PTR);


    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    FlexCAN_Ip_Init(INST_FLEXCAN_4, &FlexCAN_State0, &FlexCAN_Config0);

    FlexCAN_Api_Status = FlexCAN_Ip_SetStartMode(INST_FLEXCAN_4);


    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_3);
  	GB_ST7789_Init();

  	TestDelay(700000);
  	ST7789_SetAddressWindow(ST7789_XStart,ST7789_YStart, ST7789_XEnd, ST7789_YEnd);
  	ST7789_Fill_Color(ST77XX_BLACK);
  	TestDelay(700000);


    ST7789_WriteString(0, 80, "BMS VCU: MAster Sending Data", Font_16x26, ST77XX_NEON_GREEN, ST77XX_BLACK);

   for(;;)
   {
//	   FlexCAN_Api_Status = FlexCAN_Ip_SendBlocking(INST_FLEXCAN_4, TX_MB_IDX, &tx_info_polling_std, MSG_ID, (uint8 *)&dummyData, 2000);
//	   TestDelay(2000000);
//

		string1 = uint8_to_stringhex(dummyData_canfd, 20);
		    ST7789_WriteString(0, 140, string1 , Font_16x26, ST77XX_NEON_GREEN, ST77XX_BLACK);


	   FlexCAN_Api_Status = FlexCAN_Ip_Send(INST_FLEXCAN_4, TX_MB_IDX, &tx_info_inter_canfd, MSG_ID, (uint8 *)&dummyData_canfd);
		   TestDelay(2000000);


   }

    return 0;
}

/* END main */
/*!
** @}
*/
