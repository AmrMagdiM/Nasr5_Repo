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










void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	/* Interrupt sources handling */

	/* Manually clear interrupt flag by writing 1 to it */
}
