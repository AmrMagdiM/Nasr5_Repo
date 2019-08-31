/*
 * ADC_reg.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Amr
 */

#ifndef SRC_MCAL_ADC_ADC_REG_H_
#define SRC_MCAL_ADC_ADC_REG_H_

#define ADMUX_Reg                *((volatile uint8*) 0x27)
#define ADCSRA_Reg               *((volatile uint8*) 0x26)
#define SFIOR_Reg                *((volatile uint8*) 0x50)
#define ADCLH_Reg                *((volatile uint16*)0x24)

#endif /* SRC_MCAL_ADC_ADC_REG_H_ */
