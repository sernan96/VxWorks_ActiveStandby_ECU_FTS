# ISO 26262 Lite Tailoring

## 목적

본 문서는 VxWorks 기반 Active-Standby ECU Fault-Tolerant System에서 ISO 26262 개념을 어느 수준까지 참고 적용할지 정의한다.

## 적용 원칙

이 프로젝트는 토이프로젝트이며 실제 차량 양산, 인증, ASIL 확정, safety audit를 목표로 하지 않는다. 따라서 ISO 26262 준수 또는 인증을 주장하지 않는다.

대신 다음 목표를 위해 일부 개념만 경량 적용한다.

- 안전 요구사항을 체계적으로 도출한다.
- Hazard, Safety Goal, 시스템 요구사항, 소프트웨어 요구사항, 테스트 간 추적성을 유지한다.
- Fault injection과 verification evidence를 남긴다.
- 포트폴리오 또는 기술 설명에서 기능안전 프로세스 이해도를 보여준다.

## 적용 산출물

| ISO 26262 개념 | 이 프로젝트 산출물 | 적용 수준 |
| --- | --- | --- |
| Item Definition | `v_model/01_user_requirements/Item_Definition.md` | 시스템 경계와 운용 조건 정의 |
| Hazard Analysis and Risk Assessment | `v_model/01_user_requirements/HARA_Lite.md` | S/E/C 예비 분류 및 safety goal 연결 |
| Safety Goal | `v_model/01_user_requirements/URS.md` | 사용자 요구사항의 SG 항목으로 관리 |
| Functional Safety Concept | `v_model/02_system_requirements/Functional_Safety_Concept.md` | FSR을 시스템 요구사항에 연결 |
| Technical Safety Requirement | `v_model/02_system_requirements/SRS.md` | SR로 관리 |
| Software Safety Requirement | `v_model/04_software_requirements/Software_Requirements.md` | SWR로 관리 |
| Verification | `v_model/07_unit_test`부터 `10_system_verification` | 테스트 및 분석 증거 관리 |
| Validation | `v_model/11_user_validation` | 사용자 인수 조건 확인 |
| Configuration/Change Management | `artifact_management/` | 기준선, 변경, 리뷰, evidence 관리 |

## 제외 항목

- 실제 ASIL 확정 및 ASIL decomposition
- 독립 safety manager 또는 confirmation review 체계
- 하드웨어 random failure metric 산정
- FMEDA, FTA, DFA의 정식 수행
- production, operation, service, decommissioning 프로세스
- tool qualification
- ISO 26262 인증 주장

## 표현 가이드

문서와 발표에서는 다음 표현을 사용한다.

- 사용 가능: `ISO 26262-inspired`, `lightweight functional safety process`, `HARA-lite`, `traceability-oriented V-Model`
- 사용 금지: `ISO 26262 compliant`, `ASIL certified`, `certification-ready`, `formally qualified`

