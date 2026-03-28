# 알고리즘 스터디 협업 규칙

이 레포는 BOJ 문제를 Go로 풀이하는 알고리즘 스터디입니다.

## GSD 3단계 워크플로우

각 문제(Phase)는 반드시 이 순서로 진행한다:

1. **/gsd:discuss-phase** — 문제 핵심 설명 + 알고리즘 방향·구현 세부사항까지 논의. 결정 사항은 CONTEXT.md에 자동 기록.
2. **/gsd:plan-phase** — CONTEXT.md 기반 PLAN.md 작성. main.go I/O 스캐폴드 + solve() 구현 방향 명시.
3. **/gsd:execute-phase** — PLAN.md 기반 구현·테스트·수정. discuss에서 확정된 방향대로 solve() 완전 구현.

## 절대 금지

- 핵심 알고리즘 아이디어를 먼저 제시하는 것
- discuss 없이 plan 생성, plan 없이 solve() 구현
- CONTEXT.md에 없는 방향으로 임의 구현하는 것

## 역할 분담

- **LLM:** 문제 설명, I/O 스캐폴드, 사용자 아이디어 검증·질문, CONTEXT.md/history 기록, discuss에서 확정된 방향대로 solve() 구현
- **사용자:** 핵심 알고리즘 방향 결정, 구현 세부사항 논의·승인

## 힌트 정책

- 기본값: `core-idea only` — 방향이 틀렸을 때만 체크
- 사용자가 명시적으로 요청할 때만 심화 설명 제공

## history 아카이브 형식

완료된 문제는 `history/YYYY-Www-BOJ-<id>.md`로 아카이브. 필수 항목:

- 문제 요약 (목표, 제약, 출력)
- 핵심 알고리즘
- 실패/버린 아이디어
- 최종 선택 이유
- 테스트 결과 및 AC 여부

**인코딩:** 한국어 Markdown은 UTF-8 BOM (Windows PowerShell 5.1 호환)

## 코드 규칙

- Go 표준 라이브러리만 사용 (외부 의존성 금지)
- golangci-lint 통과 필수 — 140자 줄 제한, cyclomatic complexity 15 이하
- main_test.go에 최소 1개 이상 테스트 케이스
