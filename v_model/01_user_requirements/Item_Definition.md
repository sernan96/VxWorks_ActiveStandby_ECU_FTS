# Item Definition

## Item 이름

VxWorks 기반 Active-Standby ECU Fault-Tolerant System

## 목적

Primary ECU의 고장을 감지하고 Backup ECU로 기능을 전환하여 제한된 기능 지속 또는 Safe State 전환을 수행하는 fault-tolerant ECU supervision system을 정의한다.

## 시스템 경계

| 포함 | 제외 |
| --- | --- |
| Primary ECU 상태 감시 | 실제 차량/항공기/무기 제어 |
| heartbeat 기반 health monitoring | 실제 actuator 제어 |
| Primary fault detection | 유도, 항법, 비행 제어 알고리즘 |
| Backup ECU activation | 복잡한 센서 융합 |
| Safe State transition | Safety Supervisor 자체 이중화 |
| Manual failback 조건 관리 | ISO 26262, DO-178C, IEC 61508 인증 |
| Fault/event logging | 실제 ASIL 또는 DAL 확정 |
| Fault injection 검증 | 양산 운영/정비 프로세스 |

## 구성 요소

| 구성 요소 | 구현 대상 | 역할 |
| --- | --- | --- |
| Safety Supervisor | Raspberry Pi 4 + VxWorks | 상태 감시, fault 판단, failover 제어 |
| Primary ECU | TC375 | 정상 운용 시 주 기능 수행 |
| Backup ECU | Software ECU Simulator | Primary 고장 시 주 기능 대체 |

## 운용 상태

| 상태 | 설명 |
| --- | --- |
| 정상 운용 | Primary ECU active, Backup ECU standby |
| Primary fault | Primary heartbeat 또는 health status 이상 지속 |
| Failover | Backup ECU 활성화 요청 및 확인 |
| Degraded operation | Backup ECU active, 제한 기능 지속 |
| Recovery detected | Primary 회복 감지, 자동 failback 금지 |
| Safe State | Backup 활성화 실패 또는 정상 기능 지속 불가 |

## 가정

- Safety Supervisor 자체 고장은 프로젝트 범위에서 제외한다.
- Primary ECU와 Backup ECU는 동일한 주 기능을 수행할 수 있다고 가정한다.
- Backup ECU simulator는 실제 Backup ECU의 activation/ack 동작을 대표한다.
- 통신 오류는 heartbeat 누락 또는 지연으로 관찰 가능하다고 가정한다.
- Safe State의 구체 출력 제어는 실제 actuator가 없으므로 상태 전이와 명령 기록으로 대체한다.

