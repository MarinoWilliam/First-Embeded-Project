/*
 * EEPROM.h
 *
 * Created: 11/6/2020 1:14:39 PM
 *  Author: Marino
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_vWrite(u16 adress, u8 vall);
u8 EEPROM_vRead(u16 adress);


#endif /* EEPROM_H_ */