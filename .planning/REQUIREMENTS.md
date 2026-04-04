# Requirements: 알고리즘 스터디 (BOJ x Go)

**Defined:** 2026-03-28
**Updated:** 2026-04-04 — Milestone v1.1
**Core Value:** LLM과 협력하되 핵심 풀이는 직접 — 알고리즘 사고력을 기른다.

## v1.1 Requirements

### 문제풀이

- [ ] **PROB-01**: BOJ 1117을 Go로 풀이하여 AC를 받는다
- [ ] **PROB-02**: BOJ 30867을 Go로 풀이하여 AC를 받는다
- [ ] **PROB-03**: BOJ 30398을 Go로 풀이하여 AC를 받는다
- [ ] **PROB-04**: BOJ 18425를 Go로 풀이하여 AC를 받는다

### 워크플로우 (v1.0 계승, 전 Phase 공통)

- [ ] **WF-01**: 새 문제를 받으면 문제 핵심 설명 → I/O 스캐폴드 → plan.md 순서로 진행한다
- [ ] **WF-02**: plan.md는 매 문제마다 작성되며 풀이 방향, 실패 아이디어, 최종 선택을 담는다
- [ ] **WF-03**: 문제가 의미있게 완료되면 history/에 YYYY-Www-BOJ-<id>.md 형식으로 아카이브한다
- [ ] **WF-04**: 힌트 깊이는 기본 `core-idea only` — 사용자가 요청할 때만 심화 제공한다

### 코드 품질 (v1.0 계승, 전 Phase 공통)

- [ ] **CODE-01**: 모든 Go 코드는 golangci-lint 통과 (140자 줄 제한, complexity 15 이하)
- [ ] **CODE-02**: 각 문제는 main_test.go에 최소 1개 이상의 테스트 케이스를 포함한다
- [ ] **CODE-03**: Go 표준 라이브러리만 사용한다 (외부 의존성 금지)

### 기록 (v1.0 계승, 전 Phase 공통)

- [ ] **LOG-01**: 모든 plan/history 문서는 한국어, UTF-8 BOM으로 저장한다
- [ ] **LOG-02**: history 문서는 풀이 요약, 실패 아이디어, 선택 이유, 테스트 결과를 포함한다

## v2 Requirements

### 심화

- **ADV-01**: 동일 문제를 다른 알고리즘 접근(예: Bottom-up DP vs Top-down)으로 재풀이
- **ADV-02**: 시간/공간 복잡도 분석 노트 추가

### 통계

- **STAT-01**: 완료 문제 수, 유형별 비율, 주차별 진행률 추적

## Out of Scope

| Feature | Reason |
|---------|--------|
| Go 외 언어 사용 | Go 실력 집중 목적 |
| LLM이 핵심 알고리즘 직접 구현 | 사고력 향상이 목적 |
| 외부 알고리즘 라이브러리 | 표준 라이브러리로 충분 |
| 웹/앱 대시보드 | 텍스트 기반 기록으로 충분 |
| BOJ 25964 | v1.0에서 폐기 결정 |

## Traceability

| Requirement | Phase | Status |
|-------------|-------|--------|
| PROB-01 | Phase 5 | Pending |
| PROB-02 | Phase 6 | Pending |
| PROB-03 | Phase 7 | Pending |
| PROB-04 | Phase 8 | Pending |
| WF-01~04 | All | Pending |
| CODE-01~03 | All | Pending |
| LOG-01~02 | All | Pending |

**Coverage:**
- v1.1 requirements: 4 문제풀이 + 9 공통
- Mapped to phases: All
- Unmapped: 0

---
*Requirements defined: 2026-03-28*
*Last updated: 2026-04-04 — milestone v1.1 requirements*
