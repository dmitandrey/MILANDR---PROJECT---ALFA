#include "stdint.h"
#include "pins.h"
#include "MDR32FxQI_port.h"

// DB0 = 1/0

void DB0(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_0);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_0);
		}
}

 // DB1 = 1/0

void DB1(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_1);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_1);
		}
}

 // DB2 = 1/0

void DB2(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_2);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_2);
		}
}

 // DB3 = 1/0

void DB3(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_3);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_3);
		}
}

 // DB4 = 1/0

void DB4(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_4);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_4);
		}
}

 // DB5 = 1/0

void DB5(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTA, PORT_Pin_5);
		}
		else
		{
			PORT_ResetBits(MDR_PORTA, PORT_Pin_5);
		}
}

 // DB6 = 1/0

void DB6(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTF, PORT_Pin_2);
		}
		else
		{
			PORT_ResetBits(MDR_PORTF, PORT_Pin_2);
		}
}

// DB7 = 1/0

void DB7(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTF, PORT_Pin_3);
		}
		else
		{
			PORT_ResetBits(MDR_PORTF, PORT_Pin_3);
		}
}

// E1 = 1/0

void E1(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTB, PORT_Pin_7);
		}
		else
		{
			PORT_ResetBits(MDR_PORTB, PORT_Pin_7);
		}
}

// E2 = 1/0

void E2(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTB, PORT_Pin_8);
		}
		else
		{
			PORT_ResetBits(MDR_PORTB, PORT_Pin_8);
		}
}

// RES = 1/0

void RES(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTB, PORT_Pin_9);
		}
		else
		{
			PORT_ResetBits(MDR_PORTB, PORT_Pin_9);
		}
}

// RW = 1/0

void RW(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTB, PORT_Pin_10);
		}
		else
		{
			PORT_ResetBits(MDR_PORTB, PORT_Pin_10);
		}
}

// A0 = 1/0

void A0(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTC, PORT_Pin_0);
		}
		else
		{
			PORT_ResetBits(MDR_PORTC, PORT_Pin_0);
		}
}

// E = 1/0

void E_(uint8_t bit)
{
		if(bit == 1)
		{
			PORT_SetBits(MDR_PORTC, PORT_Pin_1);
		}
		else
		{
			PORT_ResetBits(MDR_PORTC, PORT_Pin_1);
		}
}