#include "clock.h"
#include <MDR32FxQI_rst_clk.h>

/* definition of CLK initialization*/
void clock_ini(void){
	  RST_CLK_DeInit();

    /* Enable HSE clock */
    RST_CLK_HSEconfig(RST_CLK_HSE_ON);
    /* Wait HSE ready */
    while(RST_CLK_HSEstatus() == ERROR) {}
    /* Select HSE as CPU_C1 source */
    RST_CLK_CPUclkSelectionC1(RST_CLK_CPU_C1srcHSEdiv1);
    /* Select CPU_C1 as CPU_C2 source */
    RST_CLK_CPU_PLLuse(DISABLE);
    /* Select CPU_C2 as CPU_C3 source */
    RST_CLK_CPUclkSelection(RST_CLK_CPUclkCPU_C3);

    SystemCoreClockUpdate();

    /* Enables peripheral clocks */
    RST_CLK_PCLKcmd((RST_CLK_PCLK_PORTB |RST_CLK_PCLK_UART1 
			|RST_CLK_PCLK_DAC |RST_CLK_PCLK_PORTE), ENABLE);
}
