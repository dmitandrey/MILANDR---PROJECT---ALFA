#ifndef _LIBS_FOR_PROJECT_
#define _LIBS_FOR_PROJECT_

#include "MDR32FxQI_port.h"
#include "MDR32FxQI_uart.h"

/* declaration of const for ASCII */
extern const uint8_t E;
extern const uint8_t R;

/* declaration of variable for DAC*/
extern uint8_t X;
extern uint8_t Y;
extern uint8_t Z;
extern uint16_t lvl;

/* declaration of stucts*/
extern PORT_InitTypeDef PortInit;
extern UART_InitTypeDef UART_InitStructure;
extern PORT_InitTypeDef PortLCD_Init;

extern const unsigned char Font_OCR_A[];

extern int holdbuttons;

typedef enum {
    FIRST = 0,
    SECOND = 1,
    THIRD = 2,
} Mode;

typedef enum {
    CONF = 0,
    ACCEPT= 1,
} Conf;

extern Conf conf;
extern Mode mode;

char* u8_to_str(uint8_t value, char* buffer);

#endif