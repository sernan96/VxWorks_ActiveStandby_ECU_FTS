# Safety Supervisor - Raspberry Pi 4 / VxWorks

## 책임

- Primary ECU heartbeat 및 health status 감시
- 일시적 통신 오류와 지속 고장 구분
- Primary ECU fault 선언
- Backup ECU 활성화 요청
- Backup ECU 활성화 확인
- Primary/Backup 동시 활성화 방지
- Backup ECU 활성화 실패 시 Safe State 전환
- Primary ECU 복구 감지 및 manual failback 조건 관리
- Fault/Event logging 및 failover 시간 측정

## 폴더

| 경로 | 내용 |
| --- | --- |
| `src/` | VxWorks 태스크, 상태 머신, failover 제어 구현 |
| `include/` | Supervisor 내부 헤더 및 공통 인터페이스 헤더 |
| `tests/` | Supervisor 단위 테스트 및 host 기반 테스트 |
| `docs/` | 보드 bring-up, VxWorks 설정, 타이밍/통신 제약 문서 |

## 주요 산출물 연결

- 시스템 요구사항: `v_model/02_system_requirements/SRS.md`
- 소프트웨어 요구사항: `v_model/04_software_requirements/Software_Requirements.md`
- 상태 머신 설계: `v_model/05_mbd_state_machine/MBD_State_Machine_Spec.md`
- 테스트 계획: `v_model/07_unit_test/Unit_Test_Plan.md`

