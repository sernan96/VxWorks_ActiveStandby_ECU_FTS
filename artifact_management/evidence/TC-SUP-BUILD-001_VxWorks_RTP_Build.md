# TC-SUP-BUILD-001 VxWorks RTP Build Evidence

## 목적

Safety Supervisor self-test RTP가 VxWorks SDK for Raspberry Pi 4 환경에서 빌드되는지 확인한다.

## 환경

| 항목 | 값 |
| --- | --- |
| 수행 일자 | 2026-09-04 |
| Host | Ubuntu-22.04 WSL |
| SDK | VxWorks SDK for Raspberry Pi 4, 26.03 |
| Compiler | `wr-cc` |
| Build target | `boards/01_safety_supervisor_rpi4_vxworks/build/supervisor.vxe` |

## 실행 명령

```bash
cd ~/sdk/windriver/rpi4-26.03
source ./sdkenv.sh
cd "/mnt/c/잡다한 프로젝트/VxWorks_ActiveStandby_ECU_FTS/boards/01_safety_supervisor_rpi4_vxworks"
make clean
make print-env
make
```

## 결과

빌드 성공.

```text
CC=wr-cc
TARGET=build/supervisor.vxe
GENERATED_DIR=../../v_model/05_mbd_state_machine/generated_c
wr-cc ... -rtp -static ... -o build/supervisor.vxe
```

생성된 `supervisor.vxe` 크기:

```text
1061944 bytes
```

## 경고

StateSmith generated C에서 unused parameter/function 경고 4건이 발생했다.

현재 단계에서는 self-test RTP 빌드 검증 목적이므로 허용한다. 후속 단계에서 generated-code warning policy를 정하거나, 필요 시 compiler warning suppression을 Makefile에 분리 적용한다.

