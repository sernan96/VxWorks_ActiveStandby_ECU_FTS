# HARA Lite

## 목적

ISO 26262의 HARA 개념을 경량으로 참고하여 hazard, safety goal, 사용자 요구사항 간 관계를 정리한다.

본 문서의 S/E/C 및 ASIL 후보는 학습용 예비 분류이며 실제 ISO 26262 ASIL 산정으로 사용하지 않는다.

## 분류 기준

| 항목 | 의미 | 적용 방식 |
| --- | --- | --- |
| Severity | 위험 상황 발생 시 영향 정도 | Toy project 기준 정성 분류 |
| Exposure | 해당 운용 상황 노출 가능성 | 반복 시험 가능성 기준 정성 분류 |
| Controllability | 위험 상황 제어 가능성 | Supervisor/운영자 개입 가능성 기준 정성 분류 |
| ASIL 후보 | 위험 저감 필요 수준 | 포트폴리오 설명용 참고값 |

## Hazard 분석

| Hazard | 설명 | S | E | C | ASIL 후보 | Safety Goal | 연결 UR |
| --- | --- | --- | --- | --- | --- | --- | --- |
| HAZ-01 | Primary ECU 고장 미감지로 잘못된 기능 지속 | S2 | E3 | C2 | B 후보 | SG-01 | UR-02, UR-03 |
| HAZ-02 | 일시 통신 오류를 고장으로 오탐하여 불필요한 failover | S1 | E3 | C2 | A 후보 | SG-03 | UR-04 |
| HAZ-03 | Primary/Backup 동시 활성화로 상충 출력 발생 | S2 | E2 | C3 | B 후보 | SG-04 | UR-09 |
| HAZ-04 | Failover 실패 후 잘못된 동작 지속 | S2 | E2 | C2 | B 후보 | SG-05 | UR-08 |
| HAZ-05 | 불안정한 자동 failback으로 반복 전환 발생 | S1 | E3 | C2 | A 후보 | SG-06 | UR-10, UR-11 |

## Risk Reduction 전략

| Safety Goal | 위험 저감 전략 |
| --- | --- |
| SG-01 | heartbeat timeout과 연속 실패 횟수로 Primary fault 감지 |
| SG-02 | Backup activation command와 active acknowledgement로 failover 완료 확인 |
| SG-03 | 단일 heartbeat 누락 또는 일시 지연은 fault 확정에서 제외 |
| SG-04 | active ECU owner를 단일 값으로 관리하고 isolate 명령 수행 |
| SG-05 | Backup activation timeout 시 Safe State 전환 |
| SG-06 | Primary recovery와 failback 승인을 분리하고 manual failback 조건 요구 |

