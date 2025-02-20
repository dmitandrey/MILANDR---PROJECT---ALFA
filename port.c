#include "port.h"
#include <MDR32FxQI_port.h>
#include "vars_and_const.h"

/* definition of PORTs initialization*/
void port_ini(void){
		PORT_DeInit(MDR_PORTB);
    PORT_DeInit(MDR_PORTD);
		PORT_DeInit(MDR_PORTE);

    /* Configure PORTB pins 5 (UART1_TX) as output */
    PORT_StructInit(&PortInit);
    PortInit.PORT_Pin   = PORT_Pin_5;
    PortInit.PORT_FUNC  = PORT_FUNC_ALTER;
    PortInit.PORT_SPEED = PORT_SPEED_MAXFAST;
    PortInit.PORT_MODE  = PORT_MODE_DIGITAL;
    PortInit.PORT_OE    = PORT_OE_OUT;
    PORT_Init(MDR_PORTB, &PortInit);
	
    /* Configure PORTB pins 6 (UART1_RX) as input */
    PortInit.PORT_Pin = PORT_Pin_6;
    PortInit.PORT_OE  = PORT_OE_IN;
    PORT_Init(MDR_PORTB, &PortInit);
		
		/* Configure PORTE pins 0 (DAC) as output */
		PortInit.PORT_Pin  = PORT_Pin_0;
		PortInit.PORT_OE   = PORT_OE_OUT;
		PortInit.PORT_MODE = PORT_MODE_ANALOG;
		PORT_Init(MDR_PORTE, &PortInit);
}