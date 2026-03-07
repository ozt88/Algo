# Problem Plan - BOJ 30801

## 1) Problem Summary
- Problem link/name: BOJ 30801 가희와 클럽 오디션 2
- Objective (one sentence): 노트 문자열과 실제 입력 문자열이 주어질 때, 마지막 타이밍에 Space를 눌렀을 때 성공인지 판정한다.
- Output requirement (one sentence): 최종 판정이 성공이면 `Yes`, 아니면 `No`를 출력한다.

## 2) Constraints and I/O
- Input format:
  - 첫 줄: 노트 문자열
  - 둘째 줄: 사용자가 누른 키 문자열
- Output format:
  - `Yes` 또는 `No`
- Constraints (level, input count, limits):
  - 레벨 `6 <= lv <= 11`
  - 입력 수 `1 <= len(keys) <= 20000`
  - 시간 1초, 메모리 512MB
- Notes from samples:
  - 노트 토큰은 `W`, `A`, `S`, `D`, `LU`, `LD`, `RU`, `RD` 뒤에 선택적으로 `!`
  - 입력 키는 단일 문자이며 방향으로 변환해서 비교

## 3) Core Idea (User-Driven)
- Candidate approach:
  - 노트 문자열을 방향 시퀀스로 파싱
  - 입력 문자열도 방향 시퀀스로 변환
  - `matched = 앞에서부터 일치한 길이` 상태 하나만 유지하며 순서대로 시뮬레이션
- Why this approach fits constraints:
  - 노트 길이는 최대 11, 입력 길이는 최대 20000이라 선형 시뮬레이션이면 충분
- Data structures needed:
  - `note []int`
  - `keys []int`
  - `matched int`
- Complexity target:
  - Time: `O(len(keys))`
  - Space: `O(lv + len(keys))`
- Open decisions for user:
  - [ ] 상태 전이 구현을 단순 if로 갈지 함수화할지 결정
  - [ ] 입력 문자열 전체를 배열로 바꿀지, 순회 중 즉시 처리할지 결정

## 4) Implementation Checklist
- [x] Parse input robustly.
- [x] Parse note tokens including reverse `!`.
- [x] Parse input key characters into directions.
- [x] Define `matched` state skeleton.
- [ ] Fill state transition logic (user-led).
- [x] Format output exactly as required.
- [ ] Run sample tests.
- [ ] Add edge-case tests for reset timing.

## 5) Test Cases
### Basic Cases
- Case 1:
  - Input:
    - `WLU!LDAS!D!RD!`
    - `W31AW47`
  - Expected:
    - `Yes`
- Case 2:
  - Input:
    - `DDDDDD`
    - `DDDDDDD`
  - Expected:
    - `No`

### Edge Cases
- Edge 1 (full match then one more key):
  - Input:
    - `DDDDDD`
    - `DDDDDDD`
  - Expected:
    - `No`
- Edge 2 (midway mismatch reset):
  - Input:
    - `WLU!LDAS!D!RD!`
    - `W31A447W`
  - Expected:
    - `No`

## 6) Progress Notes
- Current status:
  - 노트/입력 파싱과 판정 스캐폴드 완료, 상태 전이 핵심은 미구현
- Next action:
  - `judgeSkeleton`에서 `matched` 갱신 규칙을 정확히 채우기
- Blockers/questions:
  - 현재 없음
