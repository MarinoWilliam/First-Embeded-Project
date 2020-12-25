/*
 * std_mscros.h
 *
 * Created: 11/7/2020 8:33:18 AM
 *  Author: lwayo
 */ 


#ifndef STD_MSCROS_H_
#define STD_MSCROS_H_

#define REG_SIZE 8
#define SET_BIT(reg,bit) (reg|=(1<<bit))
#define CLR_BIT(reg,bit) (reg&=~(1<<bit))
#define TOG_BIT(reg,bit) (reg^=(1<<bit))
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define ROR_BIT(reg,num) ((reg>>num)|(reg<<(REG_SIZE-num))
#define ROL_BIT(reg,num) ((reg<<num)|(reg>>(REG_SIZE-num))

#endif /* STD_MSCROS_H_ */