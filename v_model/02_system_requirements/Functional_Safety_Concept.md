# Functional Safety Concept

## 목적

사용자 요구사항과 HARA-lite에서 정의한 safety goal을 시스템 수준 기능안전 요구사항으로 구체화한다.

## Functional Safety Requirements

| ID | 기능안전 요구사항 | Safety Goal | 시스템 요구사항 |
| --- | --- | --- | --- |
| FSR-01 | 시스템은 Primary ECU의 heartbeat와 health status를 감시하여 고장 후보와 고장 확정을 구분해야 한다. | SG-01 | SR-02, SR-03 |
| FSR-02 | 시스템은 Primary ECU 고장 확정 후 Backup ECU 활성화를 자동 수행하고 활성화 완료를 확인해야 한다. | SG-02 | SR-05, SR-06, SR-07 |
| FSR-03 | 시스템은 단일 heartbeat 손실 또는 일시 통신 지연을 Primary ECU 고장으로 확정하지 않아야 한다. | SG-03 | SR-04 |
| FSR-04 | 시스템은 Primary ECU와 Backup ECU의 active ownership이 동시에 부여되지 않도록 해야 한다. | SG-04 | SR-01, SR-09 |
| FSR-05 | Backup ECU 활성화가 실패하거나 timeout이 발생하면 시스템은 Safe State로 전환해야 한다. | SG-05 | SR-08 |
| FSR-06 | Backup ECU 운용 중 Primary ECU가 회복되더라도 자동 failback이 발생하지 않아야 한다. | SG-06 | SR-10, SR-11 |
| FSR-07 | 시스템은 안전 관련 이벤트와 상태 전이를 기록하고 운영자가 현재 상태를 확인할 수 있게 해야 한다. | SG-01..SG-06 | SR-12, SR-13 |
| FSR-08 | 시스템은 safety mechanism을 반복 검증할 수 있도록 fault injection 및 반복성 확인 수단을 제공해야 한다. | SG-01..SG-06 | SR-14, SR-15 |

## Safety Mechanism

| 메커니즘 | 설명 | 관련 FSR |
| --- | --- | --- |
| Heartbeat Monitoring | Primary ECU 생존 및 상태 주기 감시 | FSR-01 |
| Fault Confirmation Counter | 일시 오류와 지속 고장 구분 | FSR-01, FSR-03 |
| Active Owner Control | 주 기능 수행 ECU를 단일 owner로 제한 | FSR-04 |
| Backup Activation Handshake | Backup activation command와 ack 확인 | FSR-02 |
| Activation Timeout | Backup 활성화 실패 감지 | FSR-05 |
| Safe State Command | 정상 기능 지속 불가 시 안전 상태 전환 | FSR-05 |
| Manual Failback Guard | Primary recovery와 normal 복귀 분리 | FSR-06 |
| Event Logging | fault 및 상태 전이 사후 분석 | FSR-07 |
| Fault Injection | 안전 메커니즘 반복 검증 | FSR-08 |

## 검증 방향

- FSR은 `artifact_management/Traceability_Matrix.md`에서 UR, SR, SWR, StateSmith 상태, 테스트 케이스와 연결한다.
- FSR 검증 증거는 `artifact_management/evidence/`에 테스트 케이스 ID 기준으로 보관한다.
- Safe State와 failback guard는 반드시 fault injection으로 재현한다.

