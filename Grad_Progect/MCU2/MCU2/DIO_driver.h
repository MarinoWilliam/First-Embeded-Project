/*
 * DIO_driver.h
 *
 * Created: 10/24/2020 11:03:43 AM
 *  Author: Marino
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#define OUTPUT 1
#define INPUT 0
#define SET 1
#define CLEAR 0

void DIO_vSetPinDir (u8 PortName , u8 PinNumber , u8 Dir );
void DIO_vWritePin (u8 PortName , u8 PinNumber , u8 val);
u8 DIO_vReadPin (u8 PortName , u8 PinNumber);
void DIO_vToggle (u8 PortName , u8 PinNumber);
#endif /* DIO_DRIVER_H_ */