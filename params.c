#include "params.h"
#include <MDR32FxQI_eeprom.h>
#include "vars_and_const.h"

VOLTAGE_USERID voltage_id;
#define EEPROM_BASE_ADDRESS_0  0x08007000
#define EEPROM_BASE_ADDRESS_1  0x08008000
#define EEPROM_BASE_ADDRESS_2  0x08009000

void Delay(unsigned int delayTime)
{
	unsigned int i; // very important value :-)
	for (i = 0; i < delayTime; i++)
		;
}

VOLTAGE_USERID Load_from_EEPROM()
{	  
		__set_FAULTMASK(1); 
		VOLTAGE_USERID volt;
		uint32_t BankSelector;
		BankSelector = EEPROM_Main_Bank_Select;
	
		
	  volt.user_id = EEPROM_ReadByte(USER_ID_ADRESS, BankSelector);
		
	
		if  (volt.user_id ==1)
		{
	
    volt.X = EEPROM_ReadByte(VALUE_X1_ADRESS, BankSelector);
    volt.Y = EEPROM_ReadByte(VALUE_Y1_ADRESS, BankSelector);
		volt.Z = EEPROM_ReadByte(VALUE_Z1_ADRESS, BankSelector);
	
		}
		else if (volt.user_id ==2) 
		{
		
    volt.X = EEPROM_ReadByte(VALUE_X2_ADRESS, BankSelector);
    volt.Y = EEPROM_ReadByte(VALUE_Y2_ADRESS, BankSelector);
		volt.Z = EEPROM_ReadByte(VALUE_Z2_ADRESS, BankSelector);
		
		}
		
		else
		{
		volt.user_id =1;
		}
		if ((volt.X>3)|(volt.Y>9)|(volt.Z>9))
		{
		volt.X = 0;
		volt.Y = 0;
		volt.Z = 0;
		}
	__set_FAULTMASK(0);
	return volt;
	
}

void Save_to_EEPROM(VOLTAGE_USERID volt)
{	  
		__set_FAULTMASK(1);
		uint32_t BankSelector;
		BankSelector = EEPROM_Main_Bank_Select;
		
		EEPROM_ErasePage(EEPROM_BASE_ADDRESS_0, BankSelector);
		Delay(100000);
	  EEPROM_ProgramByte(USER_ID_ADRESS, BankSelector, volt.user_id);
		
			
		if  (volt.user_id ==1)
		{
		
		EEPROM_ErasePage(EEPROM_BASE_ADDRESS_1, BankSelector);
		Delay(100000);
		EEPROM_ProgramByte(VALUE_X1_ADRESS, BankSelector, volt.X);
		EEPROM_ProgramByte(VALUE_Y1_ADRESS, BankSelector, volt.Y);
		EEPROM_ProgramByte(VALUE_Z1_ADRESS, BankSelector, volt.Z);
		
		}
		else if  (volt.user_id ==2)
		{
		
		EEPROM_ErasePage(EEPROM_BASE_ADDRESS_2, BankSelector);
		Delay(100000);
		EEPROM_ProgramByte(VALUE_X2_ADRESS, BankSelector, volt.X);
		EEPROM_ProgramByte(VALUE_Y2_ADRESS, BankSelector, volt.Y);
		EEPROM_ProgramByte(VALUE_Z2_ADRESS, BankSelector, volt.Z);
		
		}
		else 
		{
		volt.user_id = 1;
		}
		__set_FAULTMASK(0); 
	}
