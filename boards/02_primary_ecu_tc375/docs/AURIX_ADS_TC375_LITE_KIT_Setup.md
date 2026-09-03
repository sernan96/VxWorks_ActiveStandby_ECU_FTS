# AURIX Development Studio Setup - TC375 Lite Kit

## 현재 구현 상태

현재 저장소의 TC375 코드는 완전한 독립 ADS 프로젝트가 아니라, Infineon 공식 ADS 예제 위에 적용하는 overlay 코드이다.

이 방식을 쓰는 이유는 AURIX Development Studio 프로젝트 설정, linker script, startup code, iLLD `Libraries/`, `Configurations/`, `.project`, `.cproject` 파일을 공식 예제에서 그대로 가져와야 TC375 Lite Kit에서 빌드/디버그 설정이 안정적으로 유지되기 때문이다.

## 기준 예제

- Repository: `https://github.com/Infineon/AURIX_code_examples`
- Example: `ASCLIN_UART_1_KIT_TC375_LK`
- Board: `AURIX TC375 lite Kit`, `KIT_A2G_TC375_LITE`
- IDE: AURIX Development Studio
- 목적: ASCLIN UART 기반 통신 설정을 Primary ECU heartbeat 송신의 기준 프로젝트로 사용

Infineon 공식 README에 따르면 AURIX Development Studio에서는 `File > Import... > Infineon > AURIX Development Studio Project`에서 `Infineon Code Examples Repository`를 선택해 code example을 import할 수 있다.

## ADS 프로젝트 구성 절차

1. AURIX Development Studio 실행
2. `File > Import...` 선택
3. `Infineon > AURIX Development Studio Project` 선택
4. `Infineon Code Examples Repository`에서 `ASCLIN_UART_1_KIT_TC375_LK` import
5. import된 프로젝트가 정상 build 되는지 먼저 확인
6. 이 저장소의 `boards/02_primary_ecu_tc375/src/*.c` 파일을 ADS 프로젝트 루트 또는 ADS 프로젝트의 application source 영역에 복사
7. 이 저장소의 `boards/02_primary_ecu_tc375/include/*.h` 파일을 ADS 프로젝트 include path에 추가하거나 프로젝트 루트에 복사
8. 기존 예제의 `Cpu0_Main.c`를 이 저장소의 `src/Cpu0_Main.c` 내용으로 교체
9. Build Project 수행
10. TC375 Lite Kit에 Flash/Debug

## 초기 통신 방침

초기 코드는 공식 ASCLIN UART 예제와 같은 iLLD 모듈 구성을 사용한다. 단, 실제 Raspberry Pi 4 Safety Supervisor와 연결할 때는 TC375 Lite Kit의 실제 UART TX/RX 핀, 전압 레벨, GND 공통 연결을 보드 매뉴얼 기준으로 확인해야 한다.

현재 `PrimaryEcu_Uart.c`의 기본 핀 설정은 공식 `ASCLIN_UART_1_KIT_TC375_LK` 예제를 따라 `ASCLIN1 / P15.5`를 기준으로 둔다. 실제 외부 UART 연결에 맞지 않으면 이 파일의 pin macro를 먼저 수정한다.

## Primary ECU 동작

- 부팅 후 watchdog은 공식 예제처럼 초기 개발 편의를 위해 비활성화한다.
- CPU sync 이후 Primary ECU application을 초기화한다.
- 100 ms 주기로 heartbeat frame을 UART로 송신한다.
- heartbeat frame에는 sequence counter, ECU state, health status, fault injection 상태를 포함한다.
- debugger에서 fault injection 변수를 바꿔 heartbeat stop, delay, fault status를 주입할 수 있다.

## Debugger에서 확인할 변수

| 변수 | 목적 |
| --- | --- |
| `g_primaryEcuRuntime.sequenceCounter` | heartbeat 송신 순번 |
| `g_primaryEcuRuntime.state` | Primary ECU 상태 |
| `g_primaryEcuRuntime.health` | health status |
| `g_primaryEcuRuntime.faultInjection` | fault injection 설정 |

## 아직 남은 작업

- TC375 Lite Kit 실제 UART 핀 확정
- Raspberry Pi 4 Supervisor와 물리 UART 또는 다른 통신 채널 결정
- Supervisor 수신 프로토콜 구현
- isolate command 수신 처리
- watchdog enable 및 periodic service 정책 결정

