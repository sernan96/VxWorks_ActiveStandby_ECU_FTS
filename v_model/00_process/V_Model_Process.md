# V-Model Process

## 목적

본 문서는 VxWorks 기반 Active-Standby ECU Fault-Tolerant System의 축소 V-Model 수행 절차를 정의한다.

## 단계별 산출물

| 단계 | 주요 산출물 | 완료 기준 |
| --- | --- | --- |
| 사용자 요구사항 | `URS.md` | UR ID, 사용자 기대, 인수 조건 연결 완료 |
| 시스템 요구사항 | `SRS.md` | 정량 조건, 시스템 상태, fault 판단 기준 정의 |
| 시스템 아키텍처 | `System_Architecture.md` | 보드별 책임, 인터페이스, 상태 전이 구조 정의 |
| 소프트웨어 요구사항 | `Software_Requirements.md` | Supervisor/Primary/Backup별 SW 요구사항 정의 |
| MBD 상세 설계 | `MBD_State_Machine_Spec.md`, `StateSmith_Workflow.md` | 상태, 이벤트, guard, action, StateSmith 생성 흐름 정의 |
| 구현 | `Implementation_Plan.md` | 보드별 구현 범위와 빌드/통합 순서 정의 |
| 단위 테스트 | `Unit_Test_Plan.md` | 모듈 단위 테스트 케이스 정의 |
| SW 통합 테스트 | `Software_Integration_Test_Plan.md` | 소프트웨어 컴포넌트 간 연동 검증 |
| 시스템 통합 테스트 | `System_Integration_Test_Plan.md` | 보드 또는 simulator 간 end-to-end 검증 |
| 시스템 검증 | `System_Verification_Plan.md` | SRS 만족 여부 검증 |
| 사용자 Validation | `User_Validation_Plan.md` | UR 및 AC 만족 여부 확인 |

## 요구사항 ID 규칙

| 유형 | Prefix | 예시 |
| --- | --- | --- |
| 사용자 요구사항 | `UR` | `UR-01` |
| Hazard | `HAZ` | `HAZ-01` |
| Safety Goal | `SG` | `SG-01` |
| Acceptance Criteria | `AC` | `AC-01` |
| 시스템 요구사항 | `SR` | `SR-01` |
| 기능안전 요구사항 | `FSR` | `FSR-01` |
| 소프트웨어 요구사항 | `SWR` | `SWR-SUP-01` |
| 아키텍처 항목 | `ARCH` | `ARCH-01` |
| 상태 머신 항목 | `STM` | `STM-01` |
| 테스트 케이스 | `TC` | `TC-SYS-01` |

## 변경 관리

요구사항, 설계, 인터페이스, 테스트 기대 결과가 변경되면 다음을 갱신한다.

- 변경 내용: `artifact_management/Change_Log.md`
- 의사결정 배경: `artifact_management/Decision_Log.md`
- 영향받는 추적성: `artifact_management/Traceability_Matrix.md`
- 검증 증거: `artifact_management/evidence/`

## ISO 26262 Tailoring 방침

본 프로젝트는 실제 차량 양산 시스템이 아니므로 ISO 26262 준수 또는 인증을 주장하지 않는다. 대신 다음 개념을 축소 적용한다.

- Item Definition으로 시스템 경계와 운용 상황을 정의한다.
- HARA-lite로 hazard, safety goal, 위험 저감 의도를 정리한다.
- Functional Safety Concept에서 safety goal을 시스템 요구사항으로 연결한다.
- 요구사항, 설계, 구현, 테스트 간 추적성을 유지한다.
- 검증 결과와 리뷰 기록을 evidence로 관리한다.

ASIL 산정은 학습용 예비 분류로만 기록하며, 실제 ASIL 등급 주장에는 사용하지 않는다.
