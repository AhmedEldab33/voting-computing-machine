/*    
*     Created in 6/9/2023
*     By : Ahmed Eldab3
*/


#include "../LIB/Bit_utils.h"
#include "../LIB/Std_types.h"

#define F_CPU 1000000
#include "util/delay.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HALL/SSD/SSD_Interface.h"
#include "../HALL/LCD/LCD_Interface.h"
#include "../HALL/LCD/LCD_Private.h"
#include "../HALL/KPAD/KPAD_Interface.h"



int main (){

	LCD_voidIitialize();
	KPAD_voidInitialize();
	LCD_voidAddPatternsToCGRAM();

	u8 x;
	u8 a=0 , b=0, c=0 , d=0, m=0;

    while(1){
    	LCD_voidWriteCommand(Clear_Display);
    	LCD_voidGoToPosition(LINE1,0);
    	LCD_voidWriteString("Welcome to");
    	LCD_voidGoToPosition(LINE2,0);
    	LCD_voidWriteString("Voting System");

    	_delay_ms(1000);
    	LCD_voidWriteCommand(Clear_Display);

    	LCD_voidGoToPosition(LINE1,0);
    	LCD_voidWriteString("1)Ahmed");
    	LCD_voidGoToPosition(LINE1,11);
    	LCD_voidWriteString("2)Amr");
    	LCD_voidGoToPosition(LINE2,0);
    	LCD_voidWriteString("3)Omar");
    	LCD_voidGoToPosition(LINE2,10);
    	LCD_voidWriteString("4)Samy");

    	_delay_ms(1000);
    	LCD_voidWriteCommand(Clear_Display);

    	LCD_voidGoToPosition(LINE1,0);
    	LCD_voidWriteString("Ahmed=");
    	LCD_voidGoToPosition(LINE1,10);
    	LCD_voidWriteString("Amr=");
    	LCD_voidGoToPosition(LINE2,0);
    	LCD_voidWriteString("Omar=");
    	LCD_voidGoToPosition(LINE2,9);
    	LCD_voidWriteString("Samy=");
while (m==0){
    	do{
    	x = KPAD_u8GetPressed();
    	if (x==1 && x!=255){
    		a++;
    		LCD_voidGoToPosition(LINE1,6);
    		LCD_voidWriteNumber(a);
    	}else if(x==2 && x!=255){
    		b++;
    		LCD_voidGoToPosition(LINE1,14);
    		LCD_voidWriteNumber(b);
    	}else if(x==3 && x!=255){
    		c++;
    		LCD_voidGoToPosition(LINE2,5);
    		LCD_voidWriteNumber(c);
    	}else if(x==4 && x!=255){
    		d++;
    		LCD_voidGoToPosition(LINE2,14);
    		LCD_voidWriteNumber(d);
    	}
    	}while(x!=5 && x!=255);
    	if(x==5 && x!=255){
    		m++;
    	}
}

    	if (x==5 && x!=255){
    		if (a>b && a>c && a>d){
    			LCD_voidWriteCommand(Clear_Display);
    			LCD_voidGoToPosition(LINE1,0);
    			LCD_voidWriteString("Ahmed is Winner");
    			_delay_ms(1000);
    		}else if (b>a && b>c && b>d){
    			LCD_voidWriteCommand(Clear_Display);
    			LCD_voidGoToPosition(LINE1,0);
    			LCD_voidWriteString("Amr is Winner");
    			_delay_ms(1000);
    		}else if (c>a && c>b && c>d){
    			LCD_voidWriteCommand(Clear_Display);
    			LCD_voidGoToPosition(LINE1,0);
    			LCD_voidWriteString("Omar is Winner");
    			_delay_ms(1000);
    		}else if (d>a && d>c && d>b){
    			LCD_voidWriteCommand(Clear_Display);
    			LCD_voidGoToPosition(LINE1,0);
    			LCD_voidWriteString("Samy is Winner");
    			_delay_ms(1000);
    		}
    	}
    }

    return 0;
}
