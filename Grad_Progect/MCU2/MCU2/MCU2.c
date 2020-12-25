/*
 * MCU2.c
 *
 * Created: 12/14/2020 3:12:40 PM
 *  Author: Marino7
 */ 

#include "std_types.h"
#include <avr/io.h>
#include "DIO_driver.h"

int main(void)
{
	SPI_vInit_Slave();
	LCD_vInit();
    
	while(1)
    {
		u8 data = SPI_u8Slave_recive();
		switch (data-48){
			case 1 :
			LCD_vClearScreen();
			LCD_vPrint("Toggle Room1");
			DIO_vToggle('C',0);
			break;
			
			case 2 :
			LCD_vClearScreen();
			LCD_vPrint("Toggle Room2");
			DIO_vToggle('C',1);
			break;			
			
			case 3 :
			LCD_vClearScreen();
			LCD_vPrint("Toggle Room3");
			DIO_vToggle('C',2);
			break;			
			
			default:
			LCD_vClearScreen();
			LCD_vPrint("Wrong Choice");
			break;
		}
        
    }
}
