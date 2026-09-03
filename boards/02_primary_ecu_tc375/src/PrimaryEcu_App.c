#include "PrimaryEcu_App.h"
#include "PrimaryEcu_Uart.h"

#define PRIMARY_ECU_FRAME_MAX_LEN   (96U)

volatile PrimaryEcu_Runtime g_primaryEcuRuntime;

static uint8 appendText(uint8 *buffer, uint8 index, const char *text)
{
    while ((text != 0) && (*text != '\0') && (index < PRIMARY_ECU_FRAME_MAX_LEN))
    {
        buffer[index] = (uint8)*text;
        index++;
        text++;
    }

    return index;
}

static uint8 appendUint32(uint8 *buffer, uint8 index, uint32 value)
{
    char digits[10];
    uint8 digitCount = 0;

    if (value == 0U)
    {
        if (index < PRIMARY_ECU_FRAME_MAX_LEN)
        {
            buffer[index] = (uint8)'0';
            index++;
        }

        return index;
    }

    while ((value > 0U) && (digitCount < sizeof(digits)))
    {
        digits[digitCount] = (char)('0' + (value % 10U));
        value /= 10U;
        digitCount++;
    }

    while ((digitCount > 0U) && (index < PRIMARY_ECU_FRAME_MAX_LEN))
    {
        digitCount--;
        buffer[index] = (uint8)digits[digitCount];
        index++;
    }

    return index;
}

static void applyFaultInjection(void)
{
    if (g_primaryEcuRuntime.faultInjection.forceFaultStatus == TRUE)
    {
        g_primaryEcuRuntime.health = PRIMARY_ECU_HEALTH_FAULT;
        g_primaryEcuRuntime.state = PRIMARY_ECU_STATE_FAILED;
    }
    else if (g_primaryEcuRuntime.faultInjection.isolateOutput == TRUE)
    {
        g_primaryEcuRuntime.health = PRIMARY_ECU_HEALTH_WARN;
        g_primaryEcuRuntime.state = PRIMARY_ECU_STATE_ISOLATED;
    }
    else
    {
        g_primaryEcuRuntime.health = PRIMARY_ECU_HEALTH_OK;
        g_primaryEcuRuntime.state = PRIMARY_ECU_STATE_ACTIVE;
    }
}

static void applyArtificialDelay(void)
{
    volatile uint32 remaining = g_primaryEcuRuntime.faultInjection.artificialDelayLoops;

    while (remaining > 0U)
    {
        remaining--;
    }
}

static void sendHeartbeat(void)
{
    uint8 frame[PRIMARY_ECU_FRAME_MAX_LEN];
    uint8 index = 0;

    index = appendText(frame, index, "HB,PRI,seq=");
    index = appendUint32(frame, index, g_primaryEcuRuntime.sequenceCounter);
    index = appendText(frame, index, ",state=");
    index = appendUint32(frame, index, (uint32)g_primaryEcuRuntime.state);
    index = appendText(frame, index, ",health=");
    index = appendUint32(frame, index, (uint32)g_primaryEcuRuntime.health);
    index = appendText(frame, index, ",fi=");
    index = appendUint32(frame, index, (uint32)g_primaryEcuRuntime.faultInjection.stopHeartbeat);
    index = appendText(frame, index, "\r\n");

    PrimaryEcu_Uart_writeBytes(frame, (Ifx_SizeT)index);
}

void PrimaryEcu_init(void)
{
    g_primaryEcuRuntime.sequenceCounter = 0U;
    g_primaryEcuRuntime.state = PRIMARY_ECU_STATE_ACTIVE;
    g_primaryEcuRuntime.health = PRIMARY_ECU_HEALTH_OK;
    g_primaryEcuRuntime.faultInjection.stopHeartbeat = FALSE;
    g_primaryEcuRuntime.faultInjection.forceFaultStatus = FALSE;
    g_primaryEcuRuntime.faultInjection.isolateOutput = FALSE;
    g_primaryEcuRuntime.faultInjection.artificialDelayLoops = 0U;

    PrimaryEcu_Uart_init();
    PrimaryEcu_Uart_writeText("PRIMARY_ECU_BOOT,KIT_A2G_TC375_LITE\r\n");
}

void PrimaryEcu_runPeriodic(void)
{
    applyFaultInjection();
    applyArtificialDelay();

    if (g_primaryEcuRuntime.faultInjection.stopHeartbeat == FALSE)
    {
        g_primaryEcuRuntime.sequenceCounter++;
        sendHeartbeat();
    }
}

void PrimaryEcu_setIsolated(boolean isolated)
{
    g_primaryEcuRuntime.faultInjection.isolateOutput = isolated;
}
