/*
 * LCD_drive.h
 *
 * Created: 11/7/2020 9:44:12 AM
 *  Author: Marino
 */ 


#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_

#define EN 3
#define RS 1
#define RW 2

void LCD_vInit(void);
void LCD_vSend_data(u8 data);
void LCD_vPrint(u8 * str);
void LCD_vClearScreen(void);
void LCD_vMoveCurser(u8 row , u8 column);
void LCD_vhide(void);
#endif /* LCD_DRIVE_H_ */