#ifndef PRIMARY_ECU_UART_H_
#define PRIMARY_ECU_UART_H_

#include "Ifx_Types.h"

void PrimaryEcu_Uart_init(void);
void PrimaryEcu_Uart_writeBytes(const uint8 *data, Ifx_SizeT length);
void PrimaryEcu_Uart_writeText(const char *text);

#endif /* PRIMARY_ECU_UART_H_ */

