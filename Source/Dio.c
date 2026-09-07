#include"Dio.h"
#include"std_types.h"
void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction){
    if(Direction == INPUT){
        switch(PortId){
            case DPORTA:DDRA = 0b00000000;break;
            case DPORTB:DDRB = 0b00000000;break;
            case DPORTC:DDRC = 0b00000000;break;
            case DPORTD:DDRD = 0b00000000;break;

        }
        
    }
    else if (Direction == OUTPUT){
        switch(PortId){
            case DPORTA:DDRA = 0b11111111 ;break;
            case DPORTB:DDRB = 0b11111111;break;
            case DPORTC:DDRC = 0b11111111;break;
            case DPORTD:DDRD = 0b11111111;break;

        }
    }    
}
void	DIO_voidSetPinValue			(u8 PortId,u8 PinId,u8 Value){
         if(Value == LOW){
        switch(PortId){
            case DPORTA:CLR_BIT(PORTA,PinId);break;
            case DPORTB:CLR_BIT(PORTB,PinId);break;
            case DPORTC:CLR_BIT(PORTC,PinId);break;
            case DPORTD:CLR_BIT(PORTD,PinId);break;

        }
    }
    else if (Value == HIGH){
        switch(PortId){
             case DPORTA:SET_BIT(PORTA,PinId);break;
             case DPORTB:SET_BIT(PORTB,PinId);break;
             case DPORTC:SET_BIT(PORTC,PinId);break;
             case DPORTD:SET_BIT(PORTD,PinId);break;

        }
    }    
}
void	DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction){
     if(Direction == INPUT){
        switch(PortId){
            case DPORTA:CLR_BIT(DDRA,PinId);break;
            case DPORTB:CLR_BIT(DDRB,PinId);break;
            case DPORTC:CLR_BIT(DDRC,PinId);break;
            case DPORTD:CLR_BIT(DDRD,PinId);break;

        }
    }
    else if (Direction == OUTPUT){
        switch(PortId){
             case DPORTA:SET_BIT(DDRA,PinId);break;
             case DPORTB:SET_BIT(DDRB,PinId);break;
             case DPORTC:SET_BIT(DDRC,PinId);break;
             case DPORTD:SET_BIT(DDRD,PinId);break;

        }
    }    
}
u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId){
    switch(PortId){
        case DPORTA:return GET_BIT(PINA,PinId);break;
        case DPORTB:return GET_BIT(PINB,PinId);break;
        case DPORTC:return GET_BIT(PINC,PinId);break;
        case DPORTD:return GET_BIT(PIND,PinId);break;
    }
}
void	DIO_voidSetPortValue		(u8 PortId,u8 Value){
	switch(PortId)
	{
		case DPORTA:
		PORTA = Value;
		break;

		case DPORTB:
		PORTB = Value;
		break;

		case DPORTC:
		PORTC = Value;
		break;

		case DPORTD:
		PORTD = Value;
		break;
	}    
}