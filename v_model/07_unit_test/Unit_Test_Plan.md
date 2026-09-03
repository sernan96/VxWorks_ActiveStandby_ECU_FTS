# Unit Test Plan

## 목적

각 소프트웨어 모듈이 독립적으로 요구 동작을 만족하는지 검증한다.

## 테스트 후보

| ID | 대상 | 검증 내용 | 연결 요구사항 |
| --- | --- | --- | --- |
| TC-UT-01 | Health Monitor | heartbeat 정상 수신 시 실패 카운터 초기화 | SWR-SUP-01, SWR-SUP-02 |
| TC-UT-02 | Health Monitor | 단일 heartbeat 누락 시 fault 미선언 | SWR-SUP-02 |
| TC-UT-03 | Fault Decision Manager | 연속 `N`회 누락 시 Primary fault 선언 | SWR-SUP-03 |
| TC-UT-04 | Failover Controller | Primary fault 후 Backup activation command 생성 | SWR-SUP-04 |
| TC-UT-05 | Failover Controller | Backup ack timeout 시 Safe State 요청 | SWR-SUP-05, SWR-SUP-06 |
| TC-UT-06 | State Manager | active owner가 동시에 두 ECU로 설정되지 않음 | SWR-SUP-07 |
| TC-UT-07 | Recovery Logic | Primary recovery만으로 failback이 수행되지 않음 | SWR-SUP-08 |
| TC-UT-08 | Event Logger | 주요 이벤트에 timestamp와 event ID 포함 | SWR-SUP-09 |

