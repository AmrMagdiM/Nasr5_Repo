/*
 * UART.h
 *
 *  Created on: Sep 13, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_UART_UART_H_
#define SRC_MCAL_UART_UART_H_

/* Initialize driver functionality */
void UART_Initialize(void);

/* Read data in UDR register, in case of receiving */
uint8 UART_GetChar(void);

/* Write data in UDR register, in case of transmitting */
void UART_SendChar(uint8 Data);

/* Functions to define interrupt functionality */
void UART_InterruptEnable(UART_Interrupt_Select_T Interrupt_type);

void UART_InterruptDisable(UART_Interrupt_Select_T Interrupt_type);


void _vector_13 (void) __attribute__((signal, used));

void _vector_14 (void) __attribute__((signal, used));

void _vector_15 (void) __attribute__((signal, used));

#endif /* SRC_MCAL_UART_UART_H_ */
