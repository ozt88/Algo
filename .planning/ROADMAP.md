# Roadmap: 알고리즘 스터디 (BOJ x Go)

## Overview

매주 BOJ 문제를 Go로 풀이하는 알고리즘 스터디.
각 Milestone = 1주차, 각 Phase = 문제 1개.
LLM은 I/O 스캐폴드와 plan.md 초안을 제공하고, 핵심 알고리즘 설계는 직접 수행한다.

## Milestone 1: 2026-W13 (2026-03-28) — 종료 (3/4, 75%)

- [x] **Phase 1: BOJ 28280** 귀납법 — BFS 전처리
- [x] **Phase 2: BOJ 31864** 눈송이 탕후루 만들기
- [x] **Phase 3: BOJ 25208** 새벽의 탐정 게임
- [ ] **Phase 4: BOJ 25964** — 미진행 (다음 마일스톤으로 이월 또는 폐기)

### Phase Details

#### Phase 1: BOJ 28280 귀납법 ✓
**Goal**: 1에서 k까지 ×2 또는 -1 연산 최소 횟수
**Algorithm**: BFS 전처리 (4×10⁶ 범위)
**Status**: AC
**History**: `history/2026-W13-BOJ-28280.md`

#### Phase 2: BOJ 31864 눈송이 탕후루 만들기 ✓
**Goal**: (0,0)에서 끝점까지 선분 위 과일 최대 개수
**Algorithm**: 기울기 정규화 + 좌표압축 그리디
**Status**: AC
**History**: `history/2026-W10-BOJ-30801.md`

#### Phase 3: BOJ 25208 새벽의 탐정 게임 ✓
**Goal**: 탐정이 한 면이 뚫린 정육면체 감옥을 굴려 도둑 위치에 뚫린 면이 바닥으로 도달 — 최소 굴리기 횟수
**Algorithm**: BFS dp[r][c][s], s=north_face×6+bottom_face (24상태), rollTable 자동 생성
**Status**: AC
**History**: `history/2026-W13-BOJ-25208.md`

#### Phase 4: BOJ 25964
**Goal**: TBD
**Status**: Not started
**Plans**:
- [ ] 04-01: 풀이 설계 및 구현

## Progress

| Milestone | Phase | Problem | Status |
|-----------|-------|---------|--------|
| W13 | 1 | BOJ 28280 귀납법 | ✓ AC |
| W13 | 2 | BOJ 31864 눈송이 탕후루 | ✓ AC |
| W13 | 3 | BOJ 25208 새벽의 탐정 게임 | ✓ AC |
| W13 | 4 | BOJ 25964 | 미진행 |

---
*Roadmap restructured: 2026-03-28 — Milestone = 주차, Phase = 문제*
*Milestone 1 종료: 2026-03-28 — 3/4 문제 AC (75%)*
*다음 마일스톤: `/gsd:new-milestone` 실행*
