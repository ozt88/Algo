# Phase 6: BOJ 30867 과제가 너무 많아 - Context

**Gathered:** 2026-04-04
**Status:** Ready for planning

<domain>
## Phase Boundary

BOJ 30867 (과제가 너무 많아)을 Go로 풀이하여 AC를 받는다.
길이 L 문자열에 N번 두통 연산(wh→hw swap)을 적용한 결과를 출력하는 문제.

</domain>

<decisions>
## Implementation Decisions

### 알고리즘 핵심 방향
- **D-01:** w와 h가 아닌 문자는 장벽 — 문자열을 w/h 세그먼트로 분리하여 각각 처리
- **D-02:** 각 세그먼트 내에서 h는 왼쪽으로 버블링. 한 pass에 최대 1칸 이동
- **D-03:** 각 h의 최종 위치 = 원래위치 - min(왼쪽_w개수, N). 연속 h끼리 겹침 불가 (수학적으로 증명됨)
- **D-04:** 시간복잡도 O(L). N번 시뮬레이션 불필요

### 구현 방식
- **D-05:** 세그먼트별로 h 위치 수집 → 새 위치 계산 → w/h 재배치 → 원래 문자열에 삽입
- **D-06:** int로 충분 (L, N ≤ 200,000)

### Claude's Discretion
- I/O 스캐폴드 구조
- 세그먼트 분리 구현 세부사항
- 테스트 케이스 선정

</decisions>

<canonical_refs>
## Canonical References

No external specs — requirements fully captured in decisions above.

</canonical_refs>

<code_context>
## Existing Code Insights

### Reusable Assets
- main.go / main_test.go 단일 파일 구조
- justfile: lint, test, build, run 태스크

### Established Patterns
- parseInput → solve 구조
- bufio.Scanner + fmt.Sscan 파싱
- table-driven 테스트

### Integration Points
- main.go에 solve() 구현
- main_test.go에 예제 3개 + 엣지 케이스 테스트

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

*Phase: 06-boj-30867*
*Context gathered: 2026-04-04*
