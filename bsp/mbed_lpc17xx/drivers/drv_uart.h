#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

void rt_hw_uart_init(void);
void UART0_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif
