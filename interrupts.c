#include <MDR32FxQI_uart.h>
#include "vars_and_const.h"
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include <MDR32FxQI_dac.h>

void UART1_IRQHandler(void){
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