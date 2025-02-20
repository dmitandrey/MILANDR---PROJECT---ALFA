#ifndef _LIBS_FOR_PROJECT_
#define _LIBS_FOR_PROJECT_

#include "MDR32FxQI_port.h"
#include "MDR32FxQI_uart.h"

/* declaration of const for ASCII */
extern const uint8_t E;
extern const uint8_t R;

/* declaration of variable for main*/
extern uint16_t lvl;
extern uint16_t DataByte;

/* declaration of stucts*/
extern PORT_InitTypeDef PortInit;
extern UART_InitTypeDef UART_InitStructure;

#endif