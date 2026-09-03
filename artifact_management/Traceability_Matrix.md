# Traceability Matrix

요구사항, 설계, 구현, 테스트, 인수 조건의 연결을 추적한다.

| UR | SG/HAZ | FSR | SR | SWR | ARCH/STM/StateSmith | Test Case | AC | 상태 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| UR-01 | SG-04, HAZ-03 | FSR-04 | SR-01 | SWR-SUP-07, SWR-BCK-01 | ARCH-01, STM-ST-02, StateSmith `NORMAL` | TC-SYS-01 | AC-01 | Draft |
| UR-02 | SG-01, HAZ-01 | FSR-01 | SR-02 | SWR-SUP-01, SWR-PRI-01 | IF-01 | TC-SIT-01 | AC-02 | Draft |
| UR-03 | SG-01, HAZ-01 | FSR-01 | SR-03 | SWR-SUP-02, SWR-SUP-03 | STM-ST-03 | TC-SIT-03 | AC-02 | Draft |
| UR-04 | SG-03, HAZ-02 | FSR-03 | SR-04 | SWR-SUP-02 | STM-ST-03 | TC-SIT-02, TC-SYS-03 | AC-04 | Draft |
| UR-05 | SG-02 | FSR-02 | SR-05 | SWR-SUP-04, SWR-BCK-02 | IF-03, StateSmith `FAILOVER_IN_PROGRESS` | TC-SYS-02 | AC-03 | Draft |
| UR-06 | SG-02 | FSR-02 | SR-06 | SWR-SUP-04, SWR-SUP-05 | measurement tool | Failover timing test | AC-03 | Draft |
| UR-07 | SG-02 | FSR-02 | SR-07 | SWR-SUP-05, SWR-BCK-03 | IF-04 | TC-SIT-04 | AC-03 | Draft |
| UR-08 | SG-05, HAZ-04 | FSR-05 | SR-08 | SWR-SUP-06, SWR-BCK-04 | STM-ST-07, StateSmith `SAFE` | TC-SYS-04 | AC-05 | Draft |
| UR-09 | SG-04, HAZ-03 | FSR-04 | SR-09 | SWR-SUP-07, SWR-PRI-03 | active owner design | TC-SYS-05 | AC-06 | Draft |
| UR-10 | SG-06, HAZ-05 | FSR-06 | SR-10 | SWR-SUP-08 | STM-ST-06 | TC-SYS-05 | AC-07 | Draft |
| UR-11 | SG-06, HAZ-05 | FSR-06 | SR-11 | SWR-SUP-08 | failback guard | TC-SYS-06 | AC-07 | Draft |
| UR-12 | HAZ-01..05 | FSR-07 | SR-12 | SWR-SUP-09 | Event Logger | log inspection | AC-08 | Draft |
| UR-13 | HAZ-01..05 | FSR-07 | SR-13 | SWR-SUP-10 | Status Interface | status demo | AC-08 | Draft |
| UR-14 | 전체 | FSR-08 | SR-14 | SWR-SUP-11, SWR-PRI-04, SWR-BCK-04 | Fault Injection Interface | fault injection tests | AC-09 | Draft |
| UR-15 | 전체 | FSR-08 | SR-15 | SWR-SUP-11 | repeatability analysis | TC-SYS-07 | AC-09 | Draft |
