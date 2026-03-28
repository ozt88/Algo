# 알고리즘 스터디 (BOJ × Go)

## What This Is

매주 BOJ 문제 2-3개를 Go로 풀이하는 개인 알고리즘 스터디 레포.
LLM이 I/O 스캐폴드, plan.md 초안, 힌트를 제공하고 핵심 알고리즘 설계는 직접 수행한다.
문제 풀이 기록은 plan.md 우선으로 history/ 에 아카이브하여 사고 과정을 보존한다.

## Core Value

LLM과 협력하되 핵심 풀이는 직접 — 알고리즘 사고력을 기른다.

## Requirements

### Validated

- ✓ Go 단일 파일 구조 (main.go + main_test.go) — Phase 0 (기존 코드)
- ✓ plan.md 기반 풀이 워크플로우 — AGENTS.md 프로토콜 정립
- ✓ history/ 아카이브 (YYYY-Www-BOJ-<id>.md) — 2026-W10 시작

### Active

- [ ] 알고리즘 유형별 주차 커리큘럼 구성 (그래프, DP, 문자열, 수학 등)
- [ ] 주차별 BOJ 문제 2-3개 선정 및 풀이
- [ ] 풀이 완료 후 history/ 에 반성 노트 아카이브

### Out of Scope

- 다른 언어(Python, C++ 등) 풀이 — Go 실력에 집중
- LLM이 핵심 알고리즘을 직접 구현 — 실력 향상이 목적
- 외부 알고리즘 라이브러리 의존 — 표준 라이브러리만 사용

## Context

- **기존 코드베이스:** Go 1.18, 외부 의존성 없음, golangci-lint + just 사용
- **AGENTS.md 프로토콜:** 문제 설명 → I/O 스캐폴드 → plan.md 협업 → history 아카이브 순서 고정
- **plan 문서:** 한국어로 작성, UTF-8 with BOM (Windows PowerShell 호환)
- **현재 진행:** 2026-W10 BOJ 30801 (이진트리 매칭) 풀이 완료

## Constraints

- **Language:** Go만 사용 — Go 실력 향상 목적
- **Encoding:** 한국어 Markdown은 UTF-8 BOM — Windows PowerShell 5.1 호환
- **Autonomy:** LLM은 핵심 풀이 로직 직접 구현 금지 — AGENTS.md 역할 분담 준수
- **Style:** golangci-lint 통과 필수 — 140자 줄 제한, cyclomatic complexity 15 이하

## Key Decisions

| Decision | Rationale | Outcome |
|----------|-----------|---------|
| Go 단일 파일 구조 | 알고리즘 문제는 파일 분리 불필요, 빠른 반복 | ✓ Good |
| plan.md 우선 아카이브 | 코드보다 사고 과정이 더 가치 있음 | ✓ Good |
| LLM 힌트 depth 제한 | 직접 풀어야 실력이 오름 | ✓ Good |

---
*Last updated: 2026-03-28 — project initialized*
