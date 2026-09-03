#ifndef PRIMARY_ECU_APP_H_
#define PRIMARY_ECU_APP_H_

#include "Ifx_Types.h"

typedef enum
{
    PRIMARY_ECU_STATE_ACTIVE = 1,
    PRIMARY_ECU_STATE_ISOLATED = 2,
    PRIMARY_ECU_STATE_FAILED = 3,
    PRIMARY_ECU_STATE_RECOVERED = 4
} PrimaryEcu_State;

typedef enum
{
    PRIMARY_ECU_HEALTH_OK = 0,
    PRIMARY_ECU_HEALTH_WARN = 1,
    PRIMARY_ECU_HEALTH_FAULT = 2
} PrimaryEcu_Health;

typedef struct
{
    boolean stopHeartbeat;
    boolean forceFaultStatus;
    boolean isolateOutput;
    uint32 artificialDelayLoops;
} PrimaryEcu_FaultInjection;

typedef struct
{
    uint32 sequenceCounter;
    PrimaryEcu_State state;
    PrimaryEcu_Health health;
    PrimaryEcu_FaultInjection faultInjection;
} PrimaryEcu_Runtime;

extern volatile PrimaryEcu_Runtime g_primaryEcuRuntime;

void PrimaryEcu_init(void);
void PrimaryEcu_runPeriodic(void);
void PrimaryEcu_setIsolated(boolean isolated);

#endif /* PRIMARY_ECU_APP_H_ */

