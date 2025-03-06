#include "LCD.h"
#include "vars_and_const.h"
#include <MDR32FxQI_port.h>

/* definition of PORTs for LCD initialization*/
void port_LCD_ini(void)
	{
		PORT_DeInit(MDR_PORTA);
		PORT_DeInit(MDR_PORTF);
		PORT_DeInit(MDR_PORTC);

    /* Configure PORTA pins 0 (DB0) as output */
    PORT_StructInit(&PortLCD_Init);
    PortLCD_Init.PORT_Pin   = PORT_Pin_0;
    PortLCD_Init.PORT_FUNC  = PORT_FUNC_MAIN;
    PortLCD_Init.PORT_SPEED = PORT_SPEED_MAXFAST;
    PortLCD_Init.PORT_MODE  = PORT_MODE_DIGITAL;
    PortLCD_Init.PORT_OE    = PORT_OE_OUT;
    PORT_Init(MDR_PORTA, &PortLCD_Init);
	
    /* Configure PORTA pins 0 (DB0) as output */
    PortLCD_Init.PORT_Pin = PORT_Pin_1;
    PORT_Init(MDR_PORTA, &PortLCD_Init);
	
		/* Configure PORTA pins 2 (DB2) as outputt */
		PortLCD_Init.PORT_Pin = PORT_Pin_2;
    PORT_Init(MDR_PORTA, &PortLCD_Init);
	
		/* Configure PORTA pins 3 (DB3) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_3;
    PORT_Init(MDR_PORTA, &PortLCD_Init);
		
		/* Configure PORTA pins 4 (DB4) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_4;
    PORT_Init(MDR_PORTA, &PortLCD_Init);
		
		/* Configure PORTA pins 5 (DB5) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_5;
    PORT_Init(MDR_PORTA, &PortLCD_Init);

		/* Configure PORTF pins 2 (DB6) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_2;
    PORT_Init(MDR_PORTF, &PortLCD_Init);
		
		/* Configure PORTF pins 3 (DB7) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_3;
    PORT_Init(MDR_PORTF, &PortLCD_Init);	
		
		/* Configure PORTB pins 7 (E1) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_7;
    PORT_Init(MDR_PORTB, &PortLCD_Init);		
		
		/* Configure PORTB pins 8 (E2) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_8;
    PORT_Init(MDR_PORTB, &PortLCD_Init);
		
		/* Configure PORTB pins 9 (RES) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_9;
    PORT_Init(MDR_PORTB, &PortLCD_Init);
		
		/* Configure PORTB pins 10 (R/W) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_10;
    PORT_Init(MDR_PORTB, &PortLCD_Init);
		
		/* Configure PORTC pins 0 (A0) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_0;
    PORT_Init(MDR_PORTC, &PortLCD_Init);
		
		/* Configure PORTC pins 1 (E) as output */
		PortLCD_Init.PORT_Pin = PORT_Pin_1;
    PORT_Init(MDR_PORTC, &PortLCD_Init);
}
