/*
 * ADC.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_

void ADC_Initialize(void);

void ADC_StartConversion(ADC_ChannelType Channel_Number);

uint16 ADC_GetResult(void);

void ADC_SetCallBack(void (*Copy_ptr) (void));

void ADC_EnableInt(void);

void ADC_DisableInt(void);

#endif /* SRC_MCAL_ADC_ADC_H_ */
