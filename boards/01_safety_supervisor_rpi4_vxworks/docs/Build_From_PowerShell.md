# Build From PowerShell

## 전제

- Ubuntu-22.04 WSL에 VxWorks SDK for Raspberry Pi 4가 설치되어 있어야 한다.
- SDK 환경 파일은 `~/sdk/windriver/rpi4-26.03/sdkenv.sh`라고 가정한다.
- 프로젝트는 Ubuntu 안에 clone되어 있다고 가정한다.

## 권장 프로젝트 위치

```bash
~/work/VxWorks_ActiveStandby_ECU_FTS
```

Windows 쪽 `C:\잡다한 프로젝트`에서 바로 빌드할 수도 있지만, 한글 경로와 `/mnt/c` 파일시스템 성능 문제를 피하려면 Ubuntu 내부에 clone하는 것이 좋다.

## PowerShell에서 clone

```powershell
wsl -d Ubuntu-22.04 -e bash -lc "mkdir -p ~/work && cd ~/work && git clone https://github.com/sernan96/VxWorks_ActiveStandby_ECU_FTS.git"
```

이미 clone되어 있으면:

```powershell
wsl -d Ubuntu-22.04 -e bash -lc "cd ~/work/VxWorks_ActiveStandby_ECU_FTS && git pull"
```

## PowerShell에서 SDK 확인

Ubuntu의 `/bin/sh`가 `dash`를 가리키면 VxWorks SDK의 `sdkenv.sh`가 다음 메시지로 실패한다.

```text
The default shell is dash, please change your default shell to bash.
```

이 경우 PowerShell에서 Ubuntu로 들어간 뒤:

```powershell
wsl -d Ubuntu-22.04
```

Ubuntu 안에서:

```bash
sudo dpkg-reconfigure dash
```

질문이 나오면 `No`를 선택한다. 그러면 `/bin/sh`가 `bash`를 가리키도록 바뀐다.

확인:

```bash
readlink /bin/sh
```

`bash`가 나오면 SDK 환경 스크립트를 사용할 수 있다.

```powershell
wsl -d Ubuntu-22.04 -e bash -lc "cd ~/sdk/windriver/rpi4-26.03 && source ./sdkenv.sh && echo \$CC && which wrdbg"
```

## PowerShell에서 Supervisor 빌드

```powershell
wsl -d Ubuntu-22.04 -e bash -lc "cd ~/sdk/windriver/rpi4-26.03 && source ./sdkenv.sh && cd ~/work/VxWorks_ActiveStandby_ECU_FTS/boards/01_safety_supervisor_rpi4_vxworks && make clean && make print-env && make"
```

성공 시 결과물:

```text
boards/01_safety_supervisor_rpi4_vxworks/build/supervisor.vxe
```

## 실행 목적

현재 `supervisor.vxe`는 실제 TC375 heartbeat 수신 전 단계의 self-test RTP이다. 실행하면 StateSmith generated state machine이 다음 흐름으로 전이되는지 콘솔 로그로 확인한다.

```text
INIT -> NORMAL -> PRIMARY_FAULT_CANDIDATE -> FAILOVER_IN_PROGRESS -> DEGRADED -> RECOVERY_DETECTED -> NORMAL
```

다음 단계에서 UDP 또는 UART heartbeat receiver를 붙이면 TC375 Lite Kit Primary ECU와 end-to-end 검증할 수 있다.
