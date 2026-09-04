#include "SupervisorApp.h"

#include <stdio.h>

#include "SupervisorMbd_Port.h"

#define SUPERVISOR_DEFAULT_FAULT_CONFIRMATION_THRESHOLD (3U)

static void dispatch(SupervisorApp *app, FailoverSupervisor_EventId eventId)
{
    printf("[SUP][DISPATCH] %s\n", FailoverSupervisor_event_id_to_string(eventId));
    FailoverSupervisor_dispatch_event(&app->stateMachine, eventId);
    printf("[SUP][CURRENT] %s\n", SupervisorApp_getStateName(app));
}

void SupervisorApp_init(SupervisorApp *app)
{
    app->faultConfirmationThreshold = SUPERVISOR_DEFAULT_FAULT_CONFIRMATION_THRESHOLD;

    FailoverSupervisor_ctor(&app->stateMachine);
    FailoverSupervisor_start(&app->stateMachine);
    dispatch(app, FailoverSupervisor_EventId_EV_INIT_DONE);
}

void SupervisorApp_onPrimaryHeartbeatOk(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_PRIMARY_HEARTBEAT_OK);
}

void SupervisorApp_onPrimaryHeartbeatTimeout(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_PRIMARY_HEARTBEAT_TIMEOUT);

    if (SupervisorMbd_getPrimaryFaultCounter() >= app->faultConfirmationThreshold)
    {
        dispatch(app, FailoverSupervisor_EventId_EV_FAULT_CONFIRMATION_REACHED);
    }
}

void SupervisorApp_onBackupActiveAck(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_BACKUP_ACTIVE_ACK);
}

void SupervisorApp_onBackupActivationTimeout(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_BACKUP_ACTIVATION_TIMEOUT);
}

void SupervisorApp_onPrimaryRecoveryDetected(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_PRIMARY_RECOVERY_DETECTED);
}

void SupervisorApp_onManualFailbackApproved(SupervisorApp *app)
{
    SupervisorMbd_setManualFailbackAllowed(true);
    dispatch(app, FailoverSupervisor_EventId_EV_MANUAL_FAILBACK_APPROVED);
}

void SupervisorApp_onCriticalFault(SupervisorApp *app)
{
    dispatch(app, FailoverSupervisor_EventId_EV_CRITICAL_FAULT);
}

const char *SupervisorApp_getStateName(const SupervisorApp *app)
{
    return FailoverSupervisor_state_id_to_string(app->stateMachine.state_id);
}

int SupervisorApp_runSelfTest(void)
{
    SupervisorApp app;

    printf("[SUP][SELFTEST] start\n");
    SupervisorApp_init(&app);

    SupervisorApp_onPrimaryHeartbeatOk(&app);
    SupervisorApp_onPrimaryHeartbeatTimeout(&app);
    SupervisorApp_onPrimaryHeartbeatTimeout(&app);
    SupervisorApp_onPrimaryHeartbeatTimeout(&app);
    SupervisorApp_onBackupActiveAck(&app);
    SupervisorApp_onPrimaryRecoveryDetected(&app);
    SupervisorApp_onManualFailbackApproved(&app);

    printf("[SUP][SELFTEST] final state=%s\n", SupervisorApp_getStateName(&app));
    return 0;
}

