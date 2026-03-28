# Roadmap: 알고리즘 스터디 (BOJ x Go)

## Overview

매주 BOJ 문제 2-3개를 Go로 풀이하며 알고리즘 사고력을 단계적으로 쌓는 커리큘럼.
기초 탐색부터 심화 그래프, 문자열, 수학까지 7개 Phase로 구성한다.
각 Phase는 하나의 알고리즘 유형을 완전히 다루며, 완료 시점에 해당 유형의 핵심 패턴을
독립적으로 적용할 수 있는 상태를 목표로 한다.

LLM은 I/O 스캐폴드와 plan.md 초안을 제공하고, 핵심 알고리즘 설계는 직접 수행한다.
모든 풀이는 plan.md -> history/ 아카이브 순서를 따른다.

## Phases

**Phase numbering:**
- Integer phases (1-7): 계획된 학습 단계
- Decimal phases: 긴급 삽입 시 사용 (예: 2.1)

- [ ] **Phase 1: 기초 탐색** - BFS/DFS, 백트래킹, Union-Find 기초 패턴 마스터
- [ ] **Phase 2: 동적 프로그래밍 기초** - 1D/2D DP, 점화식 설계, 메모이제이션 마스터
- [ ] **Phase 3: 동적 프로그래밍 심화** - 트리 DP, 비트마스크 DP, 구간 DP 마스터
- [ ] **Phase 4: 그래프 알고리즘** - 다익스트라, 플로이드-워셜, MST (크루스칼/프림) 마스터
- [ ] **Phase 5: 문자열 알고리즘** - KMP, 트라이, 해싱 기반 패턴 매칭 마스터
- [ ] **Phase 6: 수학/정수론** - 소수 판별, 조합론, 모듈러 연산, 이진 지수승 마스터
- [ ] **Phase 7: 심화 자료구조** - 세그먼트 트리, 펜윅 트리, 스택 기반 알고리즘 마스터

## Phase Details

### Phase 1: 기초 탐색
**Goal**: BFS/DFS, 백트래킹, Union-Find의 핵심 패턴을 Go로 독립적으로 작성할 수 있다
**Depends on**: Nothing (워크플로우와 코드 품질 기준이 여기서 확립된다)
**Requirements**: WF-01, WF-02, WF-03, WF-04, CUR-01, CUR-03, CODE-01, CODE-02, CODE-03, LOG-01, LOG-02
**Success Criteria** (what must be TRUE):
  1. BFS/DFS로 격자 혹은 그래프 연결요소 문제를 힌트 없이 풀 수 있다
  2. 백트래킹으로 조건부 탐색 공간을 정의하고 가지치기를 설계할 수 있다
  3. Union-Find (경로 압축 + 랭크 합병)를 직접 구현하고 연결성 판단에 쓸 수 있다
  4. 풀이마다 plan.md를 작성하고 완료 후 history/에 아카이브한다
  5. 모든 Go 코드가 golangci-lint를 통과하고 최소 1개 테스트 케이스를 포함한다
**Plans**: TBD

Plans:
- [ ] 01-01: BFS/DFS - 격자 탐색 (BOJ 1926 그림, 2178 미로탐색, 7576 토마토)
- [ ] 01-02: 백트래킹 (BOJ 15649 N과M(1), 9663 N-Queen, 1182 부분집합의 합)
- [ ] 01-03: Union-Find (BOJ 1717 집합의 표현, 1197 최소 스패닝 트리 기초, 33065 복습)

### Phase 2: 동적 프로그래밍 기초
**Goal**: 1D/2D DP 점화식을 스스로 유도하고 bottom-up / top-down 두 방식으로 구현할 수 있다
**Depends on**: Phase 1
**Requirements**: CUR-02
**Success Criteria** (what must be TRUE):
  1. 문제를 보고 상태 정의와 점화식을 먼저 종이에 적은 뒤 구현할 수 있다
  2. 1D DP (배낭, LIS, 동전) 유형을 힌트 없이 풀 수 있다
  3. 2D DP (LCS, 편집거리, 격자 경로) 유형을 힌트 없이 풀 수 있다
  4. Bottom-up과 top-down 중 적합한 방식을 선택하고 이유를 plan.md에 기록한다
