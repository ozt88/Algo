---
phase: 06-boj-30867
plan: 01
type: execute
wave: 1
depends_on: []
files_modified:
  - main.go
  - main_test.go
  - history/2026-W14-BOJ-30867.md
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
    - "main.go가 BOJ 30867 입력을 읽고 N번 두통 연산 결과를 출력한다"
    - "w/h가 아닌 문자는 장벽으로 처리되어 세그먼트를 분리한다"
    - "각 세그먼트 내 h가 min(왼쪽_w개수, N)칸 왼쪽으로 이동한다"
    - "O(L) 시간복잡도로 동작하며 N번 시뮬레이션을 하지 않는다"
    - "main_test.go에 최소 4개 테스트 케이스가 통과한다"
    - "history 아카이브가 존재한다"
  artifacts:
    - path: "main.go"
      provides: "BOJ 30867 풀이 (parseInput + solve)"
      contains: "func solve"
    - path: "main_test.go"
      provides: "테스트 케이스"
      contains: "func TestSolve"
    - path: "history/2026-W14-BOJ-30867.md"
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
BOJ 30867 (과제가 너무 많아) 풀이를 구현하고 테스트하여 AC를 받을 수 있는 상태로 만든다.

Purpose: 길이 L 문자열에 N번 두통 연산(wh→hw 버블링)을 O(L)로 처리하는 문제를 Go로 해결한다.
Output: main.go (풀이), main_test.go (테스트), history/2026-W14-BOJ-30867.md (아카이브)
</objective>

<execution_context>
@$HOME/.claude/get-shit-done/workflows/execute-plan.md
@$HOME/.claude/get-shit-done/templates/summary.md
</execution_context>

<context>
@.planning/PROJECT.md
@.planning/ROADMAP.md
@.planning/STATE.md
@.planning/phases/06-boj-30867/06-CONTEXT.md
</context>

<tasks>

<task type="auto" tdd="true">
  <name>Task 1: main.go I/O 스캐폴드 + solve() 구현 및 main_test.go 테스트</name>
  <files>main.go, main_test.go</files>
  <read_first>
    - main.go (현재 상태 확인 — 이전 문제 코드 덮어쓰기)
    - main_test.go (현재 상태 확인)
    - .planning/phases/06-boj-30867/06-CONTEXT.md (D-01~D-06 결정사항)
  </read_first>
  <behavior>
    - Test 1: L=4, N=1, S="what" → "hwat"  (세그먼트 "what": h 1개, 왼쪽 w 1개, min(1,1)=1칸 이동 → h는 인덱스 0으로)
    - Test 2: L=4, N=200000, S="hcpc" → "hcpc"  (장벽 'c','p' 있어 세그먼트 "h": h만 있어 이동 불가)
    - Test 3: L=6, N=2, S="whwwhw" → "hwhwww"  (세그먼트 "whwwhw": h 2개, 각각의 왼쪽 w개수 min N 계산)
    - Test 4: L=1, N=1, S="w" → "w"  (h 없는 세그먼트는 그대로)
  </behavior>
  <action>
    CONTEXT.md 결정사항(D-01~D-06)에 따라 구현한다.

    **main.go 구현:**
    1. 이전 문제 코드를 완전히 교체한다.
    2. Input 구조체: L, N int; S string  (per D-06: int로 충분)
    3. parseInput 함수: bufio.Scanner로 두 줄 읽기.
       - 첫 줄: fmt.Sscan(line1, &in.L, &in.N)
       - 둘째 줄: in.S = scanner.Text()
    4. solve 함수 시그니처: func solve(in Input) string
    5. solve 로직 (per D-01~D-05):

       ```
       result := []byte(in.S)

       i := 0
       for i < in.L {
           // 장벽 건너뜀: w/h가 아닌 문자 (per D-01)
           if result[i] != 'w' && result[i] != 'h' {
               i++
               continue
           }
           // 세그먼트 시작: w/h만 있는 구간 찾기
           j := i
           for j < in.L && (result[j] == 'w' || result[j] == 'h') {
               j++
           }
           // 세그먼트 result[i..j) 처리 (per D-02~D-05)
           seg := result[i:j]
           segLen := j - i

           // h 위치 수집
           hPositions := []int{}
           wCount := 0
           for k := 0; k < segLen; k++ {
               if seg[k] == 'w' {
                   wCount++
               } else { // 'h'
                   hPositions = append(hPositions, k)
               }
           }

           // 각 h의 새 위치 계산 (per D-03)
           // h의 왼쪽 w개수 = (h의 원위치) - (h 앞의 h개수)
           // 새 위치 = 원위치 - min(왼쪽_w개수, N)
           // 충돌 없음: 증명 — h_k 새위치 = pos_k - min(wLeft_k, N)
           //   wLeft_k ≥ wLeft_{k-1}이고 pos_k > pos_{k-1}이므로 순서 보존
           newSeg := make([]byte, segLen)
           hIdx := 0
           for _, origPos := range hPositions {
               wLeft := origPos - hIdx  // 이 h 앞의 w개수 = 원위치 - (앞의 h개수)
               move := wLeft
               if in.N < move {
                   move = in.N
               }
               newPos := origPos - move
               newSeg[newPos] = 'h'
               hIdx++
           }
           // 빈 자리를 'w'로 채움
           for k := 0; k < segLen; k++ {
               if newSeg[k] == 0 {
                   newSeg[k] = 'w'
               }
           }
           copy(seg, newSeg)

           i = j
       }
       return string(result)
       ```

    6. main 함수: parseInput → solve → fmt.Fprintln(writer, result)
    7. bufio.Writer로 출력 (writer := bufio.NewWriter(os.Stdout); defer writer.Flush())

    **주의:**
    - h가 없는 세그먼트(w만 있는 경우)는 변경 없이 그대로 유지된다.
    - 세그먼트 내 w가 없으면 h 위치 변화 없음 (move=0).
    - 줄 제한 140자, cyclomatic complexity 15 이하 준수.

    **main_test.go 구현:**
    1. TestSolve: table-driven 테스트, 최소 4개 케이스
    2. 각 케이스: Input{L, N, S} → solve(in) → got vs want 비교
    3. 예제 3개(문제 공식) + 엣지 케이스 1개 이상 포함

    **검증:** go test -v ./... 통과, golangci-lint run . 통과 (140자 줄 제한, complexity 15 이하)
  </action>
  <verify>
    <automated>cd C:/Users/DELL/Documents/dev &amp;&amp; go test -v ./... &amp;&amp; golangci-lint run --allow-parallel-runners .</automated>
  </verify>
  <acceptance_criteria>
    - main.go contains `func solve(in Input) string`
    - main.go contains `type Input struct`
    - main.go contains `func parseInput` with `bufio.Scanner`
    - main.go does NOT contain old problem code (cubeState, rollTable, paintedX, etc.)
    - main_test.go contains `func TestSolve`
    - main_test.go contains at least 4 test case entries
    - solve(Input{4, 1, "what"}) == "hwat"
    - solve(Input{4, 200000, "hcpc"}) == "hcpc"
    - solve(Input{6, 2, "whwwhw"}) == "hwhwww"
    - `go test -v ./...` exits 0
    - `golangci-lint run .` exits 0
  </acceptance_criteria>
  <done>main.go에 BOJ 30867 풀이가 구현되고, main_test.go에 4개 이상 테스트가 통과하며, lint가 통과한다</done>
