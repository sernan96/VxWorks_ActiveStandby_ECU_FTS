# User Requirements Specification

## 문서 목적

Primary ECU의 고장을 감지하고 Backup ECU로 기능을 전환하는 Active-Standby 구조의 Fault-Tolerant 시스템에 대해 사용자 관점의 요구사항을 정의한다.

## 시스템 개요

| 구성 요소 | 구현 대상 | 역할 |
| --- | --- | --- |
| Safety Supervisor | Raspberry Pi 4 + VxWorks | ECU 상태 감시, fault 판단, failover 제어 |
| Primary ECU | TC375 | 정상 운용 시 주 기능 수행 |
| Backup ECU | Software ECU Simulator, 추후 Arduino Uno 가능 | Primary ECU 고장 시 주 기능 대체 |

## 사용자 요구사항

| ID | 요구사항 | 사용자 기대 |
| --- | --- | --- |
| UR-01 | 시스템은 Primary ECU가 정상적인 상태에서는 Primary ECU가 시스템의 주 기능을 수행하도록 해야 한다. | 정상 상태에서 불필요하게 Backup ECU로 전환되지 않아야 한다. |
| UR-02 | 시스템은 운용 중 Primary ECU의 정상 동작 여부를 지속적으로 감시해야 한다. | Primary ECU 이상을 시스템이 스스로 인지해야 한다. |
| UR-03 | 시스템은 Primary ECU에 지속적인 이상이 발생했을 경우 이를 고장으로 판단할 수 있어야 한다. | 실제 고장을 사람이 확인하기 전에 자동 감지해야 한다. |
| UR-04 | 시스템은 일시적인 통신 지연 또는 단일 상태 정보 손실만으로 Primary ECU를 고장으로 판단해서는 안 된다. | 통신 품질 저하로 인한 불필요한 전환을 방지해야 한다. |
| UR-05 | Primary ECU의 고장이 확인되면 시스템은 사람의 개입 없이 Backup ECU로 기능을 전환해야 한다. | 기능 중단 시간을 최소화해야 한다. |
| UR-06 | Primary ECU의 고장이 발생한 이후 Backup ECU의 기능 전환은 사전에 정의된 허용 시간 내에 완료되어야 한다. | 고장 감지와 전환이 지나치게 길어지지 않아야 한다. |
| UR-07 | 시스템은 Backup ECU에 활성화를 요청한 것만으로 기능 전환 완료를 판단하지 않고 실제 활성화 여부를 확인해야 한다. | Backup ECU가 미동작인데 전환 성공으로 오판하지 않아야 한다. |
| UR-08 | Primary ECU 고장 이후 Backup ECU까지 정상적으로 활성화되지 못할 경우 시스템은 Safe State로 전환해야 한다. | 정상 기능이 불가능할 때 잘못된 출력을 계속 생성하지 않아야 한다. |
| UR-09 | 시스템은 Primary ECU와 Backup ECU가 동시에 주 기능을 수행하는 상태가 발생하지 않도록 해야 한다. | 상충 출력 발생을 방지해야 한다. |
| UR-10 | Backup ECU가 활성화된 이후 Primary ECU가 다시 정상 상태로 복구되더라도 즉시 Primary ECU로 되돌려서는 안 된다. | 반복 전환을 방지해야 한다. |
| UR-11 | Primary ECU 중심 정상 상태 복귀는 명시적인 복귀 조건을 만족한 경우에만 수행되어야 한다. | 충분히 확인되지 않은 상태로 자동 복귀하지 않아야 한다. |
| UR-12 | 시스템은 주요 고장 발생 및 상태 전환 정보를 기록해야 한다. | 사후 원인 확인이 가능해야 한다. |
| UR-13 | 운영자는 현재 시스템 상태와 활성 ECU를 확인할 수 있어야 한다. | 초기화, 정상, failover, backup 운용, 복구 감지, safe state를 구분해야 한다. |
| UR-14 | 개발자 또는 검증자는 의도적으로 고장 상황을 발생시켜 기능을 반복 검증할 수 있어야 한다. | 실제 고장을 기다리지 않고 안전 메커니즘을 검증해야 한다. |
| UR-15 | 동일한 고장 조건을 반복 주입했을 때 시스템은 일관된 결과를 보여야 한다. | Failover 결과가 timing이나 실행 순서에 우연히 좌우되지 않아야 한다. |

## Hazard

| ID | 위험 상황 |
| --- | --- |
| HAZ-01 | Primary ECU가 실제로 고장났음에도 정상으로 판단하여 잘못된 기능 수행을 계속함 |
| HAZ-02 | 일시적 통신 오류를 고장으로 오판하여 불필요하게 Backup ECU가 활성화됨 |
| HAZ-03 | Primary ECU와 Backup ECU가 동시에 주 기능을 수행하여 상충 출력 발생 |
| HAZ-04 | Primary ECU와 Backup ECU가 모두 정상 기능을 제공하지 못하는데 정상처럼 동작 |
| HAZ-05 | 복구가 완전히 확인되지 않은 Primary ECU로 자동 전환되어 반복 장애 발생 |

## Safety Goal

| ID | 목표 |
| --- | --- |
| SG-01 | Primary ECU의 고장은 시스템이 감지할 수 있어야 한다. |
| SG-02 | Primary ECU 고장 시 Backup ECU가 정상적으로 기능을 이어받을 수 있어야 한다. |
| SG-03 | 일시적인 오류가 실제 ECU 고장으로 잘못 판단되어서는 안 된다. |
| SG-04 | Primary ECU와 Backup ECU가 동시에 시스템의 주 기능을 수행해서는 안 된다. |
| SG-05 | 정상적인 Failover가 불가능한 경우 시스템은 Safe State로 전환되어야 한다. |
| SG-06 | Failover 이후 불안정한 Primary ECU로 자동 복귀해서는 안 된다. |

