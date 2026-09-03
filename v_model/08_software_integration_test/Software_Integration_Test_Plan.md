# Software Integration Test Plan

## 목적

Supervisor 내부 모듈 및 simulator 기반 ECU 컴포넌트 간 연동을 검증한다.

## 테스트 후보

| ID | 시나리오 | 기대 결과 | 연결 요구사항 |
| --- | --- | --- | --- |
| TC-SIT-01 | Primary heartbeat 정상 수신 | 시스템 상태 `NORMAL`, Backup `STANDBY` 유지 | SR-01, SR-02 |
| TC-SIT-02 | heartbeat 단일 손실 후 회복 | failover 미발생, 실패 카운터 초기화 | SR-04 |
| TC-SIT-03 | heartbeat 연속 손실 | Primary fault 선언, failover 시작 | SR-03, SR-05 |
| TC-SIT-04 | Backup active ack 수신 | 시스템 상태 `DEGRADED`, active owner Backup | SR-07, SR-09 |
| TC-SIT-05 | Backup active ack 미수신 | 시스템 상태 `SAFE` | SR-08 |
| TC-SIT-06 | Degraded 상태에서 Primary 회복 | `RECOVERY_DETECTED`, 자동 failback 미발생 | SR-10 |

