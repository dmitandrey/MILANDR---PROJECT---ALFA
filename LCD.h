#pragma once

#define COMMAND 		(MDR_PORTC->RXTX &= ~0x1);
#define WRDATA 		(MDR_PORTC->RXTX |= 0x1);

void LCD_SendData(unsigned char sdata);
void simpleDelay(unsigned int delayTime);
void LCD_L(void);
void LCD_R(void);
void LCD_ini(void);
void LCD_WriteSymbol(unsigned char symbol);
void LCD_SetPosition(const char page, const char address);
void LCD_PrintLine(const char lineNumber, const char offset, const char interval, const char lineString[]);
void port_LCD_ini(void);
void DisplayDrawLogo(void);
void LCD_Clear(void);


