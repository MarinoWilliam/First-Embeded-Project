/*
 * HC05_vInit.c
 *
 * Created: 11/21/2020 12:45:54 PM
 *  Author: lwayo
 */ 
#include "std_types.h"
#include <avr/io.h>
#define UART_DRIVER_H_
#include "UART_driver.h"
#include "HC05_driver.h"


void HC05_vInit  (){
	
	UART_vInit(9600);
}


void HC05_vSend(u8 data){
	UART_vSend(data);
	
}