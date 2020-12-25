/*
 * SPI.h
 *
 * Created: 11/27/2020 10:13:12 AM
 *  Author: lwayo
 */ 


#ifndef SPI_H_
#define SPI_H_


void SPI_vInit_Master(void);
void SPI_vMaster_transmit (char data);
void SPI_vInit_Slave(void);
char SPI_u8Slave_recive(void);



#endif /* SPI_H_ */