#include "vars_and_const.h"
#include "clock.h"
#include "port.h"
#include "uart.h"
#include "dac.h"
#include "LCD.h"

/* Interrupt function*/
void UART1_IRQHandler();

/* Main program */
int main(void)
{
		clock_ini();
    
		port_ini();
	
		uart_ini();
		
		dac_ini();
		
		port_LCD_ini();
	
		LCD_ini();
	
		LCD_WriteSymbol('A');
		
		LCD_PrintLine(2, 10, 1, "HELLO");
	
    while(1)
    {
			
    }
}


