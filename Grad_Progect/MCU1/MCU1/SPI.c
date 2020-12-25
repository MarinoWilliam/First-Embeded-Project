/*
 * SPI.c
 *
 * Created: 11/27/2020 10:12:24 AM
 *  Author: lwayo
 */ 


#include "std_types.h"
#include "std_macros.h"
#include <avr/io.h>
#include "SPI.h"

#define  SS 4
#define  MOSI 5
#define  MISO 6
#define  SCK 7



void SPI_vInit_Master (void)
{
	
	/*master or slave ?*/
	SET_BIT(SPCR,MSTR);
	
	/*clock speed*/
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
		
	/*configure DDR ss, mosi , miso , sck */
	SET_BIT(DDRB,SS);
	SET_BIT(DDRB,MOSI);
	CLR_BIT(DDRB,MISO);
	SET_BIT(DDRB,SCK);
	
	/*make ss high (enaable the selection witg 0 in the app)*/
	
	SET_BIT(PORTB,SS);
   
   
   /*enaple SPI prepheral*/
	SET_BIT(SPCR,SPE);
}

void SPI_vMaster_transmit (char data){
	
	/*enable ss*/
	CLR_BIT(PORTB,SS);
	/*put data t SPDR*/
	SPDR=data;
	/*check transimtion is done*/
	/*won't be able to check at rhe begining because it is set to one after first */
	while (READ_BIT(SPSR,SPIF)==0){
		/*wait*/
	}
	/*close SS */
	SET_BIT(PORTB,SS);
}

void SPI_vInit_Slave (void){
	/*master or slave ?*/
	CLR_BIT(SPCR,MSTR);
	
	/*configure DDR ss, mosi , miso , sck */
	CLR_BIT(DDRB,SS);
	CLR_BIT(DDRB,MOSI);
	SET_BIT(DDRB,MISO);
	CLR_BIT(DDRB,SCK);
	
      /*enaple SPI prepheral*/
      SET_BIT(SPCR,SPE);
}


char SPI_u8Slave_recive(void){
	    	/*check transimtion is done*/
		while (READ_BIT(SPSR,SPIF)==0){
			/*wait*/
		}
		return SPDR;
	
}


