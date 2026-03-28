# 알고리즘 스터디 (BOJ × Go)

매주 BOJ 문제 2-3개를 Go로 풀이하는 개인 알고리즘 스터디 레포.
LLM이 스캐폴드·힌트를 제공하고, 핵심 알고리즘 설계는 직접 수행한다.

**Core Value:** LLM과 협력하되 핵심 풀이는 직접 — 알고리즘 사고력을 기른다.

## Constraints

- Go 표준 라이브러리만 사용, golangci-lint 통과 필수
- 한국어 Markdown은 UTF-8 BOM (Windows PowerShell 5.1 호환)
- LLM은 핵심 풀이 로직 직접 구현 금지

## Key Decisions

| Decision | Rationale | Outcome |
|----------|-----------|---------|
| Go 단일 파일 구조 | 알고리즘 문제는 파일 분리 불필요 | ✓ Good |
| plan.md 우선 아카이브 | 코드보다 사고 과정이 더 가치 있음 | ✓ Good |
| discuss→plan→execute 3단계 | LLM 무단 구현 방지, 사용자 주도 유지 | ✓ Good |

---
*Last updated: 2026-03-28*
