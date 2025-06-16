#include "uart.h"
#include <MDR32FxQI_uart.h>
#include "vars_and_const.h"
#include <stdio.h>
#include <stdint.h>

/* definition of UART initialization*/
void uart_ini(void){
		/* Configure UART */

    UART_DeInit(MDR_UART1);

    /* Set the HCLK division factor = 1 for UART1,UART2 */
    UART_BRGInit(MDR_UART1, UART_HCLKdiv1);

    NVIC_EnableIRQ(UART1_IRQn);
		NVIC_ClearPendingIRQ(UART1_IRQn);

    /* Initialize UART_InitStructure */
    UART_InitStructure.UART_BaudRate            = 115200;
    UART_InitStructure.UART_WordLength          = UART_WordLength8b;
    UART_InitStructure.UART_StopBits            = UART_StopBits1;
    UART_InitStructure.UART_Parity              = UART_Parity_No;
    UART_InitStructure.UART_FIFOMode            = UART_FIFO_ON;
    UART_InitStructure.UART_HardwareFlowControl = (UART_HardwareFlowControl_RXE |
                                                    UART_HardwareFlowControl_TXE);

    /* Configure UART1 parameters*/
    UART_Init(MDR_UART1,&UART_InitStructure);

    /* Enable transmitter interrupt (UARTTXINTR)
    UART_ITConfig(MDR_UART1, UART_IT_TX, ENABLE);*/

    /* Enable Receiver interrupt*/
    UART_ITConfig(MDR_UART1, UART_IT_RX, ENABLE);

    /* Enables UART2 peripheral */
    UART_Cmd(MDR_UART1, ENABLE);
}

void build_json(void) 
{
    //snprintf((char*)data, sizeof(data), "\r\n{\"user\": \"%d\", \"Volt\": \"%d.%d%d\"}\r\n",user_id, X,Y,Z);
		snprintf((char*)data, sizeof(data), 
        "\r\n{\"user\": \"%d\", \"Volt\": \"%.2f\"}\r\n",user_id, float_voltage);
}
void debug(uint16_t value) 
{
	uint8_t data_debug[20];
	snprintf((char*)data_debug, sizeof(data_debug), 
        "\r\n\"debug\": \"%d\" \r\n",value);
	UART1_SendDataFIFO(data_debug, sizeof(data_debug) - 1);
}

void UART1_SendDataFIFO(uint8_t *data, uint16_t length) 
{
    for (uint16_t i = 0; i < length; i++) {
        while (UART_GetFlagStatus(MDR_UART1, UART_FLAG_TXFF) == SET);
        UART_SendData(MDR_UART1, data[i]);
    }
}