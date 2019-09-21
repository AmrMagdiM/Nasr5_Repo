/*
 * TWI.c
 *
 *  Created on: Sep 21, 2019
 *      Author: Amr
 */
#include "../../LIB/Bit_Math.h"
#include "../../LIB/std_types.h"

#include "TWI_reg.h"
#include "TWI_types.h"
#include "TWI_config.h"
#include "TWI.h"

uint8 TWI_SlaveAddr = 0;

static volatile uint8 TWI_Tx_Buffer[TWI_TX_BUFFER_SIZE_Byte] = {0};
static volatile uint8 TWI_Tx_Buffer_Index = 0;
static volatile uint8 TWI_Tx_Buffer_Size = 0;

static volatile uint8 TWI_Rx_Buffer[TWI_RX_BUFFER_SIZE_Byte] = {0};
static uint8 TWI_Rx_Buffer_Index = 0;
static uint8 TWI_Rx_Buffer_Size = 0;




/* Send a message */
uint8 TWI_SendMsg(uint8 SlaveAddress, uint8 TxMsg[], uint8 TxMsgSize){

	uint8 i;
	uint8 result;

	if(TWI_Tx_Buffer_Size == 0)
	{
		/* Copy slave address */
		TWI_SlaveAddr = (SlaveAddress << 1); // 0b01010101 --> 0b1010101(0)
		CLEAR_BIT(TWI_SlaveAddr,0); // 0b1010101(0)

		for(i=0; i<TxMsgSize; i++)
		{
			TWI_Tx_Buffer[i] = TxMsg[i];
		}

		TWI_Tx_Buffer_Size = TxMsgSize;

		TWI_InterruptEnable();
		TWI_GenerateStartCondition();
		result = 1;
	}
	else
	{
		/* Driver busy send another data */
		result = 0;

	}

	return result;
}

/* Start reading operation */
void TWI_StartReading(uint8 SlaveAddress, uint8 RxMsgSize)
{
	if (RxMsgSize < TWI_RX_BUFFER_SIZE_Byte)
	{
		TWI_SlaveAddr = (SlaveAddress <<1);
		SET_BIT(TWI_SlaveAddr, 0); // 0b1010101(1)

		TWI_Rx_Buffer_Size = RxMsgSize;

		TWI_InterruptEnable();
		TWI_AckEnable();
		TWI_GenerateStartCondition();
	}

}


/* Get last received message */
uint8 TWI_GetLastRxMsg(uint8 RxMsg[], uint8* RxMsgSize)
{

}

void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	TWI_Status_T CurrentStatus = (TWSR_Reg & 0b11111000);
	/* Interrupt sources handling */
	switch(CurrentStatus)
	{
		case Master_Start_Condition:
		case Master_RepeatedStart_Condition:
			TWDR_Reg = TWI_SlaveAddr;
			break;

		case MasterTx_SlaveAddrWritebitTx_AckRx:
		case MasterTx_SlaveAddrWritebitTx_NotAckRx:
			TWDR_Reg = TWI_Tx_Buffer[TWI_Tx_Buffer_Index];
			TWI_Tx_Buffer_Index++;
			break;

		case MasterTx_DataTx_AckRx:
		case MasterTx_DataTx_NotAckRx:
			if (TWI_Tx_Buffer_Index < TWI_Tx_Buffer_Size)
			{
				TWDR_Reg = TWI_Tx_Buffer[TWI_Tx_Buffer_Index];
				TWI_Tx_Buffer_Index++;
			}
			else
			{
				TWI_Tx_Buffer_Index = 0;
				TWI_Tx_Buffer_Size = 0;
				TWI_GenerateStopCondition();
			}
			break;

		case MasterRx_SlaveAddrReadbitTx_AckRx:
		case MasterRx_SlaveAddrReadbitTx_NotAckRx:
			break;

		case MasterRx_DataRx_AckTx:
			if(TWI_Rx_Buffer_Index < TWI_Rx_Buffer_Size)
			{
				TWI_Rx_Buffer[TWI_Rx_Buffer_Index] =TWDR_Reg;
				TWI_Rx_Buffer_Index++;
			}
			else
			{
				TWI_AckDisable();
			}
			break;

		case MasterRx_DataRx_NotAckTx:
			TWI_GenerateStopCondition();
			break;
	}

	/* Manually clear interrupt flag by writing 1 to it */
	SET_BIT(TWCR_Reg, 7);
}
