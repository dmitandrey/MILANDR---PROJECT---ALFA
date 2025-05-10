#include "dac.h"
#include <MDR32FxQI_dac.h>

/* definition of DAC initialization*/
void dac_ini(void){
		/* Configure DAC */	
		DAC_DeInit();
		DAC2_Init(DAC2_AVCC);
		DAC2_Cmd(ENABLE);
}
uint32_t DataByte(uint8_t X, uint8_t Y, uint8_t Z)
{
	uint32_t databyte;
	databyte = 4095*(1*X + 0.1*Y +0.01*Z)/3.29;
	return databyte;
}

