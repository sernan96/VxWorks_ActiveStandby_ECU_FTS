# MBD Integration Notes

## 적용 위치

StateSmith generated C 코드는 Safety Supervisor의 failover decision layer에 통합한다.

## 이벤트 매핑

| 외부 입력 | StateSmith 이벤트 |
| --- | --- |
| Supervisor init 완료 | `EV_INIT_DONE` |
| TC375 heartbeat 정상 수신 | `EV_PRIMARY_HEARTBEAT_OK` |
| heartbeat timeout | `EV_PRIMARY_HEARTBEAT_TIMEOUT` |
| 연속 timeout 기준 도달 | `EV_FAULT_CONFIRMATION_REACHED` |
| Backup active acknowledgement 수신 | `EV_BACKUP_ACTIVE_ACK` |
| Backup activation timeout | `EV_BACKUP_ACTIVATION_TIMEOUT` |
| Primary recovery 감지 | `EV_PRIMARY_RECOVERY_DETECTED` |
| 운영자 failback 승인 | `EV_MANUAL_FAILBACK_APPROVED` |
| 치명 fault | `EV_CRITICAL_FAULT` |

## 통합 원칙

- StateSmith generated C는 `v_model/05_mbd_state_machine/generated_c/`에 둔다.
- VxWorks task는 주기적으로 input event를 만들고 generated state machine에 전달한다.
- `SupervisorMbd_Port.c`는 generated action 함수와 실제 VxWorks/transport/logging 구현 사이의 adapter 역할을 한다.
- 현재 `SupervisorMbd_Port.c`는 host test 가능한 skeleton이며, 실제 VxWorks API 연결은 후속 구현에서 수행한다.

## 다음 구현 순서

1. StateSmith CLI 설치
2. `FailoverSupervisor.plantuml`에서 C 코드 생성
3. 생성된 API 이름 확인
4. `SupervisorMbd_Port.c`의 함수명을 generated code에서 호출하는 action 이름과 맞춤
5. host unit test 작성
6. VxWorks task와 transport adapter 연결

