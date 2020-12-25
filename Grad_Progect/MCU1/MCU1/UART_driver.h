/*
 * UART_driver.h
 *
 * Created: 11/21/2020 10:39:02 AM
 *  Author: lwayo
 */ 






#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_


#define F_CPU 16000000

void UART_vInit (u32 baud);
void UART_vSend (u8 data);

#if 0
void UART_vInit(unsigned long baud);
void UART_vTransmit(char val);
#endif

#endif /* UART_DRIVER_H_ */