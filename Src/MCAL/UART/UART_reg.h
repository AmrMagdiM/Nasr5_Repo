/*
 * UART_reg.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_UART_UART_REG_H_
#define SRC_MCAL_UART_UART_REG_H_

#define  UDR_Reg		   (*((volatile uint8*) 0x2C)
#define  USCRA_Reg         *((volatile uint8*) 0x2B)
#define  USCRB_Reg         *((volatile uint8*) 0x2A)
#define  USCRC_Reg         *((volatile uint8*) 0x40)
#define  USART_Reg         *((volatile uint8*) 0x29)

#endif /* SRC_MCAL_UART_UART_REG_H_ */
