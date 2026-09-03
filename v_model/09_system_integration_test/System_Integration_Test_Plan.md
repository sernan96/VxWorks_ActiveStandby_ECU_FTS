# System Integration Test Plan

## 목적

Safety Supervisor, Primary ECU, Backup ECU Simulator 또는 실제 보드가 연결된 상태에서 end-to-end 동작을 검증한다.

## 테스트 후보

| ID | 시나리오 | 기대 결과 | 연결 요구사항 |
| --- | --- | --- | --- |
| TC-SYS-01 | 전체 시스템 정상 부팅 | `INIT` 후 `NORMAL` 진입 | SR-01 |
| TC-SYS-02 | Primary ECU 프로세스 또는 보드 정지 | Primary fault 선언 후 Backup 활성화 | SR-03, SR-05 |
| TC-SYS-03 | 일시적 통신 지연 주입 | Backup 전환 미발생 | SR-04 |
| TC-SYS-04 | Backup Simulator 활성화 실패 주입 | `SAFE` 상태 진입 | SR-08 |
| TC-SYS-05 | Backup 활성화 후 Primary 재시작 | 동시 활성화 없음, 자동 failback 없음 | SR-09, SR-10 |
| TC-SYS-06 | Manual failback 조건 만족 | Backup standby, Primary active 복귀 | SR-11 |
| TC-SYS-07 | 동일 fault injection 10회 반복 | 동일 상태 전이와 결과 재현 | SR-15 |

