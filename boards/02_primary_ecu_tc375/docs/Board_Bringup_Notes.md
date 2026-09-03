# Primary ECU Board Bring-up Notes

## 대상

- Board: TC375 Lite Kit (`KIT_A2G_TC375_LITE`)
- 역할: 정상 운용 시 주 기능 수행 및 heartbeat 송신

## 작성 항목

| 항목 | 내용 |
| --- | --- |
| Toolchain/IDE 버전 | AURIX Development Studio, 세부 버전 TBD |
| 기준 예제 | Infineon `ASCLIN_UART_1_KIT_TC375_LK` |
| 통신 채널 | ASCLIN UART 초기 적용 |
| heartbeat 송신 주기 | 100 ms 초기값 |
| health status 정의 | TBD |
| isolate 명령 처리 방식 | TBD |
| fault injection 방법 | TBD |

## Bring-up 순서

1. ADS에서 `ASCLIN_UART_1_KIT_TC375_LK` 예제를 import한다.
2. 예제 프로젝트가 수정 없이 build/flash 되는지 확인한다.
3. 이 저장소의 Primary ECU overlay 코드를 적용한다.
4. debugger에서 `g_primaryEcuRuntime.sequenceCounter` 증가를 확인한다.
5. 실제 Supervisor 연결 전 UART 핀과 전압 레벨을 확정한다.
