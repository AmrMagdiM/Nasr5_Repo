/*
 * SPI.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_SPI_SPI_H_
#define SRC_MCAL_SPI_SPI_H_

void SPI_Initialize(void);

uint8 SPI_SendData(DIO_PortType PortId, uint8 PortValue, uint8 Data);

uint8 SPI_DataReceived();


#endif /* SRC_MCAL_SPI_SPI_H_ */
