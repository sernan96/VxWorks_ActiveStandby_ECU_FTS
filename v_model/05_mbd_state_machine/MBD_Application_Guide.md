# MBD Application Guide

## 결론

이 프로젝트에서 MBD는 Safety Supervisor의 failover 상태 머신에 먼저 적용한다.

TC375 Lite Kit Primary ECU는 heartbeat와 health status를 송신하는 대상이고, Raspberry Pi 4/VxWorks Safety Supervisor가 StateSmith로 생성한 상태 머신 코드를 이용해 fault 판단, failover, safe state 전환을 수행한다.

## 적용 범위

| 대상 | MBD 적용 여부 | 이유 |
| --- | --- | --- |
| Safety Supervisor failover logic | 적용 | 상태 전이가 명확하고 안전 요구사항 추적이 중요함 |
| Primary ECU heartbeat sender | 초기 미적용 | 단순 주기 송신이므로 hand-written C로 시작 |
| Backup ECU simulator | 초기 미적용 | failover 대상 동작 검증용으로 단순 구현 |
| Manual failback logic | 적용 후보 | guard 조건과 운영자 승인 흐름이 상태 머신에 적합 |

## 전체 흐름

```text
MBD_State_Machine_Spec.md
  -> statesmith_model/FailoverSupervisor.plantuml
  -> StateSmith CLI
  -> generated_c/FailoverSupervisor.c,h
  -> Supervisor wrapper / VxWorks adapter
  -> Unit / integration test evidence
```

## 1단계: 상태 머신 요구사항 확정

`MBD_State_Machine_Spec.md`에서 다음 항목을 먼저 확정한다.

- 상태: `INIT`, `NORMAL`, `PRIMARY_FAULT_CANDIDATE`, `FAILOVER_IN_PROGRESS`, `DEGRADED`, `RECOVERY_DETECTED`, `SAFE`
- 이벤트: heartbeat OK, heartbeat timeout, fault confirmation, backup ack, activation timeout, recovery detected, manual failback approved
- guard: fault confirmation count, backup activation timeout, manual failback 승인 조건
- action: active owner 설정, Primary fault 선언, Backup 활성화 요청, Safe State 명령, 로그 기록

## 2단계: StateSmith 모델 작성

모델 원본은 `statesmith_model/FailoverSupervisor.plantuml`에 둔다.

StateSmith는 PlantUML, draw.io, yEd 같은 diagram input을 받아 상태 머신 코드를 생성할 수 있다. 우리 프로젝트는 Git diff와 코드 리뷰가 쉬운 PlantUML을 첫 모델 형식으로 사용한다.

## 3단계: 코드 생성

StateSmith CLI 설치 후 `v_model/05_mbd_state_machine`에서 실행한다.

```powershell
ss.cli --version
ss.cli run --here --recursive
```

생성 결과는 `generated_c/`에 보관한다. 생성 파일은 직접 수정하지 않는다.

## 4단계: Supervisor에 통합

VxWorks 의존 코드는 생성 C 파일 안에 넣지 않는다. 대신 아래처럼 분리한다.

| 계층 | 역할 |
| --- | --- |
| generated C | StateSmith가 생성한 순수 상태 머신 |
| wrapper | heartbeat monitor, backup ack receiver가 StateSmith event를 호출 |
| port adapter | VxWorks task, timer, UART/socket/CAN, logging API 연결 |
| platform action | Primary isolate, Backup activate, Safe State command 수행 |

## 5단계: 테스트

| 테스트 | 목적 |
| --- | --- |
| host unit test | StateSmith 생성 코드의 상태 전이 검증 |
| Supervisor software integration test | heartbeat monitor와 generated state machine 연동 검증 |
| system integration test | TC375 Lite Kit heartbeat 기반 failover 검증 |
| fault injection repeatability test | 동일 fault 주입 시 동일 상태 전이 확인 |

## 적용 시 주의점

- StateSmith 모델이 상태 머신의 단일 원본이어야 한다.
- generated C는 손으로 수정하지 않는다.
- action/guard 함수는 testable하게 작게 유지한다.
- VxWorks API는 adapter 계층에만 둔다.
- 상태 전이마다 event log를 남겨 traceability evidence로 사용한다.

