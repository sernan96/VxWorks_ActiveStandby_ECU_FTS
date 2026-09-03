#include "PrimaryEcu_Uart.h"

#include "IfxAsclin_Asc.h"
#include "IfxCpu.h"
#include "IfxCpu_Irq.h"

#define PRIMARY_ECU_UART_BAUDRATE       (115200U)
#define PRIMARY_ECU_UART_RX_BUFFER_SIZE (128U)
#define PRIMARY_ECU_UART_TX_BUFFER_SIZE (128U)
#define INTPRIO_ASCLIN1_RX              (18U)
#define INTPRIO_ASCLIN1_TX              (19U)

/* Default pins follow Infineon's ASCLIN_UART_1_KIT_TC375_LK example.
 * Change these macros after confirming the external UART wiring to the Safety Supervisor.
 */
#define PRIMARY_ECU_UART_PIN_RX         IfxAsclin1_RXB_P15_5_IN
#define PRIMARY_ECU_UART_PIN_TX         IfxAsclin1_TX_P15_5_OUT

static IfxAsclin_Asc g_primaryEcuAscHandle;
static uint8 g_primaryEcuTxBuffer[PRIMARY_ECU_UART_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8U];
static uint8 g_primaryEcuRxBuffer[PRIMARY_ECU_UART_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8U];

IFX_INTERRUPT(primaryEcuAsclin1TxISR, 0, INTPRIO_ASCLIN1_TX);
void primaryEcuAsclin1TxISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_primaryEcuAscHandle);
}

IFX_INTERRUPT(primaryEcuAsclin1RxISR, 0, INTPRIO_ASCLIN1_RX);
void primaryEcuAsclin1RxISR(void)
{
    IfxAsclin_Asc_isrReceive(&g_primaryEcuAscHandle);
}

void PrimaryEcu_Uart_init(void)
{
    IfxAsclin_Asc_Config ascConfig;

    IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN1);

    ascConfig.baudrate.baudrate = PRIMARY_ECU_UART_BAUDRATE;
    ascConfig.interrupt.txPriority = INTPRIO_ASCLIN1_TX;
    ascConfig.interrupt.rxPriority = INTPRIO_ASCLIN1_RX;
    ascConfig.interrupt.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

    ascConfig.txBuffer = &g_primaryEcuTxBuffer;
    ascConfig.txBufferSize = PRIMARY_ECU_UART_TX_BUFFER_SIZE;
    ascConfig.rxBuffer = &g_primaryEcuRxBuffer;
    ascConfig.rxBufferSize = PRIMARY_ECU_UART_RX_BUFFER_SIZE;

    const IfxAsclin_Asc_Pins pins =
    {
        NULL_PTR, IfxPort_InputMode_pullUp,
        &PRIMARY_ECU_UART_PIN_RX, IfxPort_InputMode_pullUp,
        NULL_PTR, IfxPort_OutputMode_pushPull,
        &PRIMARY_ECU_UART_PIN_TX, IfxPort_OutputMode_pushPull,
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };

    ascConfig.pins = &pins;

    IfxAsclin_Asc_initModule(&g_primaryEcuAscHandle, &ascConfig);
}

void PrimaryEcu_Uart_writeBytes(const uint8 *data, Ifx_SizeT length)
{
    Ifx_SizeT count = length;

    if ((data != 0) && (length > 0))
    {
        IfxAsclin_Asc_write(&g_primaryEcuAscHandle, (void *)data, &count, TIME_INFINITE);
    }
}

void PrimaryEcu_Uart_writeText(const char *text)
{
    Ifx_SizeT length = 0;

    while ((text[length] != '\0') && (length < 255))
    {
        length++;
    }

    PrimaryEcu_Uart_writeBytes((const uint8 *)text, length);
}

