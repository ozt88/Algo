# Requirements: 알고리즘 스터디 (BOJ x Go)

**Defined:** 2026-03-28
**Core Value:** LLM과 협력하되 핵심 풀이는 직접 - 알고리즘 사고력을 기른다.

## v1 Requirements

### 워크플로우

- [ ] **WF-01**: 새 문제를 받으면 문제 핵심 설명 -> I/O 스캐폴드 -> plan.md 순서로 진행한다
- [ ] **WF-02**: plan.md는 매 문제마다 작성되며 풀이 방향, 실패 아이디어, 최종 선택을 담는다
- [ ] **WF-03**: 문제가 의미있게 완료되면 history/ 에 YYYY-Www-BOJ-<id>.md 형식으로 아카이브한다
- [ ] **WF-04**: 힌트 깊이는 기본 `core-idea only` - 사용자가 요청할 때만 심화 제공한다

### 커리큘럼

- [ ] **CUR-01**: 알고리즘 유형별 학습 단계를 주차(Phase)로 구성한다 (그래프, DP, 문자열, 수학, 자료구조 등)
- [ ] **CUR-02**: 각 주차에 BOJ 문제 2-3개를 배정한다 (난이도 단계적 상승)
- [ ] **CUR-03**: 각 유형의 핵심 개념과 대표 패턴을 학습 목표로 명시한다

### 코드 품질

- [ ] **CODE-01**: 모든 Go 코드는 golangci-lint 통과 (140자 줄 제한, complexity 15 이하)
- [ ] **CODE-02**: 각 문제는 main_test.go에 최소 1개 이상의 테스트 케이스를 포함한다
- [ ] **CODE-03**: Go 표준 라이브러리만 사용한다 (외부 의존성 금지)

### 기록

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

## Traceability

| Requirement | Phase | Notes | Status |
|-------------|-------|-------|--------|
| WF-01 | Phase 1 | 매 문제 워크플로우 - Phase 1에서 패턴 확립 | Pending |
| WF-02 | Phase 1 | plan.md 작성 - Phase 1에서 패턴 확립 | Pending |
| WF-03 | Phase 1 | history 아카이브 - Phase 1에서 패턴 확립 | Pending |
| WF-04 | Phase 1 | 힌트 깊이 정책 - Phase 1에서 패턴 확립 | Pending |
| CUR-01 | Phase 1 | 유형별 Phase 구조 = ROADMAP.md 자체 | Pending |
| CUR-02 | Phase 2 | 문제 2-3개/주 - Phase 2부터 Phase 7까지 공통 적용 | Pending |
| CUR-03 | Phase 1 | 학습 목표 명시 - 각 Phase 성공기준에 반영 | Pending |
| CODE-01 | Phase 1 | golangci-lint 기준 - 전 Phase 공통, Phase 1 확립 | Pending |
| CODE-02 | Phase 1 | 테스트 케이스 - 전 Phase 공통, Phase 1 확립 | Pending |
| CODE-03 | Phase 1 | 표준 라이브러리만 - 전 Phase 공통, Phase 1 확립 | Pending |
| LOG-01 | Phase 1 | 한국어 UTF-8 BOM - 전 Phase 공통, Phase 1 확립 | Pending |
| LOG-02 | Phase 1 | history 문서 형식 - 전 Phase 공통, Phase 1 확립 | Pending |

**Coverage:**
- v1 requirements: 12 total
- Mapped to phases: 12
- Unmapped: 0

---
*Requirements defined: 2026-03-28*
*Last updated: 2026-03-28 - traceability updated after ROADMAP.md creation*
