# Primary ECU Debug Test

## 목적

TC375 Lite Kit에서 Primary ECU heartbeat 송신과 fault injection 변수를 debugger로 확인한다.

## 사전 조건

- AURIX Development Studio에서 `ASCLIN_UART_1_KIT_TC375_LK` 예제를 import한다.
- 이 저장소의 Primary ECU overlay 코드를 예제 프로젝트에 적용한다.
- 프로젝트가 build되고 TC375 Lite Kit에 flash 가능해야 한다.

## 테스트

| ID | 절차 | 기대 결과 |
| --- | --- | --- |
| TC-PRI-DBG-01 | 부팅 후 `g_primaryEcuRuntime.sequenceCounter` 관찰 | 100 ms 주기로 증가 |
| TC-PRI-DBG-02 | `g_primaryEcuRuntime.faultInjection.stopHeartbeat = TRUE` 설정 | sequence counter 증가 및 heartbeat 송신 정지 |
| TC-PRI-DBG-03 | `forceFaultStatus = TRUE` 설정 | `state=FAILED`, `health=FAULT`로 변경 |
| TC-PRI-DBG-04 | `isolateOutput = TRUE` 설정 | `state=ISOLATED`, `health=WARN`으로 변경 |
| TC-PRI-DBG-05 | `artificialDelayLoops`에 큰 값 설정 | heartbeat 주기가 의도적으로 지연 |

