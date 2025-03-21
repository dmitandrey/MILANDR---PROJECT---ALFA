#include "buttons.h"
#include "vars_and_const.h"
#include "LCD.h"
////////////////////////
Mode mode;
Conf conf;
char buffer[4];

void ButtonsHold(void) // the "rattle" exclusion function
{
	holdbuttons = 1;
	SysTick->CTRL |= ((unsigned int)0x00000001);
}

void ButtonsPolling(void)
{
	if (holdbuttons == 1)   // means that the button has already been pressed and the process should be completed before start new
		return;

	if (BTNUP)
	{ if (mode ==FIRST)
		{ if (X<3)
			{
				X++;
			}
			else
			{
				return;
			}
			LCD_PrintLine(3, 10, 1, " ");
			LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
		}
		if (mode ==SECOND)
		{ if ((X<3)&(Y<9))
			{
				Y++;
			}
			else if ((X==3)&(Y<3))
			{
				Y++;
				
			}
			else 
			{
				return;
			}
			LCD_PrintLine(3, 24, 1, " ");
			LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
		}
		if (mode ==THIRD)
		{ if ((X<3)&(Z<9))
			{
				Z++;
			}
			else if ((X==3)&(Y<3)&(Z<9))
			{
				Z++;
				
			}
			else 
			{
				return;
			}
			LCD_PrintLine(3, 31, 1, " ");
			LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
		}
		ButtonsHold();
		return;
	}

	if (BTNDN)
	{if (mode ==FIRST)
		{ if (X>0)
			{
				X--;
			}
			else
			{
				return;
			}
			LCD_PrintLine(3, 10, 1, " ");
			LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
		}
		if (mode ==SECOND)
		{ if (Y > 0)
			{
				Y--;
			}
			else 
			{
				return;
			}
			LCD_PrintLine(3, 24, 1, " ");
			LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
		}
		if (mode ==THIRD)
		{ if ((Z>0))
			{
				Z--;
			}
			else 
			{
				return;
			}
			LCD_PrintLine(3, 31, 1, " ");
			LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
		}
		ButtonsHold();
		return;
	}

	if (BTNCN)
	{	if (conf == ACCEPT)
		{
			conf = CONF;
		}
		else if (conf == CONF)
		{
			conf = ACCEPT;
		}
		
		ButtonsHold();
		return;
	}

	if (BTNLF)
	{ if (mode == FIRST)
		{
			mode = THIRD;
		}
		else if(mode==SECOND)
		{
			mode = FIRST;
		}
		else if(mode==THIRD)
		{
			mode = SECOND;
		}
		ButtonsHold();
		return;
	}

	if (BTNRT)
	{ if (mode == FIRST)
		{
			mode = SECOND;
		}
		else if(mode==SECOND)
		{
			mode = THIRD;
		}
		else if(mode==THIRD)
		{
			mode = FIRST;
		}
		ButtonsHold();
		return;
	}
}