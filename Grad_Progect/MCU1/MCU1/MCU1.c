/*
 * MCU1.c
 *
 * Created: 12/14/2020 10:15:07 AM
 *  Author: Marino
 */ 

#include "std_types.h"
#include <avr/io.h>
#include "SPI.h"
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>


volatile u8 data_recived=0;
volatile u8 rxdata=0;

u8 pass=0;

int main(void)
{
	System_Init();
	Set_Password();
	
	do
	{	
		pass=Pass_Check();	
	}
	while (pass!=1);
 
	LCD_vClearScreen();
	LCD_vPrint("Choose a Room");
	_delay_ms(500);
	LCD_vClearScreen();

    while(1)
    {
		

        if(data_recived==1){
	        data_recived=0;	
	        SPI_vMaster_transmit(rxdata);
        }
    }
}


ISR(USART_RXC_vect){
	data_recived=1;
	rxdata=UDR;
}



