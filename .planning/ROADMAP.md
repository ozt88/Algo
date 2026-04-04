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

---

## Milestone 2: 2026-W14 (2026-04-04)

### Phases

- [ ] **Phase 5: BOJ 1117** - 알고리즘 설계 및 Go 구현 → AC 획득
- [ ] **Phase 6: BOJ 30867** - 알고리즘 설계 및 Go 구현 → AC 획득
- [ ] **Phase 7: BOJ 30398** - 알고리즘 설계 및 Go 구현 → AC 획득
- [ ] **Phase 8: BOJ 18425** - 알고리즘 설계 및 Go 구현 → AC 획득

### Phase Details

#### Phase 5: BOJ 1117
**Goal**: BOJ 1117을 discuss→plan→execute 워크플로우로 풀이하여 AC를 받는다
**Depends on**: Nothing (milestone start)
**Requirements**: PROB-01, WF-01, WF-02, WF-03, WF-04, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02
**Success Criteria** (what must be TRUE):
  1. BOJ 1117 제출 결과가 AC이다
  2. main_test.go에 최소 1개 이상의 테스트 케이스가 통과한다
  3. history/2026-W14-BOJ-1117.md 파일이 존재하고 풀이 요약·실패 아이디어·선택 이유·테스트 결과를 포함한다
**Plans**: 1 plan
Plans:
- [ ] 05-01-PLAN.md — main.go 풀이 구현 + 테스트 + history 아카이브

#### Phase 6: BOJ 30867
**Goal**: BOJ 30867을 discuss→plan→execute 워크플로우로 풀이하여 AC를 받는다
**Depends on**: Phase 5 (선택적 — 병렬 진행 가능)
**Requirements**: PROB-02, WF-01, WF-02, WF-03, WF-04, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02
**Success Criteria** (what must be TRUE):
  1. BOJ 30867 제출 결과가 AC이다
  2. main_test.go에 최소 1개 이상의 테스트 케이스가 통과한다
  3. history/2026-W14-BOJ-30867.md 파일이 존재하고 풀이 요약·실패 아이디어·선택 이유·테스트 결과를 포함한다
**Plans**: 1 plan
Plans:
- [ ] 05-01-PLAN.md — main.go 풀이 구현 + 테스트 + history 아카이브

#### Phase 7: BOJ 30398
**Goal**: BOJ 30398을 discuss→plan→execute 워크플로우로 풀이하여 AC를 받는다
**Depends on**: Phase 6 (선택적 — 병렬 진행 가능)
**Requirements**: PROB-03, WF-01, WF-02, WF-03, WF-04, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02
**Success Criteria** (what must be TRUE):
  1. BOJ 30398 제출 결과가 AC이다
  2. main_test.go에 최소 1개 이상의 테스트 케이스가 통과한다
  3. history/2026-W14-BOJ-30398.md 파일이 존재하고 풀이 요약·실패 아이디어·선택 이유·테스트 결과를 포함한다
**Plans**: 1 plan
Plans:
- [ ] 05-01-PLAN.md — main.go 풀이 구현 + 테스트 + history 아카이브

#### Phase 8: BOJ 18425
**Goal**: BOJ 18425를 discuss→plan→execute 워크플로우로 풀이하여 AC를 받는다
**Depends on**: Phase 7 (선택적 — 병렬 진행 가능)
**Requirements**: PROB-04, WF-01, WF-02, WF-03, WF-04, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02
**Success Criteria** (what must be TRUE):
  1. BOJ 18425 제출 결과가 AC이다
  2. main_test.go에 최소 1개 이상의 테스트 케이스가 통과한다
  3. history/2026-W14-BOJ-18425.md 파일이 존재하고 풀이 요약·실패 아이디어·선택 이유·테스트 결과를 포함한다
**Plans**: 1 plan
Plans:
- [ ] 05-01-PLAN.md — main.go 풀이 구현 + 테스트 + history 아카이브

## Progress

| Milestone | Phase | Problem | Plans Complete | Status | Completed |
|-----------|-------|---------|----------------|--------|-----------|
| W13 | 1 | BOJ 28280 귀납법 | 1/1 | AC | 2026-W13 |
| W13 | 2 | BOJ 31864 눈송이 탕후루 | 1/1 | AC | 2026-W13 |
| W13 | 3 | BOJ 25208 새벽의 탐정 게임 | 1/1 | AC | 2026-W13 |
| W13 | 4 | BOJ 25964 | 0/1 | 미진행 | - |
| W14 | 5 | BOJ 1117 | 0/1 | Not started | - |
| W14 | 6 | BOJ 30867 | 0/1 | Not started | - |
| W14 | 7 | BOJ 30398 | 0/1 | Not started | - |
| W14 | 8 | BOJ 18425 | 0/1 | Not started | - |

---
*Roadmap restructured: 2026-03-28 — Milestone = 주차, Phase = 문제*
*Milestone 1 종료: 2026-03-28 — 3/4 문제 AC (75%)*
*Milestone 2 시작: 2026-04-04 — Phase 5-8 (BOJ 1117, 30867, 30398, 18425)*
