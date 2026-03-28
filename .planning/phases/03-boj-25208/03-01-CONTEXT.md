---
name: Phase 3 Context — BOJ 25208
description: 사용자가 discuss-phase에서 직접 설계한 풀이 방향 및 핵심 결정사항
type: project
---

# Phase 3: BOJ 25208 — Context

**Gathered:** 2026-03-28
**Status:** Ready for planning
**Source:** discuss-phase 대화

<domain>
## Phase Boundary

N×M 격자에서 탐정(D)이 한 면이 뚫린 정육면체 감옥을 굴려 도둑(R) 위치로 이동.
뚫린 면이 바닥일 때 도둑 칸 도달 시 승리, 막힌 면이 바닥이면 즉시 패배.
최소 굴리기 횟수 출력 (불가능 시 -1).
</domain>

<decisions>
## Implementation Decisions

### 상태 공간
- 상태: `(x, y, s)` — x, y는 격자 좌표, s는 큐브 orientation
- s 인코딩: `s = north_face × 6 + bottom_face` (범위 0~35, 유효 상태 24개)
  - 무효 상태 12개 (north==bottom 또는 north==opposite(bottom)) — BFS 중 자연히 생성 안 됨
- dp 값: 최소 이동 횟수 (미방문 = INF)

### 면 번호 정의
- 면 0: 뚫린 면 (열린 면, 탈출구)
- 초기 큐브 배열: `faces[6] = {바닥, 윗면, 북, 남, 동, 서} = {0, 1, 2, 3, 4, 5}`
- 반대면 쌍: (0,1), (2,3), (4,5)

### 초기 상태
- bottom=0 (뚫린 면이 바닥), north=2
- s = 2 × 6 + 0 = **12**
- 탐정 시작 위치 D에서 시작

### 전환 테이블 생성 방법
- 초기 faces 배열에서 BFS로 4방향 굴리기 적용
- 굴리기 순열 (북으로 굴릴 때):
  - 새 바닥 = 기존 북, 새 북 = 기존 윗면, 새 윗면 = 기존 남, 새 남 = 기존 바닥 (동/서 불변)
- 나머지 3방향(남/동/서) 동일 방식으로 정의
- 24개 상태 × 4방향 = 96개 전환 엔트리를 코드 실행 시 자동 생성

### BFS 탐색 규칙
- 이미 저장된 이동 횟수보다 크거나 같으면 스킵 (사이클 방지 + 최솟값 보장)
- 다음 칸이 R 일 때:
  - bottom_face == 0 (뚫린 면): **승리** → 이동 횟수 반환
  - bottom_face != 0 (막힌 면): **즉시 패배 조건** → 해당 이동 스킵
- 다음 칸이 `#`이면 이동 불가
- 모든 상태 탐색 후 R 도달 불가 시: -1 출력

### 복잡도
- 상태 공간: 500 × 500 × 36 ≈ 9M (유효 상태 6M)
- 시간: O(N × M × 24) — 제한 1초, 충분

### Claude's Discretion
- 전환 테이블 생성 시 faces 배열 표현 방식 (slice vs array)
- INF 초기값 선택 (math.MaxInt32 등)
</decisions>

<canonical_refs>
## Canonical References

No external specs — requirements fully captured in decisions above.
</canonical_refs>

<specifics>
## Specific Ideas

- 사용자 직접 설계: "dp[x][y][s], 이미 적혀있는 것보다 크면 가지 않음"
- 사용자 직접 설계: "s = north_face × 6 + bottom_face" 인코딩
- 사용자 확인: 유효 상태 24개, 무효 12개는 BFS 중 자연 제거
- 사용자 확인: 초기 faces 배열에서 전환 테이블 자동 생성
- R 칸에 막힌 면으로 진입 시 스킵 (즉시 패배 조건)
</specifics>

<deferred>
## Deferred Ideas

- 최단 거리 + 거리 parity로 접근하는 방법 (초기 아이디어, 경로 의존성으로 기각)
</deferred>

---
*Phase: 03-boj-25208*
*Context gathered: 2026-03-28 via discuss-phase*
