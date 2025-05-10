#include <MDR32FxQI_uart.h>
#include "vars_and_const.h"
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include <MDR32FxQI_dac.h>
#include "LCD.h"
#include "interrupts.h"


/*void UART1_IRQHandler(void){
    if (UART_GetITStatusMasked(MDR_UART1, UART_IT_RX) == SET)
    {		
				LCD_Clear();
				
        UART_ClearITPendingBit(MDR_UART1, UART_IT_RX);
				DataByte = UART_ReceiveData(MDR_UART1);
				SEGGER_RTT_printf(0,"DataByte: %d\n",DataByte);
				lvl = DataByte;
				DataByte = DataByte*819;
				if (lvl==0)
				{
					LCD_PrintLine(0, 0, 1, "LEVEL:0");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);
				}
				else if(lvl==1)
				{
					LCD_PrintLine(0, 0, 1, "LEVEL:1");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
				else if(lvl==2)
				{
					LCD_PrintLine(0, 0, 1, "LEVEL:2");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
				else if(lvl==3)
				{
					LCD_PrintLine(0, 0, 1, "LEVEL:3");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
				else if(lvl==4)
				{
					LCD_PrintLine(0, 0, 1, "LEVEL:4");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
				else if(lvl==5)
				{
					LCD_PrintLine(0, 0, 1, "Level:5");
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
				else if(lvl>5)
				{
					LCD_PrintLine(0, 0, 1, "ERROR");
					DAC2_SetData(0);
					UART_SendData(MDR_UART1, E);
					UART_SendData(MDR_UART1, R);
				}
				SEGGER_RTT_printf(0,"lvl: %d\n",lvl);
				SEGGER_RTT_printf(0,"ChangedDataByte: %d\n",DataByte);
    }	
}*/


void SysTickConfig(void)
{
	SysTick->LOAD = 0x1FFFFF;
	SysTick->CTRL = 0x06;
}

void SysTick_Handler(void)
{
		SysTick->CTRL &= ~((unsigned int)0x00000001);
		holdbuttons = 0;
}