# Board Workspaces

보드별 구현과 보드 특화 문서를 분리해 관리한다.

| 보드 | 경로 | 역할 |
| --- | --- | --- |
| Safety Supervisor | `01_safety_supervisor_rpi4_vxworks/` | 전체 ECU 상태 감시, fault 판단, failover 제어, safe state 제어 |
| Primary ECU | `02_primary_ecu_tc375/` | 정상 운용 시 주 기능 수행, heartbeat 및 상태 제공 |
| Backup ECU | `03_backup_ecu_simulator/` | Primary ECU 고장 시 주 기능 대체 수행, 초기에는 Software ECU Simulator로 구현 |

각 보드 폴더는 `src`, `include`, `tests`, `docs` 하위 폴더를 가진다.

