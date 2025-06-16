#include "MDR32FxQI_adc.h"
#include "adc.h"

void adc_ini()
{
	ADC_DeInit();
	
	ADC_InitTypeDef adc_struct;
	adc_struct.ADC_IntVRefConversion = ADC_VREF_CONVERSION_Disable;
	adc_struct.ADC_TempSensor = ADC_TEMP_SENSOR_Disable;
	ADC_Init(&adc_struct);
	
	ADCx_InitTypeDef adc1_init;
	
  ADCx_StructInit(&adc1_init);  
  adc1_init.ADC_ChannelNumber = ADC_CH_ADC7;        
  adc1_init.ADC_Channels = ADC_CH_ADC7_MSK;        
  adc1_init.ADC_Prescaler = ADC_CLK_div_64;          
  adc1_init.ADC_VRefSource = ADC_VREF_SOURCE_INTERNAL; 
  adc1_init.ADC_LevelControl = ADC_LEVEL_CONTROL_Disable;
  adc1_init.ADC_SamplingMode = ADC_SAMPLING_MODE_SINGLE_CONV;
  adc1_init.ADC_ChannelSwitching = ADC_CH_SWITCHING_Disable;
  ADC1_Init(&adc1_init);
	
	ADC1_Cmd(ENABLE);
}

uint16_t ADC_ReadChannel(void)
{
    ADC1_Start();

    while (ADC1_GetFlagStatus(ADCx_FLAG_END_OF_CONVERSION) == RESET);

    uint32_t result = ADC1_GetResult();

    return (uint16_t)result; 
}