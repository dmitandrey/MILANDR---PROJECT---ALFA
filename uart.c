#include "uart.h"
#include <MDR32FxQI_uart.h>
#include "vars_and_const.h"

/* definition of UART initialization*/
void uart_ini(void){
		/* Configure UART */

    UART_DeInit(MDR_UART1);

    /* Set the HCLK division factor = 1 for UART1,UART2 */
    UART_BRGInit(MDR_UART1, UART_HCLKdiv1);

    NVIC_EnableIRQ(UART1_IRQn);

    /* Initialize UART_InitStructure */
    UART_InitStructure.UART_BaudRate            = 115200;
    UART_InitStructure.UART_WordLength          = UART_WordLength8b;
    UART_InitStructure.UART_StopBits            = UART_StopBits1;
    UART_InitStructure.UART_Parity              = UART_Parity_No;
    UART_InitStructure.UART_FIFOMode            = UART_FIFO_OFF;
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
