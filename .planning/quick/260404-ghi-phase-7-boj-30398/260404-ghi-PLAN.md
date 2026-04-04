---
phase: 07-boj-30398
plan: 01
type: execute
wave: 1
depends_on: []
files_modified:
  - main.go
  - main_test.go
  - history/2026-W14-BOJ-30398.md
autonomous: true
requirements:
  - PROB-01
  - WF-01
  - WF-02
  - WF-03
  - WF-04
  - CODE-01
  - CODE-02
  - CODE-03
  - LOG-01
  - LOG-02

must_haves:
  truths:
    - "main.go가 BOJ 30398 입력을 읽고 P개 중간점을 거치는 경로 수를 mod 10^9+7로 출력한다"
    - "팩토리얼 + 역팩토리얼 테이블을 N×d까지 전처리하여 O(N×d)에 구축한다"
    - "각 구간에서 B_j - A_j < 0이면 즉시 0을 출력한다"
    - "각 구간의 다항계수를 O(d)에 계산하고 P+1개 곱으로 최종 답을 낸다"
    - "main_test.go에 최소 4개 테스트 케이스가 통과한다"
    - "history 아카이브가 존재한다"
  artifacts:
    - path: "main.go"
      provides: "BOJ 30398 풀이 (parseInput + solve)"
      contains: "func solve"
    - path: "main_test.go"
      provides: "테스트 케이스"
      contains: "func TestSolve"
    - path: "history/2026-W14-BOJ-30398.md"
      provides: "풀이 아카이브"
      contains: "핵심 알고리즘"
  key_links:
    - from: "main.go"
      to: "solve function"
      via: "parseInput → solve 호출"
      pattern: "solve\\("
    - from: "main_test.go"
      to: "main.go solve"
      via: "TestSolve table-driven tests"
      pattern: "solve\\("
---

<objective>
BOJ 30398 (대구일과학고등학교) 풀이를 구현하고 테스트하여 AC를 받을 수 있는 상태로 만든다.

Purpose: d차원 격자에서 (1,...,1)→(N,...,N)으로 P개 중간점을 순서대로 거치는 경로 수를 다항계수로 구한다.
         팩토리얼 전처리 O(N×d) + 구간별 다항계수 O(P×d)로 전체 효율적 계산.
Output: main.go (풀이), main_test.go (테스트), history/2026-W14-BOJ-30398.md (아카이브)
</objective>

<execution_context>
@$HOME/.claude/get-shit-done/workflows/execute-plan.md
@$HOME/.claude/get-shit-done/templates/summary.md
</execution_context>

<context>
@.planning/PROJECT.md
@.planning/ROADMAP.md
@.planning/STATE.md
@.planning/phases/07-boj-30398/07-CONTEXT.md
</context>

<tasks>

