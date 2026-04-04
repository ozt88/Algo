# Phase 7: BOJ 30398 대구일과학고등학교 - Context

**Gathered:** 2026-04-04
**Status:** Ready for planning

<domain>
## Phase Boundary

BOJ 30398 (대구일과학고등학교)을 Go로 풀이하여 AC를 받는다.
d차원 격자에서 (1,...,1)→(N,...,N)으로 P개 중간점을 순서대로 거치는 경로 수를 mod 10^9+7로 구하는 문제.

</domain>

<decisions>
## Implementation Decisions

### 알고리즘 핵심 방향
- **D-01:** 구간 분할 — 시작→점1→점2→...→점P→끝 = P+1개 구간으로 나눔
- **D-02:** 각 구간의 경로 수 = 다항계수(다중집합 순열). 차원별 이동수가 정해져 있고 순서만 바꾸는 것
- **D-03:** 다항계수 = S! / (d_1! × d_2! × ... × d_d!). S는 택시 거리(총 이동 수)
- **D-04:** 최종 답 = P+1개 구간 경로 수의 곱 (mod 10^9+7)

### 구현 방식
- **D-05:** 팩토리얼 + 역팩토리얼(모듈러 역원)을 N×d까지 전처리. N×d ≤ 10^6이므로 충분
- **D-06:** 역팩토리얼 = (k!)^(MOD-2) mod MOD (페르마 소정리). 나눗셈 대신 역원 곱셈
- **D-07:** 각 구간 다항계수 = S! × inv(d_1!) × inv(d_2!) × ... × inv(d_d!). O(d) per 구간

### 자료형/모듈러
- **D-08:** MOD = 10^9+7 (소수). int64로 충분

### Claude's Discretion
- I/O 스캐폴드 구조
- 역팩토리얼 전처리 방식 (top-down vs bottom-up)
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
- main_test.go에 예제 + 엣지 케이스 테스트

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

*Phase: 07-boj-30398*
*Context gathered: 2026-04-04*
