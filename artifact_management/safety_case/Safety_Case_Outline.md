# Safety Case Outline

## Top Claim

본 시스템은 Primary ECU 고장 시 고장을 감지하고 Backup ECU로 전환하거나, 전환 실패 시 Safe State로 진입하도록 설계 및 검증된다.

## 주요 Claim

| Claim ID | 주장 | 근거 산출물 | 증거 |
| --- | --- | --- | --- |
| SC-01 | Primary ECU 고장은 Supervisor가 감지할 수 있다. | HARA-lite, FSR-01, SR-02, SR-03 | TC-SIT-03, TC-SYS-02 |
| SC-02 | 일시 통신 오류는 불필요한 failover로 이어지지 않는다. | FSR-03, SR-04 | TC-SIT-02, TC-SYS-03 |
| SC-03 | Primary 고장 후 Backup ECU가 자동 활성화된다. | FSR-02, SR-05, SR-07 | TC-SIT-04, TC-SYS-02 |
| SC-04 | Backup 활성화 실패 시 Safe State로 전환된다. | FSR-05, SR-08 | TC-SYS-04 |
| SC-05 | Primary와 Backup이 동시에 active owner가 되지 않는다. | FSR-04, SR-09, StateSmith 설계 | TC-SYS-05 |
| SC-06 | Primary 복구만으로 자동 failback이 발생하지 않는다. | FSR-06, SR-10, SR-11 | TC-SYS-05, TC-SYS-06 |
| SC-07 | 안전 관련 상태 전이는 추적 및 사후 분석 가능하다. | FSR-07, SR-12, SR-13 | 로그 evidence, 상태 조회 demo |

## Assumption

- Safety Supervisor 자체의 고장은 제외한다.
- 실제 actuator 출력은 다루지 않는다.
- Safe State는 상태 전이, 명령 송신, 로그 기록으로 검증한다.
- ASIL 후보는 학습용이며 인증 근거로 사용하지 않는다.

