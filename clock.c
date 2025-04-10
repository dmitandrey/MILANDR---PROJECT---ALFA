#include "clock.h"
#include <MDR32FxQI_rst_clk.h>

/* definition of CLK initialization*/
void clock_ini(void){
	  RST_CLK_DeInit();

    SystemCoreClockUpdate();

    /* Enables peripheral clocks */
    RST_CLK_PCLKcmd((	RST_CLK_PCLK_PORTB|
											RST_CLK_PCLK_PORTA|
											RST_CLK_PCLK_PORTC|
											RST_CLK_PCLK_PORTF|
											RST_CLK_PCLK_PORTE|
											RST_CLK_PCLK_UART1|
											RST_CLK_PCLK_DAC|RST_CLK_PCLK_EEPROM
										), ENABLE);
}
