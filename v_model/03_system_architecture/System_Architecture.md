# System Architecture

## 논리 구성

```text
Primary ECU (TC375)
  | heartbeat / health status
  v
Safety Supervisor (Raspberry Pi 4 + VxWorks)
  | activation command / safe state command
  v
Backup ECU (Software Simulator)
```

## 컴포넌트 책임

| 컴포넌트 | 책임 |
| --- | --- |
| Health Monitor | Primary ECU heartbeat 수신, timeout 및 연속 실패 횟수 관리 |
| Fault Decision Manager | 일시 오류와 지속 고장 구분, fault 선언 |
| Failover Controller | Primary 격리, Backup 활성화 요청, 활성화 확인 |
| State Manager | `INIT`, `NORMAL`, `FAILOVER_IN_PROGRESS`, `DEGRADED`, `RECOVERY_DETECTED`, `SAFE` 상태 관리 |
| Event Logger | 상태 전이 및 주요 이벤트 기록 |
| Fault Injection Interface | 검증용 fault 주입 제어 |
| Status Interface | 운영자 상태 조회 제공 |

## 보드별 할당

| 항목 | Safety Supervisor | Primary ECU | Backup ECU |
| --- | --- | --- | --- |
| 주 기능 수행 | 제어하지 않음 | 정상 시 수행 | Failover 후 수행 |
| Heartbeat 송신 | 수신 | 송신 | 활성화 후 상태 송신 |
| Fault 판단 | 수행 | 수행하지 않음 | 수행하지 않음 |
| Failover 제어 | 수행 | 명령 수신 | 명령 수신 |
| Safe State 결정 | 수행 | 명령 수신 | 명령 수신 |
| 로그 기록 | 시스템 이벤트 기록 | 로컬 이벤트 선택 기록 | 로컬 이벤트 선택 기록 |

## 인터페이스 후보

| ID | 방향 | 메시지 | 목적 |
| --- | --- | --- | --- |
| IF-01 | Primary -> Supervisor | `PRIMARY_HEARTBEAT` | Primary 생존 및 상태 알림 |
| IF-02 | Supervisor -> Primary | `PRIMARY_ISOLATE_CMD` | Primary 주 기능 중지 |
| IF-03 | Supervisor -> Backup | `BACKUP_ACTIVATE_CMD` | Backup 활성화 요청 |
| IF-04 | Backup -> Supervisor | `BACKUP_ACTIVE_ACK` | Backup 활성화 완료 확인 |
| IF-05 | Supervisor -> All | `SAFE_STATE_CMD` | Safe State 진입 명령 |
| IF-06 | Operator/Test Tool -> Supervisor | `FAULT_INJECTION_CMD` | 검증용 fault 주입 |
| IF-07 | Operator -> Supervisor | `STATUS_QUERY` | 현재 시스템 상태 조회 |

