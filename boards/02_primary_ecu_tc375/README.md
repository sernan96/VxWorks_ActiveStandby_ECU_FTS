# Primary ECU - TC375 Lite Kit

## 책임

- 정상 상태에서 시스템 주 기능 수행
- Safety Supervisor로 주기적 heartbeat 전송
- 현재 ECU 상태 및 활성 상태 보고
- Supervisor의 격리 또는 비활성화 명령 수신 시 주 기능 중지
- Fault Injection 검증을 위한 정지, 지연, 상태 오류 주입 지원

## 대상 보드/IDE

- Board: AURIX TC375 lite Kit, `KIT_A2G_TC375_LITE`
- IDE: AURIX Development Studio
- 기준 예제: Infineon `AURIX_code_examples/code_examples/ASCLIN_UART_1_KIT_TC375_LK`

이 폴더의 코드는 ADS 전체 프로젝트를 대체하지 않는다. 먼저 공식 예제를 ADS로 import해 프로젝트 설정과 iLLD 라이브러리를 확보한 뒤, `src/`와 `include/`의 Primary ECU overlay 코드를 적용한다.

## 폴더

| 경로 | 내용 |
| --- | --- |
| `src/` | TC375 애플리케이션, heartbeat 송신, 상태 보고 구현 |
| `include/` | Primary ECU 헤더 및 인터페이스 정의 |
| `tests/` | Primary ECU 단위 테스트 및 통신 테스트 |
| `docs/` | TC375 설정, 통신 설정, fault injection 절차 |

## 주요 상태

- `ACTIVE`: 주 기능 수행
- `FAILED`: heartbeat 또는 기능 수행 불가
- `ISOLATED`: Supervisor에 의해 주 기능 중지
- `RECOVERED`: 동작 복구 감지, 즉시 failback 대상은 아님

## 현재 구현

- `Cpu0_Main.c`: ADS 예제의 `Cpu0_Main.c` 교체용 entry point
- `PrimaryEcu_App.c/h`: Primary ECU runtime, heartbeat frame, fault injection
- `PrimaryEcu_Uart.c/h`: ASCLIN UART 송신 adapter
- `docs/AURIX_ADS_TC375_LITE_KIT_Setup.md`: ADS import 및 overlay 적용 절차
