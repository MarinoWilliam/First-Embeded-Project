/*
 * LCD_drive.c
 *
 * Created: 11/7/2020 9:43:53 AM
 *  Author: lwayo
 */ 

#include "std_types.h"
#include <avr/io.h>
#include "std_macros.h"
#include "LCD_drive.h"
#define F_CPU 16000000
#include <util/delay.h>

static void SendingFallingEdge (void);
static void Send_cmd (u8 cmd);
#define  LCD_4_BIT
void LCD_vDelete(void){
	Send_cmd(0x10);
	LCD_vSend_data(' ');
	Send_cmd(0x10);
}


#ifdef LCD_4_BIT
static void Send_cmd (u8 cmd){
    PORTA &=0x0f;
	PORTA|=(cmd&0xf0);
	CLR_BIT(PORTB,RS);
	SendingFallingEdge();
	PORTA &=0x0f;
	PORTA|=(cmd<<4);
	CLR_BIT(PORTB,RS);
	SendingFallingEdge();
}


void LCD_vInit(void){
	DDRB |= 0x0E;  /*set OUTPUT direction for EN, RS, RW (0000 1110)*/
	DDRA |=0xF0;            /*data pins*/
	CLR_BIT(PORTB,RW);   /*read*/
	Send_cmd(0x33); /*initialization*/
	Send_cmd(0x32);
	Send_cmd(0x28);	
	Send_cmd(0x01); /*clear screen*/
	Send_cmd(0x0f); /* blink curser*/
	_delay_ms(20);
}


void LCD_vSend_data(u8 data){
    PORTA &=0x0f;
    PORTA|=(data&0xf0);
    SET_BIT(PORTB,RS);
    SendingFallingEdge();
    PORTA &=0x0f;
    PORTA|=(data<<4);
    SET_BIT(PORTB,RS);
    SendingFallingEdge();
    
}
#else

static void Send_cmd (u8 cmd){
	/*put data on data lines*/
	PORTA =cmd;
	/*choose RS =0*/
	CLR_BIT(PORTB,RS);
	/*sendfallingedge ro enable*/
	SendingFallingEdge();
	
}
void LCD_vInit(void){
	DDRB |= 0x0E;  /*set OUTPUT direction for EN, RS, RW (0000 1110)*/
	DDRA=0xFF;            /*data pins*/
	CLR_BIT(PORTB,RW);   /*read*/
	Send_cmd(0x38); /*initialization*/
	Send_cmd(0x01); /*clear screen*/
	Send_cmd(0x0f); /* blink curser*/
	_delay_ms(20);
}



void LCD_vSend_data(u8 data){
	PORTA=data;
	SET_BIT(PORTB,RS);
	SendingFallingEdge();
}
#endif

static void SendingFallingEdge (void){
	SET_BIT(PORTB,EN);
	_delay_ms(5);
	CLR_BIT(PORTB,EN);
	_delay_ms(5);
}


void LCD_vPrint( u8 * str){
	while (*str){
		LCD_vSend_data(*str);
		str++;
	}
}

void LCD_vClearScreen(void){
	Send_cmd(0x01);
}

void LCD_vMoveCurser(u8 row , u8 column){
	u8 temp;
	if(row==0){
		temp=0x80+column;
	}
	else{
		temp=0xc0+column;
	}
	Send_cmd(temp);
}

