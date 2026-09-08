#include "ADC.h"

extern void ADC_Init (void)
{
    SET_BIT(ADMUX_Reg,6); 
    CLR_BIT(ADMUX_Reg,7);
    
    SET_BIT(ADCSRA_Reg,7);

    CLR_BIT(ADMUX_Reg,5);

    SET_BIT(ADCSRA_Reg,2);
    SET_BIT(ADCSRA_Reg,1);
    SET_BIT(ADCSRA_Reg,0);
}


extern u16 ADC_Read (u8 channel)
{
    CLR_BIT(ADMUX_Reg,0);
    CLR_BIT(ADMUX_Reg,1);
    CLR_BIT(ADMUX_Reg,2);
    CLR_BIT(ADMUX_Reg,3);
    CLR_BIT(ADMUX_Reg,4);

    ADMUX_Reg=ADMUX_Reg|channel;
    SET_BIT(ADCSRA_Reg,6);
    while(GET_BIT(ADCSRA_Reg,ADSC));
    u16 result = (ADCL_Reg | (ADCH_Reg << 8));
    return result;
}