/*
 * EEPROM.c
 *
 * Created: 11/6/2020 1:14:06 PM
 *  Author: Marino
 */ 


#include <avr/io.h>
#include "std_types.h"


void EEPROM_vWrite(u16 adress, u8 val){
while (((EECR&(1<<EEWE))>>EEWE)==1){}
EEARH=(char)(adress>>8);
EEARL=(char)adress;
EEDR=val;
EECR |=(1<<EEMWE);
EECR |=(1<<EEWE);
}


u8 EEPROM_vRead(u16 adress){
while (((EECR&(1<<EEWE))>>EEWE)==1){}
EEARH=(char)(adress>>8);
EEARL=(char)adress;
EECR |=(1<<EERE);
return EEDR;
}

