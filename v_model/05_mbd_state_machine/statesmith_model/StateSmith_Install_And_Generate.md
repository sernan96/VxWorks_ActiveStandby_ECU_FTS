# StateSmith Install And Generate

## 현재 PC 상태

확인 결과 이 PC에는 `.NET SDK 9.0.308`이 설치되어 있다.

StateSmith CLI는 프로젝트 로컬 dotnet tool로 설치했다.

| 항목 | 상태 |
| --- | --- |
| `.NET SDK` | 설치됨, `9.0.308` |
| StateSmith CLI | 설치됨, `0.22.2` |
| 실행 방식 | `dotnet tool run ss.cli -- <args>` |
| Tool manifest | `.config/dotnet-tools.json` |

## 설치

StateSmith 공식 문서는 두 가지 방식을 안내한다.

| 방식 | 명령/방법 | 비고 |
| --- | --- | --- |
| dotnet tool | `dotnet tool install --global StateSmith.Cli` | .NET SDK가 있을 때 가장 간단 |
| standalone binary | GitHub release에서 Windows x64 zip 다운로드 | dotnet 없이 실행 가능 |

이 PC는 `.NET SDK`가 있으므로 프로젝트 로컬 dotnet tool 방식을 사용한다.

```powershell
dotnet new tool-manifest
dotnet tool install --local StateSmith.Cli --version 0.22.2
dotnet tool run ss.cli -- --version
```

## 코드 생성

```powershell
cd "C:\잡다한 프로젝트\VxWorks_ActiveStandby_ECU_FTS\v_model\05_mbd_state_machine"
dotnet tool run ss.cli -- run -h -r -b --no-ask --lang C99 --no-csx
```

강제 재생성 또는 상세 로그가 필요하면 다음을 사용한다.

```powershell
dotnet tool run ss.cli -- run -h -r -b --no-ask --lang C99 --no-csx --verbose
```

개발 중 파일 변경을 감시하며 재생성하려면 다음을 사용한다.

```powershell
dotnet tool run ss.cli -- run -h -r -w --no-ask --lang C99 --no-csx
```

## 생성 후 확인

예상 산출물은 다음 위치에 둔다.

| 산출물 | 위치 |
| --- | --- |
| generated header | `generated_c/FailoverSupervisor.h` |
| generated source | `generated_c/FailoverSupervisor.c` |
| simulator html | `statesmith_model/FailoverSupervisor.sim.html` |

## 생성 결과

2026-09-03 기준 StateSmith CLI 0.22.2로 생성에 성공했다.

컴파일 검증은 아직 수행하지 못했다. 현재 PC의 PATH에 `gcc`, `clang`, `cl`, VxWorks SDK compiler가 없기 때문이다. 컴파일 검증은 VxWorks SDK 또는 host C compiler 설치 후 수행한다.
