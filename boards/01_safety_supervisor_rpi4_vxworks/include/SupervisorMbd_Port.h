#ifndef SUPERVISOR_MBD_PORT_H_
#define SUPERVISOR_MBD_PORT_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
    SUPERVISOR_ACTIVE_OWNER_NONE = 0,
    SUPERVISOR_ACTIVE_OWNER_PRIMARY,
    SUPERVISOR_ACTIVE_OWNER_BACKUP
} SupervisorMbd_ActiveOwner;

void SupervisorMbd_logStateEntry(const char *stateName);
void SupervisorMbd_logTransition(const char *fromState, const char *toState);
void SupervisorMbd_logEvent(const char *eventName);

void SupervisorMbd_setActiveOwnerPrimary(void);
void SupervisorMbd_setActiveOwnerBackup(void);
SupervisorMbd_ActiveOwner SupervisorMbd_getActiveOwner(void);

void SupervisorMbd_resetPrimaryFaultCounter(void);
void SupervisorMbd_incrementPrimaryFaultCounter(void);
uint32_t SupervisorMbd_getPrimaryFaultCounter(void);

void SupervisorMbd_declarePrimaryFault(void);
bool SupervisorMbd_isPrimaryFaultDeclared(void);
void SupervisorMbd_isolatePrimary(void);
void SupervisorMbd_requestBackupActivation(void);
void SupervisorMbd_requestBackupStandby(void);

void SupervisorMbd_startBackupActivationTimer(void);
void SupervisorMbd_stopBackupActivationTimer(void);
bool SupervisorMbd_isBackupActivationTimerRunning(void);
void SupervisorMbd_enterSafeState(void);
bool SupervisorMbd_isSafeStateRequested(void);

bool SupervisorMbd_isManualFailbackAllowed(void);
void SupervisorMbd_setManualFailbackAllowed(bool allowed);

#endif /* SUPERVISOR_MBD_PORT_H_ */
