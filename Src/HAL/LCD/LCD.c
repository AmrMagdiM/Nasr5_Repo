/*
 * LCD.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Amr
 */
/* Inclusion list */
#include "../../LIB/Bit_Math.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD_Config.h"
#include "LCD.h"


void LCD_Initialize(void)
{
	/* Initialization sequence for 4-bit mode */

	_delay_ms(30);

	/** Function set **/
	LCD_WriteCmd(0x23);
	LCD_WriteCmd(0x23);

#if (FONT == FiveTimesSeven)
	/* enable LCD with 5*7 pixels configuration */
	/* 0b1000 0000 == <No. of lines><Font (5*7/5*10)> x x x x x x */
	LCD_WriteCmd(0x80);

#elif (FONT == FiveTimesTen)
	/* enable LCD with 5*10 pixels configuration */
	LCD_WriteCmd(0xC0);
#endif

	_delay_ms(1);

	/** Display control **/
	LCD_WriteCmd(0x00);
	/* 0b 1111 0000 == 1 <Display ON/OFF> <Cursor> <Blink> x x x x */
	LCD_WriteCmd(0xF0);

	_delay_ms(1);

	/** Display Clear **/
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x01);

	_delay_ms(2);




}

void LCD_WriteData(uint8 data)
{
	/* Select type of Data (RS) = Data to be displayed (RS = 1) */
	DIO_SetPinValue(PORTB, Pin1, STD_HIGH);

	/* Select operation (R/W) --> write operation (R/W = 0) */
	DIO_SetPinValue(PORTB, Pin2, STD_LOW);


	/* Write on data pins (D0 --> D7 in 8-bit mode)
	 * Write on data pins (D4 --> D7 in 4-bit mode) */
	/* Write Most significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(data, 4));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(data, 5));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(data, 6));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(data, 7));


	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 msec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* Write least significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(data, 0));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(data, 1));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(data, 2));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(data, 3));

	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 msec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);
}


void LCD_WriteCmd(uint8 cmd)
{
	/* Select type of Data (RS) = command to be executed (RS = 0) */
	DIO_SetPinValue(PORTB, Pin1, STD_HIGH);

	/* Select operation (R/W) --> write operation (R/W = 0) */
	DIO_SetPinValue(PORTB, Pin2, STD_LOW);


	/* Write on data pins (D0 --> D7 in 8-bit mode)
	 * Write on data pins (D4 --> D7 in 4-bit mode) */
	/* Write Most significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(cmd, 4));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(cmd, 5));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(cmd, 6));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(cmd, 7));


	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 msec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* Write least significant bits of data */
	DIO_SetPinValue(PORTA, Pin4, GET_BIT(cmd, 0));
	DIO_SetPinValue(PORTA, Pin5, GET_BIT(cmd, 1));
	DIO_SetPinValue(PORTA, Pin6, GET_BIT(cmd, 2));
	DIO_SetPinValue(PORTA, Pin7, GET_BIT(cmd, 3));

	/* Apply latch (E) */
	/* Set enable pin to high */
	DIO_SetPinValue(PORTB, Pin3, STD_HIGH);
	/* wait for controller to sense enable pin (wait for more than 50 msec) */
	_delay_ms(1);
	/* Set enable pin to low */
	DIO_SetPinValue(PORTB, Pin3, STD_LOW);

	/* 3 msec delay for instruction execution time - to avoid checking the busy flag */
	_delay_ms(3);
}
