# StateSmith Workflow

## 목적

Failover 상태 머신을 StateSmith로 모델링하고 C 코드로 생성한 뒤 Safety Supervisor의 VxWorks 환경에 통합하는 절차를 정의한다.

## 경로

| 경로 | 내용 |
| --- | --- |
| `statesmith_model/` | StateSmith 모델 원본 |
| `diagrams/` | 상태 머신 설명용 다이어그램, 캡처, 리뷰 자료 |
| `generated_c/` | StateSmith 생성 C 코드 |
| `boards/01_safety_supervisor_rpi4_vxworks/src/` | VxWorks wrapper, adapter, task integration |
| `boards/01_safety_supervisor_rpi4_vxworks/tests/` | 생성 코드 및 wrapper 검증 |

## 모델링 규칙

- 상태 이름은 `MBD_State_Machine_Spec.md`의 상태명을 기준으로 한다.
- 외부 입력은 StateSmith event로 추상화한다.
- VxWorks API 호출, 통신 송신, 로그 저장은 모델 action에서 직접 구현하지 않고 adapter 함수로 연결한다.
- guard 조건은 테스트 가능하도록 순수 함수에 가깝게 작성한다.
- 생성 코드는 수동 수정하지 않는다.

## 생성 코드 관리

| 산출물 | 관리 방식 |
| --- | --- |
| 모델 원본 | 변경 시 리뷰 필요 |
| 생성 C 코드 | 모델에서 재생성 가능해야 함 |
| wrapper 코드 | 사람이 유지보수하는 VxWorks 통합 코드 |
| 테스트 코드 | generated-code host test와 VxWorks integration test로 분리 |

## 기본 작업 순서

1. 상태, 이벤트, guard, action을 `MBD_State_Machine_Spec.md`에 먼저 반영한다.
2. StateSmith 모델을 `statesmith_model/`에 작성한다.
3. 모델 리뷰 후 StateSmith CLI로 C 코드를 `generated_c/`로 생성한다.
4. 생성 코드를 host 환경에서 빌드하고 상태 전이 테스트를 수행한다.
5. VxWorks adapter와 연결한다.
6. Safety Supervisor 통합 테스트를 수행한다.
7. 모델 버전, 생성 코드 버전, 테스트 증거를 산출물 관리 폴더에 기록한다.

## 현재 적용안

현재 첫 MBD 원본은 `statesmith_model/FailoverSupervisor.plantuml`이다.

StateSmith CLI 설치와 생성 절차는 `statesmith_model/StateSmith_Install_And_Generate.md`에 정리한다. Safety Supervisor 통합 계약은 `boards/01_safety_supervisor_rpi4_vxworks/docs/MBD_Integration_Notes.md`와 `boards/01_safety_supervisor_rpi4_vxworks/include/SupervisorMbd_Port.h`에서 관리한다.

2026-09-03 기준 StateSmith CLI 0.22.2를 프로젝트 로컬 dotnet tool로 설치했고 `generated_c/FailoverSupervisor.c`, `generated_c/FailoverSupervisor.h`, `statesmith_model/FailoverSupervisor.sim.html` 생성을 완료했다.

## 추적성

StateSmith의 상태와 이벤트는 다음 항목에 연결되어야 한다.

- 사용자 요구사항: `UR-*`
- 기능안전 요구사항: `FSR-*`
- 시스템 요구사항: `SR-*`
- 소프트웨어 요구사항: `SWR-*`
- 테스트 케이스: `TC-*`
