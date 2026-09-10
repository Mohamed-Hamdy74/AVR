#ifndef ADC_H_
#define ADC_H_

#include "Dio.h"

#define SPCR  *((volatile u8*)0x2D)
#define SPSR  *((volatile u8*)0x2E)
#define SPDR  *((volatile u8*)0x2F)

#define Slave  0
#define Master 1

void    SPI_init        (u8 mode);
u8      SPI_SendData    (u8 data);
u8      SPI_ReciveData  (u8 data);

#ifndef