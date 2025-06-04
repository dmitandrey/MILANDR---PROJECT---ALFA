#include <MDR32FxQI_uart.h>
#include "vars_and_const.h"
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include <MDR32FxQI_dac.h>
#include "LCD.h"
#include "interrupts.h"





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