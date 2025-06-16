#include "port.h"
#include <MDR32FxQI_port.h>
#include "vars_and_const.h"

/* definition of PORTs initialization*/
void port_ini(void){
		PORT_DeInit(MDR_PORTB);
		PORT_DeInit(MDR_PORTE);
		PORT_DeInit(MDR_PORTA);
		PORT_DeInit(MDR_PORTF);
		PORT_DeInit(MDR_PORTC);
		PORT_DeInit(MDR_PORTD);
	
		/* Configure PORTE pins 3 for LEFT BUTTON  */
    PortInit.PORT_Pin = PORT_Pin_3;
		PortInit.PORT_MODE  = PORT_MODE_DIGITAL;
    PORT_Init(MDR_PORTE, &PortInit);

		/*Configure PORTE pins 1 for DOWN BUTTON  */
		PortInit.PORT_Pin = PORT_Pin_1;
    PORT_Init(MDR_PORTE, &PortInit);
		
		/* Configure PORTE pins 0 (DAC) as output */
		PortInit.PORT_Pin  = PORT_Pin_0;
		PortInit.PORT_OE   = PORT_OE_OUT;
		PortInit.PORT_MODE = PORT_MODE_ANALOG;
		PORT_Init(MDR_PORTE, &PortInit);
		
		/* Configure PORTE pins 7 (ADC) as input */
		PortInit.PORT_Pin  = PORT_Pin_7;
		PortInit.PORT_OE   = PORT_OE_IN;
		PortInit.PORT_MODE = PORT_MODE_ANALOG;
		PORT_Init(MDR_PORTD, &PortInit);

}