**Plans**: TBD

Plans:
- [ ] 02-01: 1D DP 기초 (BOJ 1463 1로 만들기, 9095 1+2+3 더하기, 11053 가장 긴 증가하는 부분수열)
- [ ] 02-02: 배낭 문제 (BOJ 12865 평범한 배낭, 7579 앱, 2629 양팔저울)
- [ ] 02-03: 2D DP (BOJ 9251 LCS, 1958 LCS3, 1149 RGB거리)

### Phase 3: 동적 프로그래밍 심화
**Goal**: 트리 구조, 비트마스크 상태, 구간 위에서 DP 상태를 정의하고 올바른 점화식을 유도할 수 있다
**Depends on**: Phase 2
**Requirements**: (Phase 2와 함께 CUR-02, CUR-03을 계속 충족)
**Success Criteria** (what must be TRUE):
  1. 트리 DP에서 루트 선택 여부 혹은 서브트리 상태를 변수로 잡을 수 있다
  2. 비트마스크로 방문 집합 상태를 인코딩하고 TSP류 문제를 풀 수 있다
  3. 구간 DP (행렬 곱셈 순서, 괄호 삽입) 점화식을 올바르게 세울 수 있다
  4. 이진 트리 매칭 (BOJ 30801 패턴) 같은 복합 재귀를 메모이제이션으로 최적화할 수 있다
**Plans**: TBD

Plans:
- [ ] 03-01: 트리 DP (BOJ 2533 사회망 서비스, 1949 우수 마을, 15681 트리와 쿼리)
- [ ] 03-02: 비트마스크 DP (BOJ 2098 외판원 순회, 1102 발전소, 1014 컨닝)
- [ ] 03-03: 구간 DP + 복합 재귀 DP (BOJ 11066 파일 합치기, 1912 연속합, 30801 복습)

### Phase 4: 그래프 알고리즘
**Goal**: 가중치 그래프에서 최단경로와 최소신장트리를 올바르게 선택하고 구현할 수 있다
**Depends on**: Phase 1 (BFS 기초), Phase 2 (DP 기초)
**Requirements**: (CUR-02, CUR-03 지속 충족)
**Success Criteria** (what must be TRUE):
  1. 다익스트라를 우선순위 큐로 구현하고 음수 간선 제약 조건을 설명할 수 있다
  2. 플로이드-워셜로 모든 쌍 최단경로를 구하고 시간복잡도 O(V^3)를 이해한다
  3. 크루스칼 (Union-Find 활용) 또는 프림으로 MST를 구하고 두 알고리즘의 차이를 설명할 수 있다
  4. 주어진 문제에서 "최단경로 vs MST vs BFS" 중 올바른 접근을 선택할 수 있다
**Plans**: TBD

Plans:
- [ ] 04-01: 다익스트라 (BOJ 1753 최단경로, 1916 최소비용 구하기, 4485 녹색 옷 입은 애가 젤다지?)
- [ ] 04-02: 플로이드-워셜 (BOJ 11404 플로이드, 1389 케빈 베이컨의 6단계 법칙, 2458 키 순서)
- [ ] 04-03: MST (BOJ 1197 최소 스패닝 트리, 1922 네트워크 연결, 6497 전력난)

### Phase 5: 문자열 알고리즘
**Goal**: KMP 실패함수와 트라이 구조를 직접 구현하고 패턴 매칭 문제에 적용할 수 있다
**Depends on**: Phase 1 (탐색 기초)
**Requirements**: (CUR-02, CUR-03 지속 충족)
**Success Criteria** (what must be TRUE):
  1. KMP 실패함수(failure function)를 직접 구현하고 O(N+M) 매칭을 설명할 수 있다
  2. 트라이(Trie) 노드 구조를 Go로 구현하고 문자열 집합 검색에 적용할 수 있다
  3. 해싱 기반 Rabin-Karp로 다중 패턴 혹은 롤링 해시 문제를 풀 수 있다
  4. 상태 시뮬레이션 기반 문자열 문제 (BOJ 30801 패턴)의 전이 규칙을 올바르게 모델링할 수 있다
