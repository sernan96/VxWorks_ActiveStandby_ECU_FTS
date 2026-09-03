# Software Requirements Specification

## Safety Supervisor 요구사항

| ID | 요구사항 | 상위 요구사항 |
| --- | --- | --- |
| SWR-SUP-01 | Supervisor 소프트웨어는 Primary heartbeat 수신 task를 제공해야 한다. | SR-02 |
| SWR-SUP-02 | Supervisor 소프트웨어는 heartbeat timeout과 연속 실패 횟수를 기반으로 fault 후보 상태를 관리해야 한다. | SR-03, SR-04 |
| SWR-SUP-03 | Supervisor 소프트웨어는 fault 후보가 설정 기준을 만족할 때 Primary fault를 선언해야 한다. | SR-03 |
| SWR-SUP-04 | Supervisor 소프트웨어는 Primary fault 선언 후 Backup 활성화 명령을 전송해야 한다. | SR-05 |
| SWR-SUP-05 | Supervisor 소프트웨어는 Backup active acknowledgement를 timeout 내 확인해야 한다. | SR-07, SR-08 |
| SWR-SUP-06 | Supervisor 소프트웨어는 Backup 활성화 실패 시 `SAFE` 상태로 전환해야 한다. | SR-08 |
| SWR-SUP-07 | Supervisor 소프트웨어는 active ECU owner를 단일 값으로 관리해야 한다. | SR-09 |
| SWR-SUP-08 | Supervisor 소프트웨어는 Primary 복구 감지와 failback 수행을 분리해야 한다. | SR-10, SR-11 |
| SWR-SUP-09 | Supervisor 소프트웨어는 주요 이벤트를 timestamp와 함께 기록해야 한다. | SR-12 |
| SWR-SUP-10 | Supervisor 소프트웨어는 운영자 상태 조회 API 또는 CLI를 제공해야 한다. | SR-13 |
| SWR-SUP-11 | Supervisor 소프트웨어는 fault injection 명령을 처리해야 한다. | SR-14, SR-15 |

## Primary ECU 요구사항

| ID | 요구사항 | 상위 요구사항 |
| --- | --- | --- |
| SWR-PRI-01 | Primary ECU 소프트웨어는 정상 운용 중 주기적으로 heartbeat를 송신해야 한다. | SR-02 |
| SWR-PRI-02 | Primary ECU 소프트웨어는 현재 active 상태와 health status를 보고해야 한다. | SR-01, SR-03 |
| SWR-PRI-03 | Primary ECU 소프트웨어는 isolate 명령 수신 시 주 기능 출력을 중지해야 한다. | SR-09 |
| SWR-PRI-04 | Primary ECU 소프트웨어는 검증을 위해 heartbeat stop, delay, fault status 주입 모드를 제공해야 한다. | SR-14 |

## Backup ECU 요구사항

| ID | 요구사항 | 상위 요구사항 |
| --- | --- | --- |
| SWR-BCK-01 | Backup ECU 소프트웨어는 정상 상태에서 standby 상태를 유지해야 한다. | SR-01 |
| SWR-BCK-02 | Backup ECU 소프트웨어는 activation command 수신 후 주 기능을 활성화해야 한다. | SR-05 |
| SWR-BCK-03 | Backup ECU 소프트웨어는 활성화 성공 시 active acknowledgement를 송신해야 한다. | SR-07 |
| SWR-BCK-04 | Backup ECU 소프트웨어는 활성화 실패 주입 모드를 제공해야 한다. | SR-08, SR-14 |

