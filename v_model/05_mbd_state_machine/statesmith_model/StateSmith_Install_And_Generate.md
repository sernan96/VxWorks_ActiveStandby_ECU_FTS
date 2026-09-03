# StateSmith Install And Generate

## 현재 PC 상태

확인 결과 이 PC에는 `.NET SDK`가 설치되어 있지만 `ss.cli` 또는 `statesmith` 명령은 아직 없다.

## 설치

StateSmith 공식 문서는 두 가지 방식을 안내한다.

| 방식 | 명령/방법 | 비고 |
| --- | --- | --- |
| dotnet tool | `dotnet tool install --global StateSmith.Cli` | .NET SDK가 있을 때 가장 간단 |
| standalone binary | GitHub release에서 Windows x64 zip 다운로드 | dotnet 없이 실행 가능 |

이 PC는 `.NET SDK`가 있으므로 dotnet tool 방식이 편하다.

```powershell
dotnet tool install --global StateSmith.Cli
ss.cli --version
```

## 코드 생성

```powershell
cd "C:\잡다한 프로젝트\VxWorks_ActiveStandby_ECU_FTS\v_model\05_mbd_state_machine"
ss.cli run --here --recursive
```

강제 재생성 또는 상세 로그가 필요하면 다음을 사용한다.

```powershell
ss.cli run --here --recursive --rebuild --verbose
```

개발 중 파일 변경을 감시하며 재생성하려면 다음을 사용한다.

```powershell
ss.cli run --here --recursive --watch
```

## 생성 후 확인

예상 산출물은 다음 위치에 둔다.

| 산출물 | 위치 |
| --- | --- |
| generated header | `generated_c/FailoverSupervisor.h` |
| generated source | `generated_c/FailoverSupervisor.c` |
| simulator html | `statesmith_model/FailoverSupervisor.sim.html` 또는 StateSmith CLI 출력 위치 |

실제 출력 파일명과 위치는 StateSmith CLI 설정에 따라 달라질 수 있으므로 첫 생성 후 `StateSmith_Workflow.md`를 갱신한다.

