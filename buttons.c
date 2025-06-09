#include "buttons.h"
#include "vars_and_const.h"
#include "LCD.h"
#include "params.h"
#include "MDR32FxQI_dac.h"
#include "dac.h"
#include "MDR32FxQI_eeprom.h"
#include "stdint.h"
#include "uart.h"
////////////////////////
Mode mode;
Conf conf;

#define EEPROM_BASE_ADDRESS_0  0x08007000
#define EEPROM_BASE_ADDRESS_1  0x08008000
#define EEPROM_BASE_ADDRESS_2  0x08009000

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
	{if (conf == CONF)
		 {
				if (mode ==FIRST )
						{ 
							if (X<3)
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
						{
							if ((X<3)&(Y<9))
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
					{ 	
							if ((X<3)&(Z<9))
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
			}
		if (conf == ACCEPT)
		{
			if (user_id == 1)
			{	
				__set_FAULTMASK(1);
				user_id = 2;
				EEPROM_ErasePage(EEPROM_BASE_ADDRESS_0, EEPROM_Main_Bank_Select);
				simpleDelay(100000);
				EEPROM_ProgramByte(USER_ID_ADRESS, EEPROM_Main_Bank_Select, user_id);
				
				LCD_PrintLine(1, 101, 1, u8_to_str(user_id,buffer));
				
				voltage_id = Load_from_EEPROM();
		
				X = voltage_id.X;
				Y = voltage_id.Y;
				Z = voltage_id.Z;
				
				__set_FAULTMASK(0);
				
				DAC2_SetData(DataByte(X,Y,Z));
				LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
				LCD_PrintLine(3, 17, 1,".");
				LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
				LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
			}			
		}
		ButtonsHold();
		return;
	}

	if (BTNDN)
	{
			if (conf == CONF)
			{
						if (mode ==FIRST)
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
				}
		if (conf == ACCEPT)
		{
			if (user_id == 2)
			{
				__set_FAULTMASK(1);
				user_id = 1;
				EEPROM_ErasePage(EEPROM_BASE_ADDRESS_0, EEPROM_Main_Bank_Select);
				simpleDelay(100000);
				EEPROM_ProgramByte(USER_ID_ADRESS, EEPROM_Main_Bank_Select, user_id);
				
				LCD_PrintLine(1, 101, 1, u8_to_str(user_id,buffer));
				voltage_id = Load_from_EEPROM();
		
				X = voltage_id.X;
				Y = voltage_id.Y;
				Z = voltage_id.Z;
				
				__set_FAULTMASK(0);
				
				DAC2_SetData(DataByte(X,Y,Z));
				LCD_PrintLine(3, 10, 1,u8_to_str(X,buffer));
				LCD_PrintLine(3, 17, 1,".");
				LCD_PrintLine(3, 24, 1,u8_to_str(Y,buffer));
				LCD_PrintLine(3, 31, 1,u8_to_str(Z,buffer));
			}
		}
		ButtonsHold();
		return;
	}

	if (BTNCN)
	{	if (conf == ACCEPT)
		{
			conf = CONF;
			LCD_PrintLine(2, 101, 1, " ");
		}
		else if (conf == CONF)
		{
			conf = ACCEPT;
			LCD_PrintLine(2, 101, 1, "^");
			voltage_id.X = X;
			voltage_id.Y = Y;
			voltage_id.Z = Z;
			voltage_id.user_id = user_id;
			Save_to_EEPROM(voltage_id);
			DAC2_SetData(DataByte(X,Y,Z));
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