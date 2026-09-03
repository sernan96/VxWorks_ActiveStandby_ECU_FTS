# V-Model Workspace

이 폴더는 축소 적용 V-Model 개발 프로세스의 산출물을 단계별로 관리한다.

## 왼쪽 개발 흐름

1. `01_user_requirements`: 사용자 요구사항
2. `02_system_requirements`: 시스템 요구사항
3. `03_system_architecture`: 시스템 아키텍처 설계
4. `04_software_requirements`: 소프트웨어 요구사항
5. `05_mbd_state_machine`: StateSmith 기반 MBD 상태 머신 상세 설계
6. `06_implementation`: 구현 및 통합 계획

## 오른쪽 검증 흐름

1. `07_unit_test`: 단위 테스트
2. `08_software_integration_test`: 소프트웨어 통합 테스트
3. `09_system_integration_test`: 시스템 통합 테스트
4. `10_system_verification`: 시스템 요구사항 검증
5. `11_user_validation`: 사용자 요구사항 Validation

## 운영 원칙

- 모든 요구사항은 고유 ID를 가진다.
- 상위 요구사항은 하위 요구사항 또는 설계 항목으로 추적 가능해야 한다.
- 모든 테스트 케이스는 검증 대상 요구사항 ID를 명시한다.
- 변경 발생 시 `artifact_management/Change_Log.md`에 기록한다.
- 기준선 확정 시 `artifact_management/baselines/`에 버전별 스냅샷 또는 링크를 남긴다.
- StateSmith 모델 원본과 생성 코드는 구분하여 관리한다.
- ISO 26262 관련 표현은 인증 또는 준수가 아닌 경량 참고 적용으로 제한한다.

## ISO 26262-inspired 산출물

| 산출물 | 경로 | 목적 |
| --- | --- | --- |
| Item Definition | `01_user_requirements/Item_Definition.md` | 시스템 경계, 운용 상황, 제외 범위 정의 |
| HARA-lite | `01_user_requirements/HARA_Lite.md` | hazard, severity/exposure/controllability 후보, safety goal 연결 |
| Functional Safety Concept | `02_system_requirements/Functional_Safety_Concept.md` | safety goal을 시스템 수준 safety requirement로 구체화 |
| Safety Case Outline | `../artifact_management/safety_case/Safety_Case_Outline.md` | 최종적으로 무엇을 근거로 안전 주장을 할지 구조화 |
