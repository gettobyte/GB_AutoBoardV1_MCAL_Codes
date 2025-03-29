/*!
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
#include "string.h"
#include "Lpspi_Ip.h"
#include "ST7789_low_level.h"
#include "fonts.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "IntCtrl_Ip.h"

  Flexcan_Ip_DataInfoType rx_info_polling_std = {
               .msg_id_type = FLEXCAN_MSG_ID_STD,
               .data_length = 8u,
               .is_polling = TRUE,
               .is_remote = FALSE
       };

       Flexcan_Ip_DataInfoType rx_info_inter_std = {
               .msg_id_type = FLEXCAN_MSG_ID_STD,
               .data_length = 8u,
               .is_polling = FALSE,
               .is_remote = FALSE
       };

       Flexcan_Ip_DataInfoType rx_info_polling_canfd = {
   				.msg_id_type = FLEXCAN_MSG_ID_STD,
   				.data_length = 64u,
   				.fd_enable = TRUE,
   				.fd_padding = 0xAA,
   				.enable_brs = TRUE,
   				.is_polling = TRUE,
   				.is_remote = FALSE,
   	};

       Flexcan_Ip_DataInfoType rx_info_inter_canfd = {
   				.msg_id_type = FLEXCAN_MSG_ID_STD,
   				.data_length = 64u,
   				.fd_enable = TRUE,
   				.fd_padding = 0xAA,
   				.enable_brs = TRUE,
   				.is_polling = FALSE,
   				.is_remote = FALSE,
   	};
extern void CAN4_ORED_0_31_MB_IRQHandler(void);
#define GB_RxMailBox_CALLBACK 1

#define MSG_ID 800u
#define RX_MB_IDX 1U

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

const char* string1, string2;

GB_MailBox_CallBack(uint8 instance, Flexcan_Ip_EventType eventType,
                  uint32 buffIdx, const Flexcan_Ip_StateType * flexcanState)
{
#if GB_RxMailBox_CALLBACK
	Flexcan_Ip_StateType * state = flexcanState;
	state->mbs[buffIdx].state = FLEXCAN_MB_RX_BUSY;
	   {
			   if(FlexCAN_State0.mbs[MSG_ID].pMBmessage->cs != 0)
			   	   {
				   	   if(FlexCAN_State0.mbs[MSG_ID].pMBmessage->msgId == 800)
				   		   {
				   		      string1 = uint8_to_stringhex(&(FlexCAN_State0.mbs[MSG_ID].pMBmessage->data), FlexCAN_State0.mbs[MSG_ID].pMBmessage->dataLen);
				   	           ST7789_WriteString(0, 140, string1 , Font_16x26, ST77XX_NEON_GREEN, ST77XX_BLACK);
				   		   }
				   	   memset(&FlexCAN_State0.mbs[MSG_ID].pMBmessage->cs, 0x0, sizeof(FlexCAN_State0.mbs[MSG_ID].pMBmessage->cs));
			   	   }
		   }
	#else

	uint8_t callback = 0;
	/* Do Nothing */
#endif
}


int main(void)
{
	Flexcan_Ip_StatusType FlexCAN_Api_Status;
    /* Write your code here */
    Clock_Ip_Init(&Mcu_aClockConfigPB[0]);

    IntCtrl_Ip_EnableIrq(FlexCAN4_1_IRQn);
    IntCtrl_Ip_InstallHandler(FlexCAN4_1_IRQn, CAN4_ORED_0_31_MB_IRQHandler, NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    Lpspi_Ip_Init(&Lpspi_Ip_PhyUnitConfig_SpiPhyUnit_0_Instance_3);
  	GB_ST7789_Init();

  	TestDelay(700000);
  	ST7789_SetAddressWindow(ST7789_XStart,ST7789_YStart, ST7789_XEnd, ST7789_YEnd);
  	ST7789_Fill_Color(ST77XX_RED);
  	TestDelay(700000);


    ST7789_WriteString(0, 80, "BMS VCU: Receiver", Font_16x26, ST77XX_NEON_GREEN, ST77XX_BLACK);


    Flexcan_Ip_MsgBuffType rxData;

    FlexCAN_Ip_Init(INST_FLEXCAN_4, &FlexCAN_State0, &FlexCAN_Config0);

    FlexCAN_Api_Status = FlexCAN_Ip_SetStartMode(INST_FLEXCAN_4);
    FlexCAN_Api_Status = FlexCAN_Ip_ConfigRxMb(INST_FLEXCAN_4, RX_MB_IDX, &rx_info_inter_canfd, MSG_ID);

 	ST7789_Fill_Color(ST77XX_BLACK);
    ST7789_SetAddressWindow(ST7789_XStart,ST7789_YStart, ST7789_XEnd, ST7789_YEnd);
    ST7789_WriteString(0, 80, "Receiving CAN Data", Font_16x26, ST77XX_NEON_GREEN, ST77XX_BLACK);

    FlexCAN_Ip_Receive(INST_FLEXCAN_4, RX_MB_IDX, &rxData, false);

   for(;;)
   {

//	 FlexCAN_Api_Status = FlexCAN_Ip_ConfigRxMb(INST_FLEXCAN_4, RX_MB_IDX, &rx_info_polling_std, MSG_ID);
//	 while(FLEXCAN_STATUS_TIMEOUT == FlexCAN_Ip_ReceiveBlocking(INST_FLEXCAN_4, RX_MB_IDX, &rxData, true,1000));
//     // clear the data received in rx buffer to Null
//	 memset(rxData.data, NULL, 64);

   }

    return 0;
}

/* END main */
/*!
** @}
*/
