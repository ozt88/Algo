---
phase: 05-boj-1117
plan: 01
subsystem: algorithm
tags: [go, boj, geometry, math, int64]

requires: []
provides:
  - BOJ 1117 O(1) 풀이 (solve, parseInput, Input struct)
  - main_test.go 6개 테스트 케이스
  - history/2026-W14-BOJ-1117.md 아카이브
affects: []

tech-stack:
  added: []
  patterns:
    - parseInput + solve(Input) int64 단일 파일 구조
    - table-driven TestSolve with int64 overflow test
    - nolint:errcheck,gosec for fmt.Sscan in competitive programming context

key-files:
  created:
    - main.go
    - main_test.go
    - history/2026-W14-BOJ-1117.md
  modified: []

key-decisions:
  - "x/y 방향 독립 처리: painted_area = painted_x × painted_y"
  - "overlap = min(f, W-f), doubled = max(0, min(x2, overlap) - x1)"
  - "painted_y = (y2-y1) × (c+1) — 가로 접기 c회 → c+1배"
  - "int64 필수 — W×H ≤ 10^18 범위"

patterns-established:
  - "Input 구조체 int64 필드 + parseInput(bufio.Scanner) 패턴"
  - "min/max int64 헬퍼 함수 (Go 1.21 이전 호환)"

requirements-completed: [PROB-01, WF-01, WF-02, WF-03, WF-04, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02]

duration: 6min
completed: 2026-04-04
---

# Phase 05 Plan 01: BOJ 1117 색칠 1 Summary

**x/y 방향 독립 O(1) 풀이로 BOJ 1117을 해결 — overlap 구간 doubled×2+single, painted_y=(y2-y1)×(c+1), int64 보장**

## Performance

- **Duration:** ~6 min
- **Started:** 2026-04-04T01:50:30Z
- **Completed:** 2026-04-04T01:56:30Z
- **Tasks:** 2
- **Files modified:** 3

## Accomplishments
- main.go에 BOJ 1117 풀이 구현 (이전 BOJ 25208 cubeState/rollTable 코드 완전 교체)
- main_test.go에 6개 table-driven 테스트 케이스 통과 (int64 오버플로 케이스 포함)
- golangci-lint 0 issues 달성
- history/2026-W14-BOJ-1117.md UTF-8 BOM 아카이브 작성

## Task Commits

Each task was committed atomically:

1. **Task 1: main.go I/O 스캐폴드 + solve() 구현 및 main_test.go 테스트** - `b22e454` (feat)
2. **Task 2: history 아카이브 작성** - `4541ef7` (chore)

## Files Created/Modified
- `main.go` - BOJ 1117 풀이: Input struct, parseInput, solve, min/max int64 헬퍼
- `main_test.go` - 6개 table-driven 테스트 (기본, 세로+가로접기, int64 오버플로, f=0, x1=x2, c최대값)
- `history/2026-W14-BOJ-1117.md` - 풀이 아카이브 (UTF-8 BOM)

## Decisions Made
- int64 사용 확정: W×H ≤ 10^18 범위를 안전하게 처리하기 위해
- `//nolint:errcheck,gosec` 주석: 경쟁 프로그래밍 컨텍스트에서 fmt.Sscan 에러 무시가 표준 패턴
- min/max int64 헬퍼 분리: Go 1.21 builtins에 의존하지 않아 이전 버전 호환성 확보

## Deviations from Plan

### Auto-fixed Issues

**1. [Rule 1 - Bug] gosec G104 lint 에러 수정**
- **Found during:** Task 1 (golangci-lint 실행)
- **Issue:** `fmt.Sscan` nolint 주석이 errcheck만 억제하고 gosec는 미억제
- **Fix:** `//nolint:errcheck` → `//nolint:errcheck,gosec`
- **Files modified:** main.go
- **Verification:** golangci-lint 0 issues
- **Committed in:** b22e454 (Task 1 commit)

**2. [Rule 1 - Bug] lll(줄 길이) lint 에러 수정**
- **Found during:** Task 1 (golangci-lint 실행)
- **Issue:** main_test.go int64 오버플로 테스트 케이스 한 줄이 121자로 120자 제한 초과
- **Fix:** Input 구조체 리터럴을 여러 줄로 분리
- **Files modified:** main_test.go
- **Verification:** golangci-lint 0 issues
- **Committed in:** b22e454 (Task 1 commit)

---

**Total deviations:** 2 auto-fixed (2 Rule 1 - Bug, lint 에러)
**Impact on plan:** lint 에러는 PLAN.md에서 golangci-lint 통과를 요구했으므로 필수 수정. 로직 변경 없음.

## Issues Encountered
- golangci-lint가 PATH에 없었으나 scoop shim(`/c/Users/DELL/scoop/shims/golangci-lint.exe`)으로 실행 성공

## User Setup Required
None - no external service configuration required.

## Next Phase Readiness
- BOJ 1117 풀이 완료, BOJ에 제출 준비 완료
- 다음 문제 (BOJ 30867 또는 BOJ 30398)를 위해 main.go/main_test.go 덮어쓰기 준비됨

---
*Phase: 05-boj-1117*
*Completed: 2026-04-04*
