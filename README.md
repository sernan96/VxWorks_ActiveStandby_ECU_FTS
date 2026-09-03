# VxWorks Active-Standby ECU Fault-Tolerant System

이 프로젝트는 VxWorks 기반 Safety Supervisor가 Primary ECU 고장을 감지하고 Backup ECU로 전환하는 Active-Standby Fault-Tolerant 시스템을 구현하고 검증하기 위한 작업공간이다.

본 프로젝트는 기능안전 및 고신뢰 임베디드 시스템 개념 학습용 토이프로젝트이며, ISO 26262, DO-178C, IEC 61508 등의 인증 준수를 목표로 하지 않는다. 다만 ISO 26262의 safety lifecycle, hazard analysis, safety goal, traceability, verification evidence 개념은 경량으로 참고하여 산출물에 반영한다.

## 주요 구성

| 영역 | 경로 | 목적 |
| --- | --- | --- |
| 보드별 구현 | `boards/` | Safety Supervisor, Primary ECU, Backup ECU별 코드와 보드 문서 관리 |
| 공통 인터페이스 | `shared/` | ECU 간 메시지, heartbeat, 상태 코드, 공통 테스트 도구 관리 |
| V-Model 프로세스 | `v_model/` | 요구사항, 설계, 구현, 검증, 인수 확인 산출물 관리 |
| 산출물 관리 | `artifact_management/` | 기준선, 변경 이력, 리뷰, 릴리스, 검증 증거 관리 |
| 개발 도구 | `tools/` | Fault Injection, Logging, Failover 시간 측정 도구 관리 |

## 시스템 목표

정상 상태에서는 Primary ECU가 주 기능을 수행하고 Backup ECU는 Standby 상태를 유지한다. Primary ECU 고장이 지속적으로 확인되면 Safety Supervisor가 Backup ECU 활성화를 요청하고, 성공 시 시스템은 Degraded 상태에서 기능을 지속한다. Backup ECU 활성화까지 실패하면 시스템은 Safe State로 전환한다.

## 개발 흐름

1. 사용자 요구사항 작성 및 기준선 등록
2. 시스템 요구사항 도출
3. 시스템 아키텍처 및 인터페이스 설계
4. 소프트웨어 요구사항 작성
5. StateSmith 기반 MBD 상태 머신 설계
6. StateSmith 모델에서 C 코드 생성
7. VxWorks 통합
8. 단위, 소프트웨어 통합, 시스템 통합, 시스템 검증 수행
9. 사용자 요구사항 Validation 수행

## MBD / StateSmith

Failover 핵심 상태 머신은 StateSmith로 진행한다. StateSmith 모델 원본은 `v_model/05_mbd_state_machine/statesmith_model/`, 생성 C 코드는 `v_model/05_mbd_state_machine/generated_c/`, 다이어그램 및 설계 보조 자료는 `v_model/05_mbd_state_machine/diagrams/`에 둔다.

생성 코드는 Safety Supervisor 보드의 VxWorks 태스크에 통합한다. 사람이 직접 수정하는 코드는 wrapper, platform adapter, test harness 위주로 분리하고, StateSmith 생성물은 재생성 가능한 산출물로 관리한다.

## ISO 26262 경량 적용 범위

이 프로젝트는 ISO 26262 인증 대상이 아니다. 대신 다음 항목만 학습 및 어필 목적의 lightweight safety work product로 관리한다.

- Item Definition
- HARA-lite 및 Safety Goal
- Functional Safety Concept 초안
- Technical Safety Requirement 수준의 시스템 요구사항 추적
- Verification/Validation evidence
- 변경 관리 및 review record

## 요구사항 추적

요구사항 추적은 `artifact_management/Traceability_Matrix.md`에서 관리한다. 모든 사용자 요구사항은 하나 이상의 시스템 요구사항, 소프트웨어 요구사항, 설계 산출물, 테스트 케이스, 사용자 인수 조건과 연결되어야 한다.
