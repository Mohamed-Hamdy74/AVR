#include <avr/io.h>
#include <avr/delay.h>
#include "Dio.h"
#include "ADC.h"
#include "LCD.h"

#define F_CPU 16000000UL

int main(void)
{
	DIO_voidSetPortDirection(DPORTC,OUTPUT);
    LCD_init();
	ADC_Init();
	u32 av,vm;
    while (1) 
    {
	av = ADC_Read(0);
	vm = ((u32)av * 5000)/1024;
	LCD_WriteNumber(vm);
	_delay_ms(700);
	LCD_SendCommand(LCD_CLR);
	}
}