**Plans**: TBD

Plans:
- [ ] 05-01: KMP (BOJ 1786 찾기, 16916 부분 문자열, 1305 광고)
- [ ] 05-02: 트라이 (BOJ 5052 전화번호 목록, 14425 문자열 집합, 9202 Boggle)
- [ ] 05-03: 해싱 + 문자열 시뮬레이션 (BOJ 1167 트리의 지름, 1251 단어 나누기, 30801 심화복습)

### Phase 6: 수학/정수론
**Goal**: 소수 판별, 조합론, 모듈러 연산을 알고리즘 문제 제약 내에서 정확하게 적용할 수 있다
**Depends on**: Phase 2 (DP 기초, 조합 점화식)
**Requirements**: (CUR-02, CUR-03 지속 충족)
**Success Criteria** (what must be TRUE):
  1. 에라토스테네스의 체로 범위 내 소수를 O(N log log N)에 열거할 수 있다
  2. 이진 지수승(fast exponentiation)으로 a^b mod p를 O(log b)에 계산할 수 있다
  3. 페르마 소정리를 활용한 모듈러 역원으로 nCr mod p를 계산할 수 있다
  4. 유클리드 호제법으로 GCD/LCM을 구하고 확장 유클리드로 역원을 찾을 수 있다
**Plans**: TBD

Plans:
- [ ] 06-01: 소수와 에라토스테네스의 체 (BOJ 1929 소수 구하기, 4948 베르트랑 공준, 6588 골드바흐의 추측)
- [ ] 06-02: 이진 지수승 + 모듈러 역원 (BOJ 1629 곱셈, 11401 이항 계수3, 13977 이항 계수와 쿼리)
- [ ] 06-03: 조합론 + 수론 응용 (BOJ 1010 다리 놓기, 2004 조합 0의 개수, 1747 소수 & 팰린드롬)

### Phase 7: 심화 자료구조
**Goal**: 구간 쿼리(합/최솟값/최댓값)를 효율적으로 처리하는 자료구조를 직접 구현할 수 있다
**Depends on**: Phase 2 (DP/재귀 기초), Phase 4 (그래프 응용)
**Requirements**: (CUR-02, CUR-03 지속 충족)
**Success Criteria** (what must be TRUE):
  1. 펜윅 트리(BIT)로 prefix sum 갱신과 쿼리를 O(log N)에 처리할 수 있다
  2. 세그먼트 트리로 구간 최솟값/최댓값/합을 O(log N)에 처리할 수 있다
  3. 단조 스택으로 Next Greater Element 류 문제를 O(N)에 풀 수 있다
  4. 어떤 구간 쿼리 문제에서 BIT vs 세그먼트 트리를 선택할지 이유를 설명할 수 있다
**Plans**: TBD

Plans:
- [ ] 07-01: 펜윅 트리 (BOJ 2042 구간 합 구하기, 11658 구간 합 구하기3, 1280 나무심기)
- [ ] 07-02: 세그먼트 트리 (BOJ 10868 최솟값, 2357 최솟값과 최댓값, 1395 스위치)
- [ ] 07-03: 스택 기반 알고리즘 (BOJ 17298 오큰수, 6549 히스토그램에서 가장 큰 직사각형, 1725 히스토그램)

## Progress

**Execution Order:**
Phase 1 -> Phase 2 -> Phase 3 -> Phase 4 -> Phase 5 -> Phase 6 -> Phase 7

| Phase | Plans Complete | Status | Completed |
|-------|----------------|--------|-----------|
| 1. 기초 탐색 | 0/3 | Not started | - |
| 2. 동적 프로그래밍 기초 | 0/3 | Not started | - |
| 3. 동적 프로그래밍 심화 | 0/3 | Not started | - |
| 4. 그래프 알고리즘 | 0/3 | Not started | - |
| 5. 문자열 알고리즘 | 0/3 | Not started | - |
| 6. 수학/정수론 | 0/3 | Not started | - |
| 7. 심화 자료구조 | 0/3 | Not started | - |

---
*Roadmap created: 2026-03-28*
*Granularity: standard (7 phases, 3 plans each)*
