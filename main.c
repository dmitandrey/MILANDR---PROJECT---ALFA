#include <MDR32FxQI_uart.h>
#include <MDR32FxQI_port.h>
#include <MDR32FxQI_rst_clk.h>
#include <MDR32FxQI_dac.h>
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include "vars_and_const.h"
#include "clock.h"
#include "port.h"
#include "uart.h"
/* definitions of variables */


/* Interrupt function*/
void UART1_IRQHandler(void)
{
    if (UART_GetITStatusMasked(MDR_UART1, UART_IT_RX) == SET)
    {
        UART_ClearITPendingBit(MDR_UART1, UART_IT_RX);
				DataByte = UART_ReceiveData(MDR_UART1);
				SEGGER_RTT_printf(0,"DataByte: %d\n",DataByte);
				lvl = DataByte;
				SEGGER_RTT_printf(0,"lvl: %d\n",lvl);
				DataByte = DataByte*819;
				SEGGER_RTT_printf(0,"ChangedDataByte: %d\n",DataByte);
				if (DataByte > 4095)
				{
					DAC2_SetData(0);
					UART_SendData(MDR_UART1, E);
					UART_SendData(MDR_UART1, R);
					UART_SendData(MDR_UART1, R);
				}else
				{
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
    }
}

/* Main program */
int main(void)
{
		clock_ini();
    
		port_ini();
	
		uart_ini();
		
		/* Configure DAC */	
		DAC_DeInit();
		DAC2_Init(DAC2_AVCC);
		DAC2_Cmd(ENABLE);
    while(1)
    {
			
    }
}


