# MBD State Machine Specification

## 목적

Failover 핵심 로직을 StateSmith 기반 MBD 상태 머신으로 정의하고, StateSmith 모델 및 자동 생성 C 코드로 이어질 수 있도록 상태, 이벤트, guard, action을 명확히 기술한다.

## StateSmith 적용 방침

- StateSmith를 failover 상태 머신의 단일 설계 원본으로 사용한다.
- 모델 원본은 `statesmith_model/`에 보관한다.
- 생성된 C 코드는 `generated_c/`에 보관하고 수동 수정하지 않는다.
- VxWorks 의존 코드는 Safety Supervisor의 platform adapter 또는 wrapper에서 처리한다.
- StateSmith 모델 변경 시 생성 코드, 단위 테스트, 추적성 매트릭스를 함께 갱신한다.

## 상태

| ID | 상태 | 설명 |
| --- | --- | --- |
| STM-ST-01 | `INIT` | Supervisor 초기화 및 ECU 통신 준비 |
| STM-ST-02 | `NORMAL` | Primary ACTIVE, Backup STANDBY |
| STM-ST-03 | `PRIMARY_FAULT_CANDIDATE` | Primary heartbeat 이상 후보 관찰 |
| STM-ST-04 | `FAILOVER_IN_PROGRESS` | Primary fault 확정 후 Backup 활성화 진행 |
| STM-ST-05 | `DEGRADED` | Backup ACTIVE로 제한 기능 지속 |
| STM-ST-06 | `RECOVERY_DETECTED` | Primary 복구 감지, 자동 failback 대기 |
| STM-ST-07 | `SAFE` | Backup 활성화 실패 또는 정상 기능 지속 불가 |

## 이벤트

| ID | 이벤트 | 설명 |
| --- | --- | --- |
| STM-EV-01 | `EV_PRIMARY_HEARTBEAT_OK` | Primary 정상 heartbeat 수신 |
| STM-EV-02 | `EV_PRIMARY_HEARTBEAT_TIMEOUT` | heartbeat timeout 발생 |
| STM-EV-03 | `EV_FAULT_CONFIRMATION_REACHED` | 연속 실패 횟수 기준 도달 |
| STM-EV-04 | `EV_BACKUP_ACTIVE_ACK` | Backup 활성화 확인 |
| STM-EV-05 | `EV_BACKUP_ACTIVATION_TIMEOUT` | Backup 활성화 timeout |
| STM-EV-06 | `EV_PRIMARY_RECOVERY_DETECTED` | Primary 복구 감지 |
| STM-EV-07 | `EV_MANUAL_FAILBACK_APPROVED` | 명시적 복귀 조건 승인 |
| STM-EV-08 | `EV_FAULT_INJECTION` | 검증용 fault 주입 |

## 전이 초안

| From | Event / Guard | To | Action |
| --- | --- | --- | --- |
| `INIT` | 통신 초기화 완료 | `NORMAL` | active owner를 Primary로 설정 |
| `NORMAL` | `EV_PRIMARY_HEARTBEAT_TIMEOUT` | `PRIMARY_FAULT_CANDIDATE` | 실패 횟수 증가, 로그 기록 |
| `PRIMARY_FAULT_CANDIDATE` | `EV_PRIMARY_HEARTBEAT_OK` | `NORMAL` | 실패 횟수 초기화 |
| `PRIMARY_FAULT_CANDIDATE` | `EV_FAULT_CONFIRMATION_REACHED` | `FAILOVER_IN_PROGRESS` | Primary fault 선언, Backup activate 요청 |
| `FAILOVER_IN_PROGRESS` | `EV_BACKUP_ACTIVE_ACK` | `DEGRADED` | active owner를 Backup으로 설정 |
| `FAILOVER_IN_PROGRESS` | `EV_BACKUP_ACTIVATION_TIMEOUT` | `SAFE` | safe state 명령, 실패 로그 기록 |
| `DEGRADED` | `EV_PRIMARY_RECOVERY_DETECTED` | `RECOVERY_DETECTED` | 자동 failback 금지, 복구 감지 로그 |
| `RECOVERY_DETECTED` | `EV_MANUAL_FAILBACK_APPROVED` | `NORMAL` | Backup standby 전환, Primary owner 복귀 |
| `DEGRADED` 또는 `RECOVERY_DETECTED` | 치명적 fault | `SAFE` | safe state 명령 |

## 설계 제약

- Primary와 Backup이 동시에 active owner가 될 수 없다.
- 단일 heartbeat 누락은 Primary fault 확정 조건이 아니다.
- Backup 활성화 요청만으로 failover 성공을 판단하지 않는다.
- Primary 복구 감지는 failback 승인과 다른 이벤트로 취급한다.

## 생성 코드 통합 원칙

| 항목 | 원칙 |
| --- | --- |
| 입력 이벤트 | heartbeat monitor, backup ack receiver, operator command adapter에서 StateSmith event로 변환 |
| 출력 action | platform-independent action 함수로 분리 후 VxWorks adapter에서 실제 명령 수행 |
| 타이머 | VxWorks timer/tick을 wrapper에서 관리하고 timeout event만 상태 머신에 전달 |
| 로그 | entry/exit/action 지점에서 Event Logger 호출 |
| 테스트 | host 기반 generated-code unit test 후 VxWorks 통합 테스트 수행 |
