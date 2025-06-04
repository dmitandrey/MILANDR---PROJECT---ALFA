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
extern uint8_t user_id;
extern uint8_t id;
extern uint16_t lvl;
extern uint32_t USER_ID_ADRESS;
extern uint32_t VALUE_X1_ADRESS;
extern uint32_t VALUE_Y1_ADRESS;
extern uint32_t VALUE_Z1_ADRESS;
extern uint32_t VALUE_X2_ADRESS;
extern uint32_t VALUE_Y2_ADRESS;
extern uint32_t VALUE_Z2_ADRESS;
extern uint32_t ZERO;
extern uint32_t ONE;
extern uint32_t TWO;
extern uint8_t data[30];  
extern char buffer[4];

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