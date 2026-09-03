# System Requirements Specification

## 범위

사용자 요구사항을 시스템 수준 요구사항으로 구체화한다. 정량값은 초기값이며 실제 보드 bring-up 후 측정 결과에 따라 기준선을 갱신한다.

## 시스템 상태

| 상태 | Primary ECU | Backup ECU | 설명 |
| --- | --- | --- | --- |
| `INIT` | UNKNOWN | UNKNOWN | 초기화 및 통신 확인 |
| `NORMAL` | ACTIVE | STANDBY | Primary ECU 주 기능 수행 |
| `FAILOVER_IN_PROGRESS` | FAILED 또는 ISOLATING | ACTIVATING | Backup ECU 전환 수행 중 |
| `DEGRADED` | FAILED 또는 ISOLATED | ACTIVE | Backup ECU로 제한 기능 지속 |
| `RECOVERY_DETECTED` | RECOVERED | ACTIVE | Primary ECU 복구 감지, 자동 failback 금지 |
| `SAFE` | FAILED | FAILED 또는 UNAVAILABLE | 정상 기능 지속 불가, 안전 상태 |

## 시스템 요구사항

| ID | 요구사항 | 상위 요구사항 |
| --- | --- | --- |
| SR-01 | 시스템은 `NORMAL` 상태에서 Primary ECU만 주 기능을 수행하도록 제어해야 한다. | UR-01, UR-09 |
| SR-02 | Safety Supervisor는 Primary ECU heartbeat를 주기적으로 수신하고 마지막 정상 수신 시각을 관리해야 한다. | UR-02 |
| SR-03 | Safety Supervisor는 연속 `N`회 heartbeat 누락 또는 health status fault가 확인된 경우 Primary ECU fault를 선언해야 한다. | UR-03, UR-04 |
| SR-04 | `N` 값과 heartbeat timeout은 설정 가능해야 하며 단일 누락만으로 fault를 선언하지 않아야 한다. | UR-04 |
| SR-05 | Primary ECU fault 선언 후 Safety Supervisor는 Backup ECU 활성화 요청을 자동 전송해야 한다. | UR-05 |
| SR-06 | Primary ECU fault 선언부터 Backup ECU 활성화 확인까지의 시간은 정의된 failover time budget 이내여야 한다. | UR-06 |
| SR-07 | Backup ECU는 활성화 요청 후 active acknowledgement 또는 active status를 Supervisor에 보고해야 한다. | UR-07 |
| SR-08 | Backup ECU 활성화 확인이 timeout 이내에 오지 않으면 시스템은 `SAFE` 상태로 전환해야 한다. | UR-08 |
| SR-09 | Safety Supervisor는 Primary ECU와 Backup ECU가 동시에 `ACTIVE`가 되지 않도록 활성 ECU ownership을 단일화해야 한다. | UR-09 |
| SR-10 | `DEGRADED` 상태에서 Primary ECU heartbeat가 회복되어도 자동으로 `NORMAL` 상태로 전환하지 않아야 한다. | UR-10 |
| SR-11 | `NORMAL` 복귀는 운영자 승인, Primary 안정성 확인, Backup 안전 비활성화 조건을 모두 만족해야 수행되어야 한다. | UR-11 |
| SR-12 | 모든 fault 선언, 활성화 요청, 활성화 결과, safe state 진입, 복구 감지, 시스템 상태 전이를 로그로 남겨야 한다. | UR-12 |
| SR-13 | 시스템은 운영자가 현재 시스템 상태와 활성 ECU를 확인할 수 있는 상태 조회 인터페이스를 제공해야 한다. | UR-13 |
| SR-14 | 시스템은 Primary 정지, heartbeat 손실, 지연, Backup 활성화 실패를 주입할 수 있는 fault injection 기능을 제공해야 한다. | UR-14 |
| SR-15 | 동일한 fault injection sequence에서 동일한 상태 전이 및 결과가 재현되어야 한다. | UR-15 |

## 초기 정량 파라미터

| 항목 | 초기값 | 비고 |
| --- | --- | --- |
| Heartbeat period | TBD | Primary ECU 송신 주기 |
| Heartbeat timeout | TBD | Supervisor 수신 timeout |
| Fault confirmation count `N` | 3 | 단일 손실 오탐 방지용 초기값 |
| Backup activation timeout | TBD | Backup active 확인 제한 시간 |
| Failover time budget | TBD | fault 선언부터 Backup active 확인까지 |

