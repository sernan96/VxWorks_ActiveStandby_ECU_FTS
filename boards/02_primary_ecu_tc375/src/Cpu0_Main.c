/**********************************************************************************************************************
 * \file Cpu0_Main.c
 * \brief Primary ECU application entry point for KIT_A2G_TC375_LITE.
 *
 * This file is intended to replace the Cpu0_Main.c file in Infineon's
 * ASCLIN_UART_1_KIT_TC375_LK AURIX Development Studio example project.
 *********************************************************************************************************************/

#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "IfxStm.h"
#include "PrimaryEcu_App.h"

#define PRIMARY_ECU_PERIOD_MS       (100U)

IFX_ALIGN(4) IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void)
{
    IfxCpu_enableInterrupts();

    /* Development baseline follows Infineon's ADS examples. Re-enable watchdogs before safety evaluation. */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());

    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);

    PrimaryEcu_init();

    while (1)
    {
        PrimaryEcu_runPeriodic();
        IfxStm_waitTicks(&MODULE_STM0, IfxStm_getTicksFromMilliseconds(&MODULE_STM0, PRIMARY_ECU_PERIOD_MS));
    }
}

