# Phase 5: BOJ 1117 색칠 1 - Context

**Gathered:** 2026-04-04
**Status:** Ready for planning

<domain>
## Phase Boundary

BOJ 1117 (색칠 1)을 discuss→plan→execute 워크플로우로 풀이하여 AC를 받는다.
W×H 종이를 세로·가로로 접은 뒤 직사각형을 칠하고 펼었을 때 색칠되지 않은 면적을 구하는 문제.

</domain>

<decisions>
## Implementation Decisions

### 알고리즘 핵심 방향
- **D-01:** x방향 접기와 y방향 접기를 독립적으로 처리한다. 접힌 좌표→원래 좌표 매핑이 각 축에서 독립이므로 칠해진 면적 = painted_x × painted_y.
- **D-02:** 답 = W×H - painted_x × painted_y

### y방향 (가로 접기)
- **D-03:** c+1개 구간 모두에 동일하게 스며들므로 painted_y = (y2-y1) × (c+1). 단순 곱셈.

### x방향 (세로 접기, x=f)
- **D-04:** 겹치는 구간 = [0, min(f, W-f)]. 이 구간 내 [x1,x2] 교집합 부분은 펼치면 ×2, 나머지는 ×1.
- **D-05:** painted_x = doubled×2 + single. 여기서 doubled = max(0, min(x2, overlap) - x1), single = (x2-x1) - doubled.

### 곱셈 정당성
- **D-06:** 펼친 후 x구간끼리 안 겹치고 y구간끼리 안 겹치므로 직교곱 면적 공식이 성립. 여러 직사각형의 합이지만 총 면적 = painted_x × painted_y 정확.

### 자료형
- **D-07:** W, H ≤ 10^9이므로 곱셈 시 int64 필수.

### Claude's Discretion
- I/O 스캐폴드 구조 (bufio.Scanner vs fmt.Scan)
- 엣지 케이스 테스트 선정

</decisions>

<canonical_refs>
## Canonical References

No external specs — requirements fully captured in decisions above.

</canonical_refs>

<code_context>
## Existing Code Insights

### Reusable Assets
- main.go / main_test.go 단일 파일 구조 (매 문제 덮어쓰기)
- justfile: lint, test, build, run 태스크

### Established Patterns
- parseInput → solve 구조 (Input 구조체 사용)
- bufio.Scanner + fmt.Sscan 파싱
- table-driven 테스트 (TestSolve, TestParseInput)

### Integration Points
- main.go에 solve() 구현
- main_test.go에 예제 6개 테스트 케이스 추가

</code_context>

<specifics>
## Specific Ideas

No specific requirements — open to standard approaches.

</specifics>

<deferred>
## Deferred Ideas

None — discussion stayed within phase scope.

</deferred>

---

*Phase: 05-boj-1117*
*Context gathered: 2026-04-04*
