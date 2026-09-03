# Measurement Tools

Failover 시간, heartbeat timeout, Backup activation timeout을 측정하는 도구를 관리한다.

## 측정 대상

| 항목 | 시작 | 종료 |
| --- | --- | --- |
| fault detection time | 첫 이상 heartbeat 관찰 | Primary fault 선언 |
| failover time | Primary fault 선언 | Backup active ack 수신 |
| safe state transition time | Backup activation timeout | Safe State 진입 완료 |

