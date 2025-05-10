#include "LCD.h"
#include "vars_and_const.h"
#include <MDR32FxQI_port.h>

/* definition of PORTs for LCD initialization*/
void port_LCD_ini(void)
	{
		PORT_DeInit(MDR_PORTA);
		PORT_DeInit(MDR_PORTF);
		PORT_DeInit(MDR_PORTC);

		MDR_PORTA->OE |= 0x3F;	   // PA0...PA5 -> Output mode
		MDR_PORTA->ANALOG |= 0x3F; // PA0...PA5 -> Digital mode
		MDR_PORTA->PULL |= 0x3F;   // PA0...PA5 -> Pull-down
		MDR_PORTA->PWR |= 0xFFF;   // PA0...PA5 -> High-speed mode

		MDR_PORTB->OE |= 0x780;		// PB7...PB10 -> Output mode
		MDR_PORTB->ANALOG |= 0x7E0; // PB5...PB10 -> Digital mode
		MDR_PORTB->PULL |= 0x780;	// PB7...PB10 -> Pull-down
		MDR_PORTB->PWR |= 0x3FC000; // PB7...PB10 -> High-speed mode

		MDR_PORTC->OE |= 0x3;	  // PC0, PC1 -> Output mode
		MDR_PORTC->ANALOG |= 0x7; // PC0, PC1, PC2 -> Digital mode
		MDR_PORTC->PULL |= 0x3;	  // PC0, PC1 -> Pull-down
		MDR_PORTC->PWR |= 0x3F;	  // PC0, PC1, PC2 -> High-speed mode

		MDR_PORTF->OE |= 0xC;	  // PF3, PF2 -> Output mode
		MDR_PORTF->ANALOG |= 0xC; // PF3, PF2 -> Digital mode
		MDR_PORTF->PULL |= 0xC;	  // PF3, PF2 -> Pull-down
		MDR_PORTF->PWR |= 0xF0;	  // PF3, PF2 -> High-speed mode
		
}
