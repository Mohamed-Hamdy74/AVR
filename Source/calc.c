#include"calc.h"


u8 keypad_port;

void	calc_init (u8 portid)
{
	keypad_port = portid;
	LCD_init();
	LCD_SendString ("WELCOME");
	_delay_ms(1600);
	LCD_init();
	keypad_init(keypad_port);
}



void	calc_start ()
{

	static u8 f=0,itt[15];
	u8 button;
	button=keypad_get(keypad_port);
	
	if(button=='c'){
		LCD_init();
		f=0;
	}

	 else if((button>='0' && button<='9')  || button =='/' || button =='*' ||  button =='-' || button =='+'){
		LCD_sendChar(button);
		itt[f]=button;
		f++;
	}

	else if (button=='='){
		  if(f == 0){
        return;
	   }

		
		if(itt[0]=='*' || itt[0]=='/' || itt[f-1]=='*' || itt[f-1]=='/' || itt[f-1]=='+' || itt[f-1]=='-')
		{
			LCD_init();
			LCD_SendString("ERROR");
			_delay_ms(500);
			LCD_init();
			f=0;
		}

		else{
			s32 number=0,eq[15],fl=0;
			for(u8 i=0;i<f;i++){
				if(itt[i]>='0' && itt[i]<='9')
				{
					number = (number * 10) + (itt[i] - '0');
				}

				else{
					eq[fl]=number;
					fl++;
					eq[fl]=itt[i];
					fl++;
					number=0;
				}
				
		}
		eq[fl]=number;
		fl++;
		for (u8 i=0;i<fl; i++){

			if (eq[i]=='/'||eq[i]=='*'){
				s32 op1,op2,res;
				op1=eq[i-1];
				op2=eq[i+1];

				if(eq[i]=='*'){
					res=op1*op2;
				}

				else if(eq[i]=='/'){

					if(op2==0){
						LCD_init();
						LCD_SendString("ERROR");
						f=0;
						return;
					}

					else{

						res=op1/op2;
					}
				}
				
				eq[i-1]='c';
				eq[i]='c';
				eq[i+1]=res;
			}
		}

		s32 sum = 0;
		u8 op = '+';

		for (u8 i=0;i<fl;i++){
			
			if(eq[i]=='c'){
				continue;
			}

			if(eq[i]=='+'){
				op='+';
			}

			else if(eq[i]=='-'){
				op='-';
			}

			else{
				if(op=='+'){
					sum+=eq[i];
				}

				else if(op=='-'){
					sum-=eq[i];
				}
			}	 
		}
		LCD_WriteNumber(sum);
		}
		


	}
 }
}