#ifndef SUPERVISOR_APP_H_
#define SUPERVISOR_APP_H_

#include <stdint.h>

#include "FailoverSupervisor.h"

typedef struct
{
    FailoverSupervisor stateMachine;
    uint32_t faultConfirmationThreshold;
} SupervisorApp;

void SupervisorApp_init(SupervisorApp *app);
void SupervisorApp_onPrimaryHeartbeatOk(SupervisorApp *app);
void SupervisorApp_onPrimaryHeartbeatTimeout(SupervisorApp *app);
void SupervisorApp_onBackupActiveAck(SupervisorApp *app);
void SupervisorApp_onBackupActivationTimeout(SupervisorApp *app);
void SupervisorApp_onPrimaryRecoveryDetected(SupervisorApp *app);
void SupervisorApp_onManualFailbackApproved(SupervisorApp *app);
void SupervisorApp_onCriticalFault(SupervisorApp *app);
const char *SupervisorApp_getStateName(const SupervisorApp *app);
int SupervisorApp_runSelfTest(void);

#endif /* SUPERVISOR_APP_H_ */

