/*
 * UART_driver.c
 *
 * Created: 11/21/2020 10:38:50 AM
 *  Author: Marino
 */ 

#include "std_types.h"
#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART_driver.h"
#define CPU_FREQ 16000000UL




void UART_vInit(u32  baud)
{
/*Set band rate in UBRRL  UBRRH*/
u16 temp =((160000/(16*96))-1);

UBRRL=(u8) temp;
UBRRH=(u8) (temp >>8);

/*choose frame (enable controlling UREC register ) (8 bit)  (one stop bit)   (no parity)*/
UCSRC = (1<<URSEL);  // clear everything else

SET_BIT(UCSRC,UCSZ0);
SET_BIT(UCSRC,UCSZ1);

/*enable interrupt reception */
UCSRB = (1<<RXCIE);    // clear everything else


/*enable UART Rx Tx*/
SET_BIT(UCSRB,TXEN);
SET_BIT(UCSRB,RXEN);
}


void UART_vSend(u8 data){
	
	while (READ_BIT(UCSRA,UDRE)==0){
		/*wait*/
	}
	UDR=data;
}


#if 0
void UART_vInit(unsigned long baud)
{
	unsigned short ubrr;
	
	/*1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH*/
	ubrr =  ( (CPU_FREQ/ (16*baud)) - 1);
	
	UBRRL = (char) ubrr;
	UBRRH = (char) (ubrr >> 8);
	
	/*3 - Choose number of data bits to be sent from UCSRC We will work with 8 bits.*/
	UCSRC = (1<<URSEL)|(1<<UCSZ0) | (1<<UCSZ1);

	UCSRB = (1<<RXCIE);
	
	/*2 - Enable UART Sender & Receiver*/
	UCSRB |= (1<<TXEN) | (1<<RXEN);
}

void UART_vSend(unsigned char val)
{
	/*Wait for Transmit buffer to be empty*/
	while( (UCSRA & (1<<UDRE)) == 0 )
	{
		
	}
	
	/*Put data to transmit buffer*/
	UDR = val;
}

#endif


