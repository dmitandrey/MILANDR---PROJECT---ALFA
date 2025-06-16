#include "vars_and_const.h"
#include "clock.h"
#include "port.h"
#include "uart.h"
#include "dac.h"
#include "LCD.h"
#include <MDR32FxQI_dac.h>
#include "buttons.h"
#include "interrupts.h"
#include "params.h"
#include "MDR32FxQI_eeprom.h"
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include "timer.h"
#include "adc.h"

#include <stdio.h>
#include <stdint.h>


/* Interrupt function*/
void UART1_IRQHandler(void){
    if (UART_GetITStatusMasked(MDR_UART1, UART_IT_RX) == SET)
    {		
				uint8_t received = UART_ReceiveData(MDR_UART1);
        UART_ClearITPendingBit(MDR_UART1, UART_IT_RX);
				build_json();
				UART1_SendDataFIFO(data, sizeof(data) - 1);
		}
}


/* Main program */
int main(void)
{
		clock_ini();
    
		port_ini();
	
		port_LCD_ini();
	
		SysTickConfig();
		
		dac_ini();
	
		adc_ini();
	
		uart_ini();
	
		LCD_ini();
		
		LCD_Clear();
		
	
		LCD_SetPosition(0, 0);
		LCD_PrintLine(1, 10, 1, "CURRENT USER:");
		LCD_PrintLine(2, 10, 1, "CURRENT V:");
	
		__set_FAULTMASK(1);
		voltage_id = Load_from_EEPROM();
		__set_FAULTMASK(0);
		
		X = voltage_id.X;
		Y = voltage_id.Y;
		Z = voltage_id.Z;
		user_id = voltage_id.user_id;
		
		DAC2_SetData(DataByte(X,Y,Z));
		LCD_PrintLine(1, 101, 1, u8_to_str(user_id,buffer));
		LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
		LCD_PrintLine(3, 17, 1,".");
		LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
		LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
		
		mode = FIRST;
		conf = CONF;
		
		timer_ini();
		
    while(1)
    {
			ButtonsPolling();
			
			switch(mode)		
			{
				case FIRST:
					LCD_PrintLine(4, 31, 1, " ");
					LCD_PrintLine(4, 24, 1, " ");
					switch(conf)
					{
					case CONF:
						while (1)
						{	
							
							simpleDelay(100000);
							LCD_PrintLine(4, 10, 1, "^");	
							ButtonsPolling();
							simpleDelay(100000);
							LCD_PrintLine(4, 10, 1, " ");
							ButtonsPolling();
							if ((conf != CONF)|(mode != FIRST))
								break;
						}
					break;
					
				case ACCEPT:
					LCD_PrintLine(4, 10, 1, "^");
				break;
					
				}
			
			break;
///////////////////////////////////////////////////////////////

			case SECOND:
				LCD_PrintLine(4, 31, 1, " ");
				LCD_PrintLine(4, 10, 1, " ");
				switch(conf)
				{
					case CONF:
						while (1)
						{	
							
							simpleDelay(100000);
							LCD_PrintLine(4, 24, 1, "^");
							ButtonsPolling();
							simpleDelay(100000);
							LCD_PrintLine(4, 24, 1, " ");
							ButtonsPolling();
							if ((conf != CONF)|(mode != SECOND))
								break;
						}
					break;
						
					case ACCEPT:
							LCD_PrintLine(4, 24, 1, "^");
							
					break;
				}
			break;
////////////////////////////////////////////////////////////////
			case THIRD:
				LCD_PrintLine(4, 10, 1, " ");
				LCD_PrintLine(4, 24, 1, " ");
				switch(conf)
				{
					case CONF:
						while (1)
						{	
							
							simpleDelay(100000);
							LCD_PrintLine(4, 31, 1, "^");
							ButtonsPolling();
							simpleDelay(100000);
							LCD_PrintLine(4, 31, 1, " ");
							ButtonsPolling();
							if ((conf != CONF)|(mode != THIRD))
								break;
						}
					break;
						
					case ACCEPT:
							LCD_PrintLine(4, 31, 1, "^");
					
					break;
					
				}
				break;

			default:
				break;
			}
		 
    }
}


