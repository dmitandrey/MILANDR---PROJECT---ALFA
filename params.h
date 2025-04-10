#pragma once
#include "vars_and_const.h"

typedef struct {
    uint8_t X ;
    uint8_t Y ;
		uint8_t Z ;
		uint8_t user_id;
}VOLTAGE_USERID;

extern VOLTAGE_USERID voltage_id;

VOLTAGE_USERID Load_from_EEPROM();

void Save_to_EEPROM(VOLTAGE_USERID);

