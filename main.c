#include <MDR32FxQI_uart.h>
#include <MDR32FxQI_port.h>
#include <MDR32FxQI_rst_clk.h>
#include <MDR32FxQI_dac.h>
#include <SEGGER_RTT.h>
#include <SEGGER_RTT_Conf.h>
#include "vars_and_const.h"

/* definitions of variables */


/* Interrupt function*/
void UART1_IRQHandler(void)
{
    if (UART_GetITStatusMasked(MDR_UART1, UART_IT_RX) == SET)
    {
        UART_ClearITPendingBit(MDR_UART1, UART_IT_RX);
				DataByte = UART_ReceiveData(MDR_UART1);
				SEGGER_RTT_printf(0,"DataByte: %d\n",DataByte);
				lvl = DataByte;
				SEGGER_RTT_printf(0,"lvl: %d\n",lvl);
				DataByte = DataByte*819;
				SEGGER_RTT_printf(0,"ChangedDataByte: %d\n",DataByte);
				if (DataByte > 4095)
				{
					DAC2_SetData(0);
					UART_SendData(MDR_UART1, E);
					UART_SendData(MDR_UART1, R);
					UART_SendData(MDR_UART1, R);
				}else
				{
					DAC2_SetData(DataByte);
					UART_SendData(MDR_UART1, lvl);	
				}
    }
}

/* Main program */
int main(void)
{
    RST_CLK_DeInit();

    /* Enable HSE clock */
    RST_CLK_HSEconfig(RST_CLK_HSE_ON);
    /* Wait HSE ready */
    while(RST_CLK_HSEstatus() == ERROR) {}
    /* Select HSE as CPU_C1 source */
    RST_CLK_CPUclkSelectionC1(RST_CLK_CPU_C1srcHSEdiv1);
    /* Select CPU_C1 as CPU_C2 source */
    RST_CLK_CPU_PLLuse(DISABLE);
    /* Select CPU_C2 as CPU_C3 source */
    RST_CLK_CPUclkSelection(RST_CLK_CPUclkCPU_C3);

    SystemCoreClockUpdate();

    /* Enables peripheral clocks */
    RST_CLK_PCLKcmd((RST_CLK_PCLK_PORTB |RST_CLK_PCLK_UART1 
			|RST_CLK_PCLK_DAC |RST_CLK_PCLK_PORTE), ENABLE);

    PORT_DeInit(MDR_PORTB);
    PORT_DeInit(MDR_PORTD);
		PORT_DeInit(MDR_PORTE);

    /* Configure PORTB pins 5 (UART1_TX) as output */
    PORT_StructInit(&PortInit);
    PortInit.PORT_Pin   = PORT_Pin_5;
    PortInit.PORT_FUNC  = PORT_FUNC_ALTER;
    PortInit.PORT_SPEED = PORT_SPEED_MAXFAST;
    PortInit.PORT_MODE  = PORT_MODE_DIGITAL;
    PortInit.PORT_OE    = PORT_OE_OUT;
    PORT_Init(MDR_PORTB, &PortInit);
	
    /* Configure PORTB pins 6 (UART1_RX) as input */
    PortInit.PORT_Pin = PORT_Pin_6;
    PortInit.PORT_OE  = PORT_OE_IN;
    PORT_Init(MDR_PORTB, &PortInit);
		
		/* Configure PORTE pins 0 (DAC) as output */
		PortInit.PORT_Pin  = PORT_Pin_0;
		PortInit.PORT_OE   = PORT_OE_OUT;
		PortInit.PORT_MODE = PORT_MODE_ANALOG;
		PORT_Init(MDR_PORTE, &PortInit);

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
		
		/* Configure DAC */	
		DAC_DeInit();
		DAC2_Init(DAC2_AVCC);
		DAC2_Cmd(ENABLE);
    while(1)
    {
			
    }
}


