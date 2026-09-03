# Shared Test Tools

공통 simulator, message stub, timing helper를 배치한다.

## 후보 도구

| 도구 | 목적 |
| --- | --- |
| Primary heartbeat stub | Supervisor 단위 및 통합 테스트용 heartbeat 생성 |
| Backup ack stub | Backup 활성화 성공/실패 시뮬레이션 |
| Message recorder | 테스트 중 송수신 메시지 기록 |
| Timing helper | failover time budget 측정 |

