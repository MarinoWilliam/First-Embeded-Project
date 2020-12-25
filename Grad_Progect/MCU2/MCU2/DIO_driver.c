/*
 * DIO.c
 *
 * Created: 10/24/2020 11:37:13 AM
 *  Author: lwayo
 */ 


#include "std_types.h"
#include <avr/io.h>

void DIO_vSetPinDir (u8 PortName , u8 PinNumber , u8 Dir ){
	
	switch(PortName){
		case 'A':
		if (1==Dir){
			DDRA |= 1<< PinNumber;
		}
		else{
			DDRA &=~(1<<PinNumber);
		}
		break;
		
		
		case 'B':
		if (1==Dir){
			DDRB |= 1<< PinNumber;
		}
		else{
			DDRB &=~(1<<PinNumber);
		}
		break;
		
		
		case 'C':
		if (1==Dir){
			DDRC |= 1<< PinNumber;
		}
		else{
			DDRC &=~(1<<PinNumber);
		}
		break;
		
		
		case 'D':
		if (1==Dir){
			DDRD |= 1<< PinNumber;
		}
		else{
			DDRD &=~(1<<PinNumber);
		}
		break;
		
	}
	
	
}



void DIO_vWritePin (u8 PortName , u8 PinNumber , u8 val){
	switch(PortName){
		case 'A':
		if (1==val){
			PORTA |=1<<PinNumber;
		}
		else {
			PORTA &=~(1<<PinNumber);
		}
		break;
		
		case 'B':
		if (1==val){
			PORTB |=1<<PinNumber;
		}
		else {
			PORTB &=~(1<<PinNumber);
		}
		break;
		
		case 'C':
		if (1==val){
			PORTC |=1<<PinNumber;
		}
		else {
			PORTC &=~(1<<PinNumber);
		}
		break;
		
			
		case 'D':
		if (1==val){
			PORTD |=1<<PinNumber;
		}
		else {
			PORTD &=~(1<<PinNumber);
		}
		break;			
				
	}
	
	
	
}



u8 DIO_vReadPin (u8 PortName , u8 PinNumber){
	u8 val;
	
	switch(PortName){
		case 'A':
		val=(PINA&(1<<PinNumber))>>PinNumber;
		break;
		case 'B':
		val=(PINB&(1<<PinNumber))>>PinNumber;
		break;		
		case 'C':
		val=(PINC&(1<<PinNumber))>>PinNumber;
		break;	
		case 'D':
		val=(PIND&(1<<PinNumber))>>PinNumber;
		break;	
	}		
	return val;
}





void DIO_vToggle (u8 PortName , u8 PinNumber){
		
	switch(PortName){
		case 'A':
		(PORTA^=(1<<PinNumber));
		break;
		case 'B':
		(PORTB^=(1<<PinNumber));
		break;
		case 'C':
		(PORTC^=(1<<PinNumber));
		break;
		case 'D':
		(PORTD^=(1<<PinNumber));
		break;
	}
}