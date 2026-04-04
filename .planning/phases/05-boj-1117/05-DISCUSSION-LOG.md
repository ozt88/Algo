# Phase 5: BOJ 1117 색칠 1 - Discussion Log

> **Audit trail only.** Do not use as input to planning, research, or execution agents.
> Decisions are captured in CONTEXT.md — this log preserves the alternatives considered.

**Date:** 2026-04-04
**Phase:** 05-boj-1117
**Areas discussed:** 알고리즘 접근 방향, x/y 독립 분리, x방향 매핑, 곱셈 정당성

---

## 문제 설명 요청

사용자가 문제 설명을 먼저 요청. 문제 핵심(접기→칠하기→펼치기)과 단계별 과정을 설명.

**User's choice:** 문제 이해 후 알고리즘 논의로 진행

---

## 알고리즘 접근 방향

사용자: "접은 상태에서 칠한 영역을 원래 좌표로 매핑하는 함수를 만들 수 있나?"
→ 유효한 접근. x/y 축이 독립임을 확인.

**User's choice:** 매핑 함수 접근 채택

---

## x/y 독립 분리

사용자: "색칠 안 된 면적끼리 곱하면 되나?"
→ 안 됨. 칠해진 면적끼리 곱한 뒤 전체에서 빼야 함.
→ 답 = W×H - painted_x × painted_y

**User's choice:** painted 면적 곱셈 후 전체에서 빼기

---

## x방향 매핑 (겹치는 구간)

사용자: "접힌 영역에 겹친 직사각형 영역만 ×2, 나머지 ×1"
사용자: "겹치는 구간 = [0, min(f, W-f)]"

**User's choice:** overlap = min(f, W-f), doubled/single 분리 계산

---

## 곱셈 정당성 검증

사용자: "펼치면 직사각형이 아닐 수 있는데 단순 곱셈이 맞나?"
→ x구간끼리 안 겹치고 y구간끼리 안 겹치므로 직교곱 면적 공식 성립.

**User's choice:** 납득 — 곱셈 정당성 확인

---

## Claude's Discretion

- I/O 스캐폴드 구조
- 엣지 케이스 테스트 선정

## Deferred Ideas

None.
