#ifndef _UART_INI_H_
#define _UART_INI_H_
#include <stdint.h>

/* decloration of CLK initialization*/
void uart_ini(void);
void UART1_SendDataFIFO(uint8_t *data, uint16_t length);
void build_json(void); 
void debug(uint16_t value); 
#endif
