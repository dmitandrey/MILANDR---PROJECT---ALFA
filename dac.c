#include "dac.h"
#include <MDR32FxQI_dac.h>

/* definition of DAC initialization*/
void dac_ini(void){
		/* Configure DAC */	
		DAC_DeInit();
		DAC2_Init(DAC2_AVCC);
		DAC2_Cmd(ENABLE);
}