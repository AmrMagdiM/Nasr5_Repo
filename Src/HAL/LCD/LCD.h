/*
 * LCD.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Amr
 */

#ifndef SRC_HAL_LCD_LCD_H_
#define SRC_HAL_LCD_LCD_H_

void LCD_Initialize(void);
void LCD_WriteData(uint8 data);
void LCD_WriteCmd(uint8 cmd);


#endif /* SRC_HAL_LCD_LCD_H_ */
