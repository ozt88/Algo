---
phase: 07-boj-30398
plan: "01"
subsystem: algorithm
tags: [combinatorics, multinomial, modular-arithmetic, golang]
dependency_graph:
  requires: []
  provides: [BOJ-30398-solution]
  affects: [main.go, main_test.go, history]
tech_stack:
  added: []
  patterns: [factorial-precomputation, fermat-inverse, multinomial-coefficient, parse-input-solve]
key_files:
  created:
    - history/2026-W14-BOJ-30398.md
  modified:
    - main.go
    - main_test.go
decisions:
  - "역팩토리얼 전처리 방향: top-down (invFact[maxN] 계산 후 하향 재귀)"
  - "strconv.Atoi blank-identifier assignment — nolint 불필요, errcheck 미적용"
metrics:
  duration: ~8min
  completed_date: "2026-04-04"
  tasks_completed: 2
  files_modified: 3
---

# Phase 07 Plan 01: BOJ 30398 대구일과학고등학교 Summary

**One-liner:** 팩토리얼+역팩토리얼 전처리 O(N×d) 후 구간별 다항계수 곱으로 d차원 경로 수를 mod 10^9+7로 계산

## What Was Built

BOJ 30398 풀이를 main.go에 완전 구현했다. 이전 문제(BOJ 30867) 코드를 제거하고 새 Input 구조체 및 solve 함수로 교체했다.

- `parseInput`: bufio.Scanner로 "N D P" 첫 줄 후 P개 좌표 읽기
- `solve`: 팩토리얼·역팩토리얼 전처리 → 구간별 다항계수 곱 → mod 10^9+7 반환
- `modpow`: 페르마 소정리용 빠른 거듭제곱
- `main_test.go`: 5개 테스트 케이스 (예제, P=0, 불가능, 경계, 최솟값)

## Tasks Completed

| Task | Name | Commit | Files |
|------|------|--------|-------|
| 1 | main.go I/O 스캐폴드 + solve() 구현 및 테스트 | 4f4535a | main.go, main_test.go |
| 2 | history 아카이브 작성 | 8e131a1 | history/2026-W14-BOJ-30398.md |

## Verification Results

- `go test -v ./...`: 5/5 PASS
- `golangci-lint run .`: 0 issues
- `history/2026-W14-BOJ-30398.md`: exists, UTF-8 BOM confirmed

## Deviations from Plan

### Auto-fixed Issues

**1. [Rule 1 - Bug] Removed unnecessary `//nolint:errcheck` on blank-identifier strconv.Atoi**
- **Found during:** Task 1 lint run
- **Issue:** `golangci-lint` reported `nolintlint` — the directive was unused because `errcheck` does not flag blank-identifier `_` assignments
- **Fix:** Removed the nolint comment; blank identifier pattern is already idiomatic and needs no suppression
- **Files modified:** main.go
- **Commit:** Included in 4f4535a (fixed before commit)

## Known Stubs

None — all test cases use concrete expected values; solve() returns a computed int64 with no placeholder data.

## Self-Check: PASSED

- main.go exists and contains `func solve`, `type Input struct`, `func parseInput`, `func modpow`
- main_test.go exists and contains `func TestSolve` with 5 entries
- history/2026-W14-BOJ-30398.md exists with UTF-8 BOM (ef bb bf)
- Commits 4f4535a and 8e131a1 verified in git log
- solve(N=4,d=2,P=1,point=(2,3)) == 9 confirmed by test pass
