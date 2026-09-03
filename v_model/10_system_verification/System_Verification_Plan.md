# System Verification Plan

## 목적

시스템 요구사항 `SR-01`부터 `SR-15`까지 구현 결과가 충족되었는지 검증한다.

## 검증 방법

| 방법 | 설명 |
| --- | --- |
| Test | 실제 실행 또는 simulator 실행 결과로 확인 |
| Inspection | 코드, 로그, 설정 파일, 모델 산출물 확인 |
| Analysis | timing measurement, 반복 결과 통계 분석 |
| Demonstration | 운영자 관점 시연으로 확인 |

## 요구사항별 검증 초안

| 요구사항 | 검증 방법 | 대표 테스트 |
| --- | --- | --- |
| SR-01 | Test | TC-SYS-01 |
| SR-02 | Test | TC-SIT-01 |
| SR-03 | Test | TC-SIT-03 |
| SR-04 | Test | TC-SIT-02, TC-SYS-03 |
| SR-05 | Test | TC-SYS-02 |
| SR-06 | Analysis | Failover 시간 측정 결과 |
| SR-07 | Test | TC-SIT-04 |
| SR-08 | Test | TC-SYS-04 |
| SR-09 | Test, Inspection | TC-SYS-05 |
| SR-10 | Test | TC-SYS-05 |
| SR-11 | Demonstration | TC-SYS-06 |
| SR-12 | Inspection | 로그 산출물 검토 |
| SR-13 | Demonstration | 상태 조회 시연 |
| SR-14 | Test | fault injection 도구 실행 |
| SR-15 | Analysis | TC-SYS-07 |