</task>

<task type="auto">
  <name>Task 2: history 아카이브 작성</name>
  <files>history/2026-W14-BOJ-30867.md</files>
  <read_first>
    - .planning/phases/06-boj-30867/06-CONTEXT.md (결정사항 참조)
    - main.go (구현된 코드 확인)
    - main_test.go (테스트 결과 확인)
  </read_first>
  <action>
    history/2026-W14-BOJ-30867.md를 UTF-8 BOM으로 작성한다 (per LOG-01).

    **필수 포함 항목 (per LOG-02):**
    1. 문제 요약: 길이 L 문자열에 N번 두통 연산(wh→hw) 적용 결과 출력. w/h 외 문자는 장벽.
    2. 핵심 알고리즘: D-01~D-05 — 세그먼트 분리, h의 새 위치 = 원위치 - min(왼쪽_w개수, N), O(L) 단일 패스
    3. 실패/버린 아이디어: N번 직접 시뮬레이션 O(L×N) → TLE로 폐기
    4. 최종 선택 이유: h끼리 충돌 불가 수학적 증명으로 단일 패스 O(L) 가능
    5. 테스트 결과: go test 통과 여부, AC 여부

    **형식:** 기존 history 파일 패턴 따르기 (# 제목, ## 섹션)
    **인코딩:** UTF-8 BOM (Windows PowerShell 5.1 호환, per CLAUDE.md)
  </action>
  <verify>
    <automated>test -f "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30867.md" &amp;&amp; grep -q "핵심 알고리즘" "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30867.md" &amp;&amp; grep -q "테스트 결과" "C:/Users/DELL/Documents/dev/history/2026-W14-BOJ-30867.md"</automated>
  </verify>
  <acceptance_criteria>
    - history/2026-W14-BOJ-30867.md exists
    - File contains "문제 요약" or "# BOJ 30867"
    - File contains "핵심 알고리즘"
    - File contains "실패" or "버린 아이디어"
    - File contains "선택 이유"
    - File contains "테스트 결과"
    - File is UTF-8 BOM encoded
  </acceptance_criteria>
  <done>history/2026-W14-BOJ-30867.md가 존재하고 풀이 요약, 핵심 알고리즘, 실패 아이디어, 선택 이유, 테스트 결과를 포함한다</done>
</task>

</tasks>

<verification>
1. `go test -v ./...` — 모든 테스트 통과 (예제 3개 포함)
2. `golangci-lint run .` — lint 에러 없음
3. `test -f history/2026-W14-BOJ-30867.md` — history 파일 존재
4. main.go에 이전 문제 코드가 남아있지 않음
</verification>

<success_criteria>
1. main.go가 BOJ 30867 입력을 읽고 올바른 답을 출력한다
2. solve("what", N=1) == "hwat", solve("hcpc", N=200000) == "hcpc", solve("whwwhw", N=2) == "hwhwww"
3. main_test.go에 4개 이상의 테스트 케이스가 통과한다
4. golangci-lint 통과한다
5. history/2026-W14-BOJ-30867.md가 필수 항목을 포함한다
</success_criteria>

<output>
After completion, create `.planning/phases/06-boj-30867/06-01-SUMMARY.md`
</output>
