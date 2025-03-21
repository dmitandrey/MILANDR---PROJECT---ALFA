#pragma once
#include "vars_and_const.h"

#define BTNCN ((MDR_PORTC->RXTX & 0x04) == 0) // PC2 -> Button: S (SELECT / CENTER)
#define BTNUP ((MDR_PORTB->RXTX & 0x20) == 0) // PB5 -> Button: U (UP)
#define BTNDN ((MDR_PORTE->RXTX & 0x02) == 0) // PE1 -> Button: D (DOWN)
#define BTNLF ((MDR_PORTE->RXTX & 0x08) == 0) // PE3 -> Button: L (LEFT)
#define BTNRT ((MDR_PORTB->RXTX & 0x40) == 0) // PB6 -> Button: R (RIGHT)


void ButtonsHold(void);

void ButtonCentrAction(void);

void ButtonLeftAction(void);

void ButtonRightAction(void);
	
void ButtonsPolling(void);

