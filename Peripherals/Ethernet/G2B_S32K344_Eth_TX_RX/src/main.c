
/* Including necessary configuration files. */
#include "Mcal.h"
#include "Clock_Ip.h"
#include "Siul2_Port_Ip_Cfg.h"
#include "Siul2_Port_Ip.h"
#include "Gmac_Ip.h"
#include "string.h"

volatile int exit_code = 0;
/* User includes */

#define INST_GMAC_0    (0U)

Gmac_Ip_StatusType Status = 0;

uint8 MacAddr_Src[6U] = {0U};

uint8 MacAddr_Dest[6U] = {02,00,00,00,00,02};

Gmac_Ip_TxOptionsType TxOptions = {TRUE, GMAC_CRC_AND_PAD_INSERTION, GMAC_CHECKSUM_INSERTION_DISABLE};

Gmac_Ip_BufferType TxBuffer = {0};

Gmac_Ip_BufferType RxBuffer = {0};

Gmac_Ip_TxInfoType TxInfo  = {0};

Gmac_Ip_RxInfoType RxInfo  = {0};

/*
*  Ethernet Frame Format (IEEE 802.3 / Ethernet II)
*
*  +------------+------------+-----------+------------------+-----------+
*  | Destination|   Source   | EtherType |      Payload     |   FCS     |
*  |   MAC (6B) |   MAC (6B) |   (2B)    |   (46–1500 B)    |   (4B)    |
*  +------------+------------+-----------+------------------+-----------+
*
*  Field Details:
*   - Destination MAC (6 bytes): Who the frame is sent to
*   - Source MAC      (6 bytes): Who is sending the frame
*   - EtherType/Length(2 bytes): Protocol indicator
*         e.g. 0x0800 = IPv4, 0x0806 = ARP, custom = 0x88B5 etc.
*   - Payload         (46–1500 bytes): Actual data being sent
*   - FCS             (4 bytes): CRC checksum (auto-inserted by GMAC HW)
*
*  In our code:
*    [0..5]   -> txFrame.dstMac
*    [6..11]  -> txFrame.srcMac
*    [12..13] -> txFrame.etherType
*    [14..N]  -> txFrame.payload
*    [N+1..]  -> FCS (handled automatically by hardware)
*/

typedef struct
{
    uint8  dstMac[6];
    uint8  srcMac[6];
    uint16 etherType;
    uint8  payload[64];   /* max Ethernet payload size */
    uint16 payloadLen;
} EthFrame_t;

static void BuildEthernetFrame(Gmac_Ip_BufferType *txBuf, const EthFrame_t *frame)
{
    uint8 *ptr = txBuf->Data;

    /* Copy destination MAC */
    memcpy(ptr, frame->dstMac, 6U);
    ptr += 6U;

    /* Copy source MAC */
    memcpy(ptr, frame->srcMac, 6U);
    ptr += 6U;

    /* EtherType (big-endian) */
    *ptr++ = (uint8)((frame->etherType >> 8) & 0xFFU);
    *ptr++ = (uint8)(frame->etherType & 0xFFU);

    /* Copy payload */
    memcpy(ptr, frame->payload, frame->payloadLen);
    ptr += frame->payloadLen;

    /* Set buffer length (exclude FCS, controller appends it) */
    txBuf->Length = (uint32)(ptr - txBuf->Data);
}

int main(void) {

	Clock_Ip_Init(&Clock_Ip_aClockConfig[0]);

	/* Initialize all pins using the Port driver */
	Siul2_Port_Ip_Init(
	NUM_OF_CONFIGURED_PINS_PortContainer_0_BOARD_InitPeripherals,
			g_pin_mux_InitConfigArr_PortContainer_0_BOARD_InitPeripherals);

	EthFrame_t txFrame;

	Status = Gmac_Ip_Init(INST_GMAC_0, &Gmac_0_ConfigPB);
	DevAssert(Status == GMAC_STATUS_SUCCESS);

	Gmac_Ip_GetMacAddr(INST_GMAC_0, MacAddr_Src);

    memcpy(txFrame.srcMac, MacAddr_Src, 6U);
    memcpy(txFrame.dstMac, MacAddr_Dest, 6U);
    txFrame.etherType = 0xBB80U;
    txFrame.payloadLen = 46U;

    for (uint16 i = 0; i < txFrame.payloadLen; i++)
    {
        txFrame.payload[i] = (uint8)i;           /* dummy payload */
    }

    Status = Gmac_Ip_GetTxBuff(INST_GMAC_0, 0U, &TxBuffer, NULL_PTR);
    DevAssert(Status == GMAC_STATUS_SUCCESS);

    BuildEthernetFrame(&TxBuffer, &txFrame);

    Status = Gmac_Ip_SendFrame(INST_GMAC_0, 0U, &TxBuffer, &TxOptions);
    DevAssert(Status == GMAC_STATUS_SUCCESS);

	for (;;) {
		if (exit_code != 0) {
			break;
		}
	}
	return exit_code;
}

/** @} */
