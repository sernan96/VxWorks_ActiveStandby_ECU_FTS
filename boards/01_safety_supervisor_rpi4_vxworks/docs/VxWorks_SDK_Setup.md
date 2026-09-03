# VxWorks SDK Setup - Raspberry Pi 4 Safety Supervisor

## 현재 상태

이 PC에는 VxWorks SDK가 아직 설치되어 있지 않다.

확인 결과:

- `vxprj` 명령 없음
- `wrtool` 명령 없음
- `WIND_*`, `VXWORKS_*` 환경변수 없음
- 일반적인 `C:\Program Files` 및 사용자 홈 경로에서 Wind River 설치 흔적 없음

## 무료 SDK 사용 방침

Wind River Labs의 VxWorks SDK는 Non-Commercial License Agreement, NCLA 조건으로 제공된다. 이 프로젝트는 학습 및 포트폴리오용 토이프로젝트이므로 무료 SDK 사용 목적과 맞지만, 다운로드와 사용 전 사용자가 직접 라이선스 조건을 확인하고 동의해야 한다.

## 대상 SDK

Safety Supervisor 대상 보드는 Raspberry Pi 4이므로 다음 SDK를 사용한다.

| 항목 | 값 |
| --- | --- |
| Target | Raspberry Pi 4 / Raspberry Pi 4B |
| OS | VxWorks |
| SDK | VxWorks SDK for Raspberry Pi 4 |
| 용도 | Supervisor application build, deploy, debug |

Wind River Labs Forum 기준으로 VxWorks SDK for Raspberry Pi 4의 최신 공개 항목은 VxWorks 26.03 기반 `1.9.0`, release date `2026-05-07`이다.

## Host 주의사항

Wind River Labs의 SDK 안내는 특별히 명시되지 않는 한 Linux host를 기준으로 한다. 따라서 이 프로젝트의 개발 환경은 다음처럼 나누는 것을 권장한다.

| 영역 | 권장 환경 |
| --- | --- |
| TC375 Lite Kit Primary ECU | Windows + AURIX Development Studio |
| Raspberry Pi 4 VxWorks Supervisor | Linux host 또는 WSL/별도 Linux 머신 + VxWorks SDK |
| 문서/추적성 관리 | 현재 GitHub 저장소 |

Windows에서 ADS로 TC375를 개발하는 것과 VxWorks SDK로 Raspberry Pi 4 Supervisor application을 빌드하는 것은 별도 toolchain이다.

## 설치 절차

1. Wind River Labs의 VxWorks SDK 다운로드 페이지 또는 forum에서 `VxWorks SDK for Raspberry Pi 4`를 찾는다.
2. NCLA 내용을 읽고 동의한다.
3. Linux host에 SDK archive를 다운로드한다.
4. 원하는 위치에 압축을 해제한다.
5. SDK 환경 파일을 source한다.

```bash
cd <SDK_DIR>
source toolkit/wind_sdk_env.linux
```

6. compiler와 debugger 명령이 PATH에 잡혔는지 확인한다.

```bash
which $CC
which wrdbg
```

## Supervisor application 빌드 방향

초기 Supervisor는 user-space RTP보다 DKM 또는 일반 command-line app 중 어느 쪽이 좋은지 비교 후 결정한다.

| 방식 | 장점 | 주의점 |
| --- | --- | --- |
| RTP | user-space 격리, app 단위 배포 쉬움 | 실시간성/드라이버 접근 제약 확인 필요 |
| DKM | kernel task와 직접 통합 쉬움 | 잘못된 접근 시 system 영향 큼 |

이 프로젝트의 첫 목표는 상태 머신, heartbeat 수신, logging 검증이므로 RTP로 시작하고, timing 또는 I/O 제약이 생기면 DKM으로 옮기는 방식을 권장한다.

## 다음 구현 작업

1. Linux host에 VxWorks SDK 설치
2. `boards/01_safety_supervisor_rpi4_vxworks`에 SDK용 Makefile 또는 CMakeLists 추가
3. StateSmith generated C를 Supervisor build에 포함
4. UART 또는 UDP heartbeat receiver 구현
5. TC375 Lite Kit Primary ECU heartbeat와 end-to-end 연동

