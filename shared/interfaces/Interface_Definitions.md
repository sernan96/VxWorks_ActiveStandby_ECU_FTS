# Interface Definitions

## ECU 상태

| 상태 | 의미 |
| --- | --- |
| `UNKNOWN` | 아직 상태 확인 전 |
| `ACTIVE` | 주 기능 수행 중 |
| `STANDBY` | 대기 중 |
| `FAILED` | 고장 또는 동작 불가 |
| `ISOLATED` | Supervisor에 의해 격리됨 |
| `RECOVERED` | 복구 감지됨 |
| `UNAVAILABLE` | 사용할 수 없음 |

## 시스템 상태

| 상태 | 의미 |
| --- | --- |
| `INIT` | 초기화 |
| `NORMAL` | Primary ECU 정상 운용 |
| `FAILOVER_IN_PROGRESS` | Backup 전환 진행 |
| `DEGRADED` | Backup ECU 운용 |
| `RECOVERY_DETECTED` | Primary 복구 감지 |
| `SAFE` | 안전 상태 |

## 명령

| 명령 | 방향 | 목적 |
| --- | --- | --- |
| `PRIMARY_ISOLATE_CMD` | Supervisor -> Primary | Primary 주 기능 중지 |
| `BACKUP_ACTIVATE_CMD` | Supervisor -> Backup | Backup 활성화 |
| `BACKUP_STANDBY_CMD` | Supervisor -> Backup | Backup 대기 전환 |
| `SAFE_STATE_CMD` | Supervisor -> All | Safe State 진입 |

