# Primary ECU - TC375

## 책임

- 정상 상태에서 시스템 주 기능 수행
- Safety Supervisor로 주기적 heartbeat 전송
- 현재 ECU 상태 및 활성 상태 보고
- Supervisor의 격리 또는 비활성화 명령 수신 시 주 기능 중지
- Fault Injection 검증을 위한 정지, 지연, 상태 오류 주입 지원

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

