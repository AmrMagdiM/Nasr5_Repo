/*
 * BCDSevenSeg.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Amr
 */
#include <avr/delay.h>
#include "../../LIB/Bit_Math.h"
#include "BCDSevenSeg.h"

/* Function to initialize 7Segment component */
void BCDSevenSegment_Initialization(void){
	/* Decoder inputs are set as output pins */
	DIO_SetPinDirection(PORTA,Pin4,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin5,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin6,DIO_Output);
	DIO_SetPinDirection(PORTA,Pin7,DIO_Output);

	/* Set direction for 7segment enable pins */
	DIO_SetPinDirection(PORTB,Pin1,DIO_Output);
	DIO_SetPinDirection(PORTB,Pin2,DIO_Output);
	DIO_SetPinDirection(PORTB,Pin3,DIO_Output);
}

/* Function to write a number on 7 segment */
void BCDSevenSegment_WriteNumber(uint8 Value)
{
	uint8 SevenSegOne, SevenSegTwo;

	if (Value < 100){

		/* 53 / 10 = 5 */
		SevenSegOne = Value / 10;
		/* 53 % 10 = 3*/
		SevenSegTwo = Value % 10;

		/* Disable seven segment 1 */
		BCDSevenSegment_Disable1();
		/* Disable seven segment 2 */
		BCDSevenSegment_Disable2();

		/* 5 --> 0b 0000 0101 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 0, C = 1, D = 0 */
		/* Input Value to decoder (A, B, C, D) */
		/* Value of decoder input A */
		DIO_SetPinValue(PORTA, Pin4, GET_BIT(SevenSegOne,0));
		/* Value of decoder input B */
		DIO_SetPinValue(PORTA, Pin5, GET_BIT(SevenSegOne,1));
		/* Value of decoder input C */
		DIO_SetPinValue(PORTA, Pin6, GET_BIT(SevenSegOne,2));
		/* Value of decoder input D */
		DIO_SetPinValue(PORTA, Pin7, GET_BIT(SevenSegOne,3));

		/* Enable seven segment 1 */
		BCDSevenSegment_Enable1();

		/* 10 mSec delay */
		_delay_ms(10);

		/* Disable seven segment 1 */
		BCDSevenSegment_Disable1();

		/* 3 --> 0b 0000 0011 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 1, C = 0, D = 0 */
		/* Input Value to decoder (A, B, C, D) */
		/* Value of decoder input A */
		DIO_SetPinValue(PORTA, Pin4, GET_BIT(SevenSegTwo,0));
		/* Value of decoder input B */
		DIO_SetPinValue(PORTA, Pin5, GET_BIT(SevenSegTwo,1));
		/* Value of decoder input C */
		DIO_SetPinValue(PORTA, Pin6, GET_BIT(SevenSegTwo,2));
		/* Value of decoder input D */
		DIO_SetPinValue(PORTA, Pin7, GET_BIT(SevenSegTwo,3));

		/* Enable seven segment 2 */
		BCDSevenSegment_Enable2();

		/* 10 mSec delay */
		_delay_ms(10);



	}

}

/* Function to enable 7segment 1 */
void BCDSevenSegment_Enable1(void)
{
	/* PinB2 is High */
	DIO_SetPinValue(PORTB,Pin2,STD_HIGH);
}

/* Function to disable 7segment 1 */
void BCDSevenSegment_Disable1(void)
{
	/* PinB2 is Low */
	DIO_SetPinValue(PORTB,Pin2,STD_LOW);
}
/* Function to enable 7segment 2 */
void BCDSevenSegment_Enable2(void)
{
	/* PinB1 is High */
	DIO_SetPinValue(PORTB,Pin1,STD_HIGH);
}

/* Function to disable 7segment 2 */
void BCDSevenSegment_Disable2(void)
{
	/* PinB1 is High */
	DIO_SetPinValue(PORTB,Pin1,STD_LOW);
}

