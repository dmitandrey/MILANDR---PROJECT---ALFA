#include "MDR32FxQI_timer.h"
#include "uart.h"
#include "MDR32FxQI_uart.h"
#include "vars_and_const.h"
#include "adc.h"

void timer_ini(void){
	TIMER_CntInitTypeDef timer_struct;
	
	TIMER_BRGInit(MDR_TIMER1,TIMER_HCLKdiv1);
	
	TIMER_CntStructInit(&timer_struct);
	
	timer_struct.TIMER_IniCounter = 0;
	timer_struct.TIMER_Prescaler = 7999; //8MHz/8000
	timer_struct.TIMER_Period = 999;
	
	TIMER_CntInit(MDR_TIMER1, &timer_struct);
	
	NVIC_EnableIRQ(Timer1_IRQn);
	TIMER_ITConfig(MDR_TIMER1,TIMER_STATUS_CNT_ARR,ENABLE);
	
	TIMER_Cmd(MDR_TIMER1,ENABLE);
}

void Timer1_IRQHandler()
{
		if (TIMER_GetITStatus(MDR_TIMER1, TIMER_STATUS_CNT_ARR)== SET)
		{
			TIMER_ClearITPendingBit(MDR_TIMER1, TIMER_STATUS_CNT_ARR);
			if(user_id == last_user_id)
				{
					UART_SendData(MDR_UART1, user_id + 0x30);
				}
			else
				{ 
					uint16_t adc_volt = ADC_ReadChannel();
					debug(adc_volt); 
					float_voltage = (adc_volt/(float)4095)* 3.29;
					build_json();
					UART1_SendDataFIFO(data, sizeof(data) - 1);
				}
			last_user_id = user_id;
		}
}