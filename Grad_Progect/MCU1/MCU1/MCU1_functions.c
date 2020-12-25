/*
 * MCU1_functions.c
 *
 * Created: 12/24/2020 7:56:38 PM
 *  Author: Marino
 */ 

#include "std_types.h"
#include <avr/io.h>
#include "HC05_driver.h"
#include "SPI.h"
#include <avr/interrupt.h>
#include "EEPROM.h"
#define F_CPU 16000000
#include <util/delay.h>
#include "MCU1_functions.h"


volatile extern u8 data_recived;
volatile extern u8 rxdata;

void System_Init (){
		HC05_vInit();
		SPI_vInit_Master();
		sei();
		LCD_vInit();	
}



void Set_Password(){
		EEPROM_vWrite(0x00,1);
		EEPROM_vWrite(0x01,2);
		EEPROM_vWrite(0x02,3);
		EEPROM_vWrite(0x03,4);
}


u8 Pass_Check (){
	u8 valid=1;
		LCD_vClearScreen();
		LCD_vPrint("Password");
		LCD_vMoveCurser(1,0);
		
		u8*p2 = 0x04;
		for(u8 i=0;i<4;i++){
		while (data_recived==0){}
		data_recived=0;
		EEPROM_vWrite(p2,rxdata-48);
		LCD_vSend_data(rxdata);
		_delay_ms(250);
		LCD_vhide();
		++p2;
	}
	u8* p1 =0x00;
	p2 =0x04;
	for(u8 i=0;i<4;i++){
		if(EEPROM_vRead(p1)!=EEPROM_vRead(p2)){
			valid=0;
			break;
		}
		p1++;
		p2++;
	}
	
	if (valid!=1){
		LCD_vClearScreen();
		LCD_vPrint("Access Denied");
	}
	else {
		LCD_vClearScreen();
		LCD_vPrint("Welcome");
	}
	
	_delay_ms(1000);
	
	
	return valid ;
}