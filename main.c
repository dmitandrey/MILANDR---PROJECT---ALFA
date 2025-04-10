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

/* Interrupt function*/
/*void UART1_IRQHandler();*/


/* Main program */
int main(void)
{
	
		clock_ini();
    
		port_ini();
	
		SysTickConfig();
		/*uart_ini();*/
		
		dac_ini();
		
		port_LCD_ini();
	
		LCD_ini();
		
		LCD_Clear();
	
		LCD_SetPosition(0, 0);
		
		LCD_PrintLine(2, 10, 1, "CURRENT VOLTAGE:");
		
		voltage_id = Load_from_EEPROM();
		
		X = voltage_id.X;
		Y = voltage_id.Y;
		Z = voltage_id.Z;
		user_id = voltage_id.user_id;
		
		DAC2_SetData(DataByte(X,Y,Z));
	
		LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
		LCD_PrintLine(3, 17, 1,".");
		LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
		LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
		
		mode = FIRST;
		conf = ACCEPT;
		
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
						voltage_id.X = 0;
						voltage_id.user_id = 1;
						Save_to_EEPROM(voltage_id);
						LCD_PrintLine(4, 10, 1, "^");
						DAC2_SetData(DataByte(X,Y,Z));
						
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
							voltage_id.Y = 0;
							voltage_id.user_id = 1;
							Save_to_EEPROM(voltage_id);
							DAC2_SetData(DataByte(X,Y,Z));
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
							voltage_id.Z = 0;
							voltage_id.user_id = 1;
							Save_to_EEPROM(voltage_id);
							DAC2_SetData(DataByte(X,Y,Z));
							LCD_PrintLine(4, 31, 1, "^");
					
					break;
					
				}
				break;

			default:
				break;
			}
		 
    }
}


