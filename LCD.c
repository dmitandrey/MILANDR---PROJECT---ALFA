#include "MDR32FxQI_port.h"             // Drivers:PORT
#include "LCD.h"
#include "pins.h"
#include "vars_and_const.h"

// Delay
void simpleDelay(unsigned int delayTime)
{
	unsigned int i; // very important value :-)
	for (i = 0; i < delayTime; i++)
		;
}
// Display Write Function
void LCD_SendData(unsigned char sdata) 
{

	MDR_PORTA->RXTX |= (sdata & 0x3F);		  // bitwise AND with mask 00111111 -> write to PA5...PA0
	MDR_PORTF->RXTX |= ((sdata & 0xC0) >> 4); // bitwise AND with mask 11000000, shift right at 4 -> write to PF3, PF2
	simpleDelay(100);
	MDR_PORTC->RXTX |=  0x2; // Generation STROB signal (set bit PC1)
	simpleDelay(10);
	MDR_PORTC->RXTX &= ~0x2; // Reset bit PC1
	simpleDelay(400);

	MDR_PORTA->RXTX &= ~0x3F; // Reset Data Bits (PA5...PA0)
	MDR_PORTF->RXTX &= ~0xC;  // Reset Data Bits (PF3, PF2)
}

void LCD_L(void)
{
	MDR_PORTB->RXTX &= ~0x100;  // LCD E2=0 reset PB8
	MDR_PORTB->RXTX |= 0x80;    // LCD E1=1 set PB7
}

void LCD_R(void)
{
	MDR_PORTB->RXTX &= ~0x80; // 
	MDR_PORTB->RXTX |= 0x100; // 
}

void LCD_ini(void)
{

	MDR_PORTB->RXTX &= ~0x400; // LCD RW=0 -> write state (reset PB10)
	MDR_PORTB->RXTX &= ~0x200; // LCD RES=0 (reset PB9)////////////////////////////////////////////////////////////////
	simpleDelay(100);
	
	MDR_PORTB->RXTX |= 0x200; // LCD RES=1  (set PB9)
	simpleDelay(1000);

	COMMAND;
	LCD_L();
	LCD_SendData(0x3F); // COMAND Display ON (LEFT SIDE)
	simpleDelay(100);
	LCD_R();
	LCD_SendData(0x3F); // COMAND Display ON (RIGHT SIDE)
	simpleDelay(100);
}
void LCD_SetPosition(const char page, const char address)
{
	COMMAND;
	LCD_SendData(0xB8 + page);
	LCD_SendData(0x40 + address);
	WRDATA;
}

void LCD_WriteSymbol(unsigned char symbol)
{
	WRDATA;
	unsigned char font_index = (symbol > 0x20) ? (symbol - 0x20) : 0x20; //if(symbol > 0x20) {symbol - 0x20} else {0x20}
	for (unsigned char i = 0; i < 7; i++)
	{
		LCD_SendData(Font_OCR_A[font_index * 7 + i]);
	}
}

void LCD_PrintLine(const char lineNumber, const char offset, const char interval, const char lineString[])
{
	LCD_L();
	unsigned char p = 0;
	LCD_SetPosition(lineNumber, offset);
	unsigned char x = offset;
	unsigned char v = (interval > 2) ? 2 : interval;

	const char *strPtr;
	strPtr = lineString;

	unsigned char npos = 0;
	while (strPtr[npos] != '\0')
	{

		unsigned char font_index = (strPtr[npos] > 0x20) ? (strPtr[npos] - 0x20) : 0x00;

		for (unsigned int i = 0; i < (6 + v); i++)
		{
			if (x > 127)
				return;
			if (x > 63 & p == 0)
			{
				LCD_R();
				LCD_SetPosition(lineNumber, (x - 64));
				p = 1;
			}

			LCD_SendData(Font_OCR_A[font_index * 7 + i]);
			++x;
		}
		npos++;
	}
}
void DisplayDrawLogo(void)
{

	for (unsigned char y = 0; y < 8; ++y)
	{
		LCD_L();
		LCD_SetPosition(y, 0);
		unsigned char p = 0;

		for (unsigned char x = 0; x < 128; ++x)
		{
			if (x > 63 & p == 0)
			{
				LCD_R();
				LCD_SetPosition(y, 0);
				p = 1;
			}
			LCD_SendData(Logo[y * 128 + x]);
		}
	}
}

void LCD_Clear(void)
{

	for (unsigned int E = 0; E < 2; E++)
	{
		if (E == 0)
			LCD_L();
		if (E == 1)
			LCD_R();

		for (unsigned int p = 0; p < 8; p++)
		{
			COMMAND;
			LCD_SendData(0xB8 + p);
			LCD_SendData(0x40);
			WRDATA;

			for (unsigned int i = 0; i < 64; i++)
			{
				LCD_SendData(0x00);
			}
		}
	}
}