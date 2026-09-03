# Shared

보드 간 공유되는 인터페이스, 프로토콜, 테스트 유틸리티를 관리한다.

| 경로 | 내용 |
| --- | --- |
| `interfaces/` | ECU 상태, 명령, 이벤트, error code 공통 정의 |
| `protocols/` | heartbeat, activation request/ack, safe state notification 메시지 정의 |
| `test_tools/` | host 기반 simulator, message stub, timing helper |

공통 정의는 특정 보드의 구현 세부사항에 의존하지 않도록 유지한다.

