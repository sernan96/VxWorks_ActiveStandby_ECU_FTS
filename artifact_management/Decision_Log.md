# Decision Log

| 날짜 | 결정 ID | 결정 내용 | 배경 | 영향 |
| --- | --- | --- | --- | --- |
| 2026-09-03 | DEC-001 | 보드별 작업공간을 Safety Supervisor, Primary ECU, Backup ECU 세 영역으로 분리한다. | 명세서의 세 주요 구성 요소와 책임 분리가 명확함 | 구현, 테스트, 문서 산출물 관리가 보드 단위로 가능 |
| 2026-09-03 | DEC-002 | Backup ECU 초기 구현은 Software ECU Simulator 폴더에서 시작한다. | 명세서에서 초기 구현 대상을 simulator로 정의함 | 추후 Arduino 등 하드웨어로 대체 가능하도록 shared interface 분리 필요 |
| 2026-09-03 | DEC-003 | V-Model 산출물은 단계별 폴더와 요구사항 추적표로 관리한다. | 사용자 요구사항부터 Validation까지 추적성 유지 필요 | 변경 시 Traceability Matrix 갱신 필요 |
| 2026-09-03 | DEC-004 | Failover MBD는 StateSmith를 기준 도구로 사용한다. | 임베디드 상태 머신 생성과 재생성 가능한 C 코드 관리에 적합함 | 모델 원본, 생성 코드, VxWorks adapter를 분리 관리 |
| 2026-09-03 | DEC-005 | ISO 26262는 인증 준수가 아닌 lightweight tailoring으로 적용한다. | 토이프로젝트 범위에서 표준 전체 적용은 과도하지만 안전 lifecycle 산출물은 어필 가치가 있음 | Item Definition, HARA-lite, FSC, traceability, evidence만 관리 |
