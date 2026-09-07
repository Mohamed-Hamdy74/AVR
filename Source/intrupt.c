 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Dio.h"
#include "intrupt.h"
void initExternalInterupts(void)
{
    SET_BIT   (SREG,7);
    CLEAR_BIT (MCUCR,ISC01);
    SET_BIT   (MCUCR,ISC00);
    CLEAR_BIT (MCUCR,ISC11);
    SET_BIT   (MCUCR,ISC10);
    SET_BIT   (GICR,INT0);
    SET_BIT   (GICR,INT1);
}

