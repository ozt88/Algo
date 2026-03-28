---
name: Phase 2 Context — BOJ 31864
description: 사용자가 discuss-phase에서 직접 설계한 풀이 방향 및 핵심 결정사항
type: project
---

# Phase 2: BOJ 31864 — Context

**Gathered:** 2026-03-28
**Status:** Ready for planning
**Source:** discuss-phase 대화

<domain>
## Phase Boundary

(0,0)에서 끝점까지의 선분 위에 올라오는 과일 최대 개수 계산.
N개 과일, M개 끝점 주어졌을 때 최적 끝점 선택.
</domain>

<decisions>
## Implementation Decisions

### 핵심 관찰
- 꼬치는 (0,0)에서 시작하므로 모든 과일·끝점은 원점에서의 벡터로 표현
- 과일이 끝점 선분 위 ↔ 같은 방향 + 과일 scale ≤ 끝점 scale

### 방향 정규화
- `gcd(|fx|, |fy|)`로 나눈 `(fx/gcd, fy/gcd)` pair를 map key로 사용
- 반대 방향(`(-1,-2)` vs `(1,2)`)은 다른 key — 꼬치 방향이 다르므로 의도된 동작

### 거리 비교
- scale = 정규화 전 gcd 값
- `과일 scale ≤ 끝점 scale`이면 해당 끝점 꼬치에 포함

### 그룹화 및 카운트
- map[direction] = 정렬된 scale 배열
- 끝점마다 binary search로 포함되는 과일 수 O(log N)

### 전체 복잡도
- 전처리: O(N log N) (정렬)
- 쿼리: O(M log N) (binary search × M)

### Claude's Discretion
- (0,0) 과일 처리 (gcd=0 케이스) — 구현 시 결정
- binary search 라이브러리 선택 (sort.SearchInts)
</decisions>

<canonical_refs>
## Canonical References

No external specs — requirements fully captured in decisions above.
</canonical_refs>

<specifics>
## Specific Ideas

- 사용자 직접 언급: "pair를 key로 하는 map, 정렬된 배열로 scale 값 저장"
- 사용자 직접 언급: "x,y의 GCD로 나눠서 unit vector를 key로"
- 반대 방향 key 분리: 사용자 확인 완료 ("꼬치는 0,0에서 시작하니깐")
</specifics>

<deferred>
## Deferred Ideas

None
</deferred>

---
*Phase: 02-boj-31864*
*Context gathered: 2026-03-28 via discuss-phase*
