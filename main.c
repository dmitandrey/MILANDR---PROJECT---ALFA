#include "vars_and_const.h"
#include "clock.h"
#include "port.h"
#include "uart.h"
#include "dac.h"

/* Interrupt function*/
void UART1_IRQHandler();

/* Main program */
int main(void)
{
		clock_ini();
    
		port_ini();
	
		uart_ini();
		
		dac_ini();
	
    while(1)
    {
			
    }
}


