# Backup ECU - Software ECU Simulator

## 책임

- 정상 상태에서는 Standby 유지
- Supervisor의 활성화 요청 수신
- 활성화 완료 후 상태 보고
- Primary ECU 고장 시 주 기능 대체 수행
- 활성화 실패 시 Supervisor가 Safe State로 전환할 수 있도록 실패 상태 제공

## 향후 대체 가능 대상

초기 구현은 Software ECU Simulator를 사용한다. 필요 시 Arduino Uno 등 별도 하드웨어 보드로 교체할 수 있도록 인터페이스는 `shared/interfaces/`와 `shared/protocols/`에 분리한다.

## 폴더

| 경로 | 내용 |
| --- | --- |
| `src/` | Simulator 또는 Backup ECU 애플리케이션 구현 |
| `include/` | Backup ECU 헤더 및 인터페이스 정의 |
| `tests/` | 활성화 성공/실패, standby 유지 테스트 |
| `docs/` | simulator 실행 방법, Arduino 대체 시 포팅 메모 |

