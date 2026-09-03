# Heartbeat Protocol

## Primary Heartbeat

| 필드 | 설명 |
| --- | --- |
| `message_id` | `PRIMARY_HEARTBEAT` |
| `sequence_counter` | heartbeat 순번 |
| `timestamp` | 송신 시각 또는 tick |
| `ecu_state` | Primary ECU 상태 |
| `health_status` | `OK`, `WARN`, `FAULT` 중 하나 |

## Backup Active Ack

| 필드 | 설명 |
| --- | --- |
| `message_id` | `BACKUP_ACTIVE_ACK` |
| `sequence_counter` | 응답 순번 |
| `timestamp` | 송신 시각 또는 tick |
| `ecu_state` | Backup ECU 상태 |
| `activation_result` | `SUCCESS` 또는 `FAILED` |

## 초기 규칙

- heartbeat 단일 누락은 fault 확정 조건이 아니다.
- `sequence_counter` 역전 또는 장시간 정지는 fault 후보로 기록한다.
- Backup 활성화는 command 송신이 아니라 `BACKUP_ACTIVE_ACK` 수신으로 완료 판단한다.

