#include "SupervisorMbd_Port.h"

#include <stdio.h>

static SupervisorMbd_ActiveOwner g_activeOwner = SUPERVISOR_ACTIVE_OWNER_NONE;
static uint32_t g_primaryFaultCounter = 0U;
static bool g_primaryFaultDeclared = false;
static bool g_backupActivationTimerRunning = false;
static bool g_safeStateRequested = false;
static bool g_manualFailbackAllowed = false;

void SupervisorMbd_logStateEntry(const char *stateName)
{
    printf("[SUP][STATE] enter %s\n", stateName);
}

void SupervisorMbd_logTransition(const char *fromState, const char *toState)
{
    printf("[SUP][TRANSITION] %s -> %s\n", fromState, toState);
}

void SupervisorMbd_logEvent(const char *eventName)
{
    printf("[SUP][EVENT] %s\n", eventName);
}

void SupervisorMbd_setActiveOwnerPrimary(void)
{
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_PRIMARY;
    printf("[SUP][OWNER] PRIMARY\n");
}

void SupervisorMbd_setActiveOwnerBackup(void)
{
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_BACKUP;
    printf("[SUP][OWNER] BACKUP\n");
}

SupervisorMbd_ActiveOwner SupervisorMbd_getActiveOwner(void)
{
    return g_activeOwner;
}

void SupervisorMbd_resetPrimaryFaultCounter(void)
{
    g_primaryFaultCounter = 0U;
    printf("[SUP][FAULT] primary counter reset\n");
}

void SupervisorMbd_incrementPrimaryFaultCounter(void)
{
    g_primaryFaultCounter++;
    printf("[SUP][FAULT] primary counter=%lu\n", (unsigned long)g_primaryFaultCounter);
}

uint32_t SupervisorMbd_getPrimaryFaultCounter(void)
{
    return g_primaryFaultCounter;
}

void SupervisorMbd_declarePrimaryFault(void)
{
    g_primaryFaultDeclared = true;
    printf("[SUP][FAULT] primary fault declared\n");
}

bool SupervisorMbd_isPrimaryFaultDeclared(void)
{
    return g_primaryFaultDeclared;
}

void SupervisorMbd_isolatePrimary(void)
{
    printf("[SUP][CMD] primary isolate requested\n");
}

void SupervisorMbd_requestBackupActivation(void)
{
    printf("[SUP][CMD] backup activation requested\n");
}

void SupervisorMbd_requestBackupStandby(void)
{
    printf("[SUP][CMD] backup standby requested\n");
}

void SupervisorMbd_startBackupActivationTimer(void)
{
    g_backupActivationTimerRunning = true;
    printf("[SUP][TIMER] backup activation timer started\n");
}

void SupervisorMbd_stopBackupActivationTimer(void)
{
    g_backupActivationTimerRunning = false;
    printf("[SUP][TIMER] backup activation timer stopped\n");
}

bool SupervisorMbd_isBackupActivationTimerRunning(void)
{
    return g_backupActivationTimerRunning;
}

void SupervisorMbd_enterSafeState(void)
{
    g_safeStateRequested = true;
    g_activeOwner = SUPERVISOR_ACTIVE_OWNER_NONE;
    printf("[SUP][SAFE] safe state requested\n");
}

bool SupervisorMbd_isSafeStateRequested(void)
{
    return g_safeStateRequested;
}

bool SupervisorMbd_isManualFailbackAllowed(void)
{
    return g_manualFailbackAllowed;
}

void SupervisorMbd_setManualFailbackAllowed(bool allowed)
{
    g_manualFailbackAllowed = allowed;
    printf("[SUP][FAILBACK] manual failback allowed=%d\n", allowed ? 1 : 0);
}
