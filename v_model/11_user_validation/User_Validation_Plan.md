# User Requirement Validation Plan

## 목적

사용자 요구사항과 사용자 인수 조건이 실제 운용 관점에서 만족되는지 확인한다.

## Acceptance Criteria

| ID | 인수 조건 | 연결 요구사항 |
| --- | --- | --- |
| AC-01 | Primary ECU가 정상일 때 Backup ECU가 불필요하게 활성화되지 않는가? | UR-01 |
| AC-02 | Primary ECU를 실제로 정지시키면 시스템이 고장을 감지하는가? | UR-02, UR-03 |
| AC-03 | Primary ECU 고장 후 Backup ECU가 자동으로 활성화되는가? | UR-05 |
| AC-04 | 일시적인 상태 신호 손실만으로 Failover가 발생하지 않는가? | UR-04 |
| AC-05 | Backup ECU가 활성화되지 못하면 시스템이 Safe State로 전환되는가? | UR-08 |
| AC-06 | Backup ECU가 활성화된 이후 Primary ECU가 다시 동작하더라도 두 ECU가 동시에 주 기능을 수행하지 않는가? | UR-09 |
| AC-07 | Primary ECU 복구만으로 자동 Failback이 발생하지 않는가? | UR-10, UR-11 |
| AC-08 | 각 고장과 상태 전환이 기록되어 사후 원인을 확인할 수 있는가? | UR-12, UR-13 |
| AC-09 | 동일한 Fault Injection을 반복했을 때 동일한 시스템 반응을 재현할 수 있는가? | UR-14, UR-15 |

## Validation 수행 기록 양식

| 항목 | 내용 |
| --- | --- |
| 수행 일자 | TBD |
| 수행자 | TBD |
| 대상 버전 | TBD |
| 사용 보드 구성 | TBD |
| 결과 요약 | TBD |
| 미해결 이슈 | TBD |

