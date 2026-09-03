# Implementation Plan

## 구현 순서

1. `shared/interfaces`에 ECU 상태, system state, command, event ID 정의
2. `shared/protocols`에 heartbeat 및 activation message format 정의
3. Backup ECU Simulator 최소 구현
4. TC375 Lite Kit Primary ECU heartbeat 송신 및 fault injection stub 구현
5. Safety Supervisor heartbeat monitor 구현
6. StateSmith 모델 작성 및 generated C 코드 생성
7. Supervisor 상태 머신 wrapper와 VxWorks adapter 작성
8. Backup activation 및 acknowledgement 처리 구현
9. Safe State 전환 처리 구현
10. Logging, status query, failover time measurement 구현
11. VxWorks target 통합 및 보드 간 통신 검증

## 보드별 구현 항목

| 보드 | 우선 구현 | 후속 구현 |
| --- | --- | --- |
| Safety Supervisor | 상태 머신, heartbeat 감시, failover 제어 | VxWorks task tuning, logging persistence |
| Primary ECU | TC375 Lite Kit heartbeat 송신, 상태 보고 | 실제 Supervisor UART 연결, isolate command 수신 |
| Backup ECU | simulator activation/ack | Arduino 또는 별도 target 포팅 |

## 완료 기준

- `SR-01`부터 `SR-15`까지 대응 소프트웨어 요구사항이 구현되어야 한다.
- 모든 주요 상태 전이가 로그로 확인되어야 한다.
- fault injection을 통해 정상, 오탐 방지, failover 성공, failover 실패 safe state 시나리오가 재현되어야 한다.
- StateSmith 모델과 generated C 코드의 버전 관계가 산출물 관리 폴더에 기록되어야 한다.