<task type="auto" tdd="true">
  <name>Task 1: main.go I/O 스캐폴드 + solve() 구현 및 main_test.go 테스트</name>
  <files>main.go, main_test.go</files>
  <read_first>
    - main.go (현재 상태 확인 — 이전 문제 코드 교체)
    - main_test.go (현재 상태 확인)
    - .planning/phases/07-boj-30398/07-CONTEXT.md (D-01~D-08 결정사항)
  </read_first>
  <behavior>
    - Test 1: N=4, d=2, P=1, point=(2,3) → 9
      (세그먼트1: (1,1)→(2,3) diffs=[1,2] S=3 → 3!/(1!2!)=3, 세그먼트2: (2,3)→(4,4) diffs=[2,1] S=3 → 3!/(2!1!)=3, 3×3=9)
    - Test 2: N=3, d=2, P=0 → 6
      (세그먼트1: (1,1)→(3,3) diffs=[2,2] S=4 → 4!/(2!2!)=6)
    - Test 3: N=2, d=3, P=1, point=(1,2,1) → 0
      (세그먼트1: (1,1,1)→(1,2,1) diffs=[0,1,0] S=1 → 1, 세그먼트2: (1,2,1)→(2,2,2) diffs=[1,0,1] S=2 → 2!/(1!0!1!)=2, 1×2=2)
      (수정: 이 케이스는 0이 아님. 실제 불가능 케이스: P=1 point=(3,1) N=3 d=2 → 세그먼트2에서 B_j-A_j=3-3=0,4-1=3 가능. 다시 계산해서 맞는 케이스 사용)
      실제 Test 3: N=3, d=2, P=1, point=(1,3) → 세그먼트2: (1,3)→(3,3) diffs=[2,0] S=2 → 2!/(2!0!)=1. 세그먼트1: (1,1)→(1,3) diffs=[0,2] S=2 → 2!/(0!2!)=1. 답=1.
    - Test 4: N=2, d=2, P=1, point=(3,1) → 0 (불가능: 세그먼트1 diffs=[2,-1] → B_j-A_j < 0이므로 0)
    - Test 5 (경계): N=1, d=1, P=0 → 1 (S=0, 다항계수=1)
  </behavior>
  <action>
    CONTEXT.md 결정사항(D-01~D-08)에 따라 구현한다.

    **main.go 구현:**
    1. 이전 문제 코드를 완전히 교체한다.
    2. Input 구조체:
       ```go
       type Input struct {
           N, D, P int
           Points  [][]int // length P, each length D; 중간점 좌표
       }
       ```
    3. parseInput 함수: bufio.Scanner로 입력 읽기.
       - 첫 줄: fmt.Sscan(line, &in.N, &in.D, &in.P)
       - 다음 P줄: 각 줄에서 d개 정수 읽어 Points 추가
         ```go
         for i := 0; i < in.P; i++ {
             scanner.Scan()
             fields := strings.Fields(scanner.Text())
             pt := make([]int, in.D)
             for j := 0; j < in.D; j++ {
                 pt[j], _ = strconv.Atoi(fields[j])
             }
             in.Points = append(in.Points, pt)
         }
         ```
       - import: "strings", "strconv" 추가
    4. solve 함수 시그니처: func solve(in Input) int64
    5. solve 로직 (per D-01~D-08):

       **전처리:**
       ```go
       const mod = 1_000_000_007
       maxN := in.N * in.D
       fact := make([]int64, maxN+1)
       invFact := make([]int64, maxN+1)
       fact[0] = 1
       for i := 1; i <= maxN; i++ {
           fact[i] = fact[i-1] * int64(i) % mod
       }
       // Fermat 소정리로 역팩토리얼 계산 (per D-06)
       invFact[maxN] = modpow(fact[maxN], mod-2, mod)
       for i := maxN - 1; i >= 0; i-- {
           invFact[i] = invFact[i+1] * int64(i+1) % mod
       }
       ```

       **점 배열 구성 (per D-01):**
       ```go
       // start = (1,...,1), end = (N,...,N)
       start := make([]int, in.D)
       end := make([]int, in.D)
       for j := 0; j < in.D; j++ {
           start[j] = 1
           end[j] = in.N
       }
       // allPoints: [start, points..., end]
       allPoints := make([][]int, 0, in.P+2)
       allPoints = append(allPoints, start)
       allPoints = append(allPoints, in.Points...)
       allPoints = append(allPoints, end)
       ```

       **구간별 다항계수 곱 (per D-02~D-05):**
       ```go
       ans := int64(1)
       for i := 0; i < len(allPoints)-1; i++ {
           A := allPoints[i]
           B := allPoints[i+1]
           S := 0
           for j := 0; j < in.D; j++ {
               diff := B[j] - A[j]
               if diff < 0 {
                   return 0  // 불가능 (per D-07)
               }
               S += diff
           }
           // 다항계수 = S! / (d_1! × ... × d_D!)
           coeff := fact[S]
           for j := 0; j < in.D; j++ {
               coeff = coeff * invFact[B[j]-A[j]] % mod
           }
           ans = ans * coeff % mod
       }
       return ans
       ```

       **modpow 헬퍼:**
       ```go
       func modpow(base, exp, mod int64) int64 {
           result := int64(1)
           base %= mod
           for exp > 0 {
               if exp%2 == 1 {
                   result = result * base % mod
               }
               base = base * base % mod
               exp /= 2
           }
           return result
       }
       ```

    6. main 함수: parseInput → solve → fmt.Fprintln(writer, result)
    7. bufio.Writer로 출력 (writer := bufio.NewWriter(os.Stdout); defer writer.Flush())

    **주의:**
    - N=1일 때 maxN = 1*D이므로 factoral 인덱스 범위 주의. maxN = N*D이므로 최소 D >= 1이면 문제없음.
    - P=0일 때 Points가 비어있어도 allPoints = [start, end]로 정상 동작.
    - 줄 제한 140자, cyclomatic complexity 15 이하 준수.
    - modpow의 mod 파라미터는 int64 타입으로 받는다.

    **main_test.go 구현:**
    1. TestSolve: table-driven 테스트, 최소 4개 케이스
    2. 각 케이스: Input{N, D, P, Points} → solve(in) → got vs want 비교 (int64)
    3. 예제(N=4,d=2,P=1) + P=0 케이스 + 불가능(0) 케이스 + 경계(N=1) 포함

    **검증:** go test -v ./... 통과, golangci-lint run . 통과 (140자 줄 제한, complexity 15 이하)
  </action>
  <verify>
    <automated>cd C:/Users/DELL/Documents/dev &amp;&amp; go test -v ./... &amp;&amp; golangci-lint run --allow-parallel-runners .</automated>
  </verify>
  <acceptance_criteria>
    - main.go contains `func solve(in Input) int64`
    - main.go contains `type Input struct`
    - main.go contains `func parseInput` with `bufio.Scanner`
    - main.go contains `func modpow`
    - main.go does NOT contain old problem code (processSegment, hPositions, wLeft, etc.)
    - main_test.go contains `func TestSolve`
    - main_test.go contains at least 4 test case entries
    - solve(Input{N:4, D:2, P:1, Points:[][]int{{2,3}}}) == 9
    - solve(Input{N:3, D:2, P:0, Points:nil}) == 6
    - solve(Input{N:2, D:2, P:1, Points:[][]int{{3,1}}}) == 0
    - `go test -v ./...` exits 0
    - `golangci-lint run .` exits 0
  </acceptance_criteria>
  <done>main.go에 BOJ 30398 풀이가 구현되고, main_test.go에 4개 이상 테스트가 통과하며, lint가 통과한다</done>
