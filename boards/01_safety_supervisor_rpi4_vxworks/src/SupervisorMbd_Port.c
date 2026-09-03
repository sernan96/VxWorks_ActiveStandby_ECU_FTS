#include "SupervisorMbd_Port.h"

static SupervisorMbd_ActiveOwner g_activeOwner = SUPERVISOR_ACTIVE_OWNER_NONE;
static uint32_t g_primaryFaultCounter = 0U;
static bool g_primaryFaultDeclared = false;
static bool g_backupActivationTimerRunning = false;
static bool g_safeStateRequested = false;
static bool g_manualFailbackAllowed = false;

void SupervisorMbd_logStateEntry(const char *stateName)
{
    (void)stateName;
}

void SupervisorMbd_logTransition(const char *fromState, const char *toState)
{
    (void)fromState;
    (void)toState;
}

void SupervisorMbd_logEvent(const char *eventName)
{
    (void)eventName;
}

void SupervisorMbd_setActiveOwnerPrimary(void)
{
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_PRIMARY;
}

void SupervisorMbd_setActiveOwnerBackup(void)
{
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_BACKUP;
}

SupervisorMbd_ActiveOwner SupervisorMbd_getActiveOwner(void)
{
    return g_activeOwner;
}

void SupervisorMbd_resetPrimaryFaultCounter(void)
{
    g_primaryFaultCounter = 0U;
}

void SupervisorMbd_incrementPrimaryFaultCounter(void)
{
    g_primaryFaultCounter++;
}

uint32_t SupervisorMbd_getPrimaryFaultCounter(void)
{
    return g_primaryFaultCounter;
}

void SupervisorMbd_declarePrimaryFault(void)
{
    g_primaryFaultDeclared = true;
}

void SupervisorMbd_isolatePrimary(void)
{
    /* TODO: connect to Primary ECU isolate command transport. */
}

void SupervisorMbd_requestBackupActivation(void)
{
    /* TODO: connect to Backup ECU activation command transport. */
}

void SupervisorMbd_requestBackupStandby(void)
{
    /* TODO: connect to Backup ECU standby command transport. */
}

void SupervisorMbd_startBackupActivationTimer(void)
{
    g_backupActivationTimerRunning = true;
}

void SupervisorMbd_stopBackupActivationTimer(void)
{
    g_backupActivationTimerRunning = false;
}

void SupervisorMbd_enterSafeState(void)
{
    g_safeStateRequested = true;
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_NONE;
}

bool SupervisorMbd_isManualFailbackAllowed(void)
{
    return g_manualFailbackAllowed;
}