</task>

<task type="auto">
  <name>Task 2: history 아카이브 작성</name>
  <files>history/2026-W14-BOJ-30398.md</files>
  <read_first>
    - .planning/phases/07-boj-30398/07-CONTEXT.md (결정사항 참조)
    - main.go (구현된 코드 확인)
    - main_test.go (테스트 결과 확인)
  </read_first>
  <action>
    history/2026-W14-BOJ-30398.md를 UTF-8 BOM으로 작성한다 (per LOG-01).

    **필수 포함 항목 (per LOG-02):**
    1. 문제 요약: d차원 격자 (1,...,1)→(N,...,N), P개 중간점 순서 통과 경로 수를 mod 10^9+7로 출력.
       제약: 1≤N≤1000, 1≤d≤1000, 0≤P≤1000, N×d≤10^6.
    2. 핵심 알고리즘: D-01~D-07 — 구간 분할, 다항계수 = S!/(d_1!×...×d_D!),
       역팩토리얼 페르마 소정리, 전체 O(N×d + P×d)
    3. 실패/버린 아이디어: 각 구간 직접 격자 탐색 → 지수적 경우의 수, 불가능
    4. 최종 선택 이유: d차원 경로를 차원별 독립 이동의 순열로 보면 다항계수가 정확한 답
    5. 테스트 결과: go test 통과 여부, AC 여부

    **형식:** 기존 history 파일 패턴 따르기 (# 제목, ## 섹션)
    **인코딩:** UTF-8 BOM (Windows PowerShell 5.1 호환, per CLAUDE.md)
  </action>
  <verify>
    <automated>test -f "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30398.md" &amp;&amp; grep -q "핵심 알고리즘" "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30398.md" &amp;&amp; grep -q "테스트 결과" "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30398.md"</automated>
  </verify>
  <acceptance_criteria>
    - history/2026-W14-BOJ-30398.md exists
    - File contains "# BOJ 30398" or "문제 요약"
    - File contains "핵심 알고리즘"
    - File contains "실패" or "버린 아이디어"
    - File contains "선택 이유"
    - File contains "테스트 결과"
    - File is UTF-8 BOM encoded
  </acceptance_criteria>
  <done>history/2026-W14-BOJ-30398.md가 존재하고 풀이 요약, 핵심 알고리즘, 실패 아이디어, 선택 이유, 테스트 결과를 포함한다</done>
</task>

</tasks>

<verification>
1. `go test -v ./...` — 모든 테스트 통과 (예제 포함)
2. `golangci-lint run .` — lint 에러 없음
3. `test -f history/2026-W14-BOJ-30398.md` — history 파일 존재
4. main.go에 이전 문제 코드(processSegment 등)가 남아있지 않음
5. solve(N=4,d=2,P=1,point=(2,3)) == 9 확인
</verification>

<success_criteria>
1. main.go가 BOJ 30398 입력을 읽고 올바른 답을 출력한다
2. solve(N=4,d=2,P=1,point=(2,3)) == 9, solve(N=3,d=2,P=0) == 6, 불가능 케이스 == 0
3. main_test.go에 4개 이상의 테스트 케이스가 통과한다
4. golangci-lint 통과한다
5. history/2026-W14-BOJ-30398.md가 필수 항목을 포함한다
</success_criteria>

<output>
After completion, create `.planning/phases/07-boj-30398/07-01-SUMMARY.md`
</output>
