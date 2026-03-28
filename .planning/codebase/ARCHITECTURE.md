# Architecture

**Analysis Date:** 2026-03-28

## Pattern Overview

**Overall:** Monolithic single-file algorithmic solver with memoized recursion pattern

**Key Characteristics:**
- Standard competitive programming structure: single Go package with input parsing, core logic, and main entry point
- Top-down dynamic programming with memoization (recursive state caching)
- Pure functional approach: no external dependencies, no state mutations beyond DP table
- Problem-specific domain types for input representation

## Layers

**Input/Output Layer:**
- Purpose: Parse command-line input and format output
- Location: `main.go` (functions `parseInput`, `main`)
- Contains: Input struct definition, buffered reader parsing
- Depends on: Go standard library only (bufio, fmt, io, os)
- Used by: main entry point

**Core Algorithm Layer:**
- Purpose: Execute the memoized recursion to solve the binary tree matching problem
- Location: `main.go` (function `solve`)
- Contains: DP table initialization, recursive state computation, memoization logic
- Depends on: Input struct from Input/Output Layer
- Used by: main function

**Testing Layer:**
- Purpose: Verify correctness through unit tests
- Location: `main_test.go`
- Contains: Test cases for parsing and end-to-end solving
- Depends on: strings package (for test input generation)
- Used by: go test runner

## Data Flow

**Problem-Solving Flow:**

1. **Input Parsing** (`parseInput`): Read k, N (calculated as 2^(k-1)), T1 array, T2 array from stdin
2. **DP Initialization** (`solve`): Create 3D DP table with dimensions [maxLevel+1][blockCount][blockCount], initialize all to -1
3. **Recursive Computation** (`solveBlock`): For each (h, i, j) state:
   - Base case (h=0): Compare single leaf values, return 1 if equal, 0 if different
   - Recursive case (h>0): Compute maximum of same-order matching vs cross-order matching
4. **Memoization Check**: Before computing, check if dpTable[h][i][j] != -1; if cached, return cached value
5. **Output**: Return solveBlock(maxLevel, 0, 0) result to stdout

**State Management:**
- DP table indexed by three dimensions:
  - `h`: height/level (0 = leaf, maxLevel = root)
  - `i`: block index in T1 (0 to blockCount-1)
  - `j`: block index in T2 (0 to blockCount-1)
- Each cell caches the maximum matching cardinality for that subtree pair
- No side effects; all computation is deterministic

## Key Abstractions

**Input Type:**
- Purpose: Encapsulate the problem input with computed metadata
- Examples: `main.go` lines 10-15
- Pattern: Simple struct with explicit fields for k, n, T1, T2

**DP State (h, i, j):**
- Purpose: Represent a subproblem defined by tree height and block indices
- Pattern: Implicit via function parameters and memoization closure
- Semantics: f(h, i, j) = maximum subset size achievable when matching T1's i-th block at height h with T2's j-th block

**Matching Directions:**
- Purpose: Model the two valid strategies at each recursive level
- Pattern: Explicit computation of sameOrder vs crossOrder; maximum selection
- Semantics:
  - sameOrder: T1[left] pairs with T2[left], T1[right] pairs with T2[right]
  - crossOrder: T1[left] pairs with T2[right], T1[right] pairs with T2[left]

## Entry Points

**main():**
- Location: `main.go` lines 90-93
- Triggers: Program execution via `go run main.go` or `./algo.exe`
- Responsibilities:
  1. Read input from stdin via parseInput
  2. Call solve with parsed input
  3. Print integer result to stdout

**parseInput(io.Reader) Input:**
- Location: `main.go` lines 17-40
- Triggers: Called by main function
- Responsibilities:
  1. Read k from first line
  2. Calculate N = 2^(k-1)
  3. Allocate and populate T1, T2 arrays
  4. Return fully populated Input struct

**solve(Input) int:**
- Location: `main.go` lines 42-88
- Triggers: Called by main after input parsing
- Responsibilities:
  1. Initialize DP table with -1 sentinel values
  2. Define nested recursive function solveBlock
  3. Invoke solveBlock(maxLevel, 0, 0)
  4. Return final result

## Error Handling

**Strategy:** Implicit handling via zero values and panic-on-invalid-input

**Patterns:**
- Input validation is minimal; malformed input will cause Fscan to fail silently (leaving zero values)
- No explicit error types or error checking (appropriate for competitive programming context)
- Out-of-bounds access is prevented by precondition assumptions (k, N sizes must match)
- Negative array indices prevented by invariant: i < blockCount, j < blockCount maintained by recursion structure

## Cross-Cutting Concerns

**Logging:** Not present; competitive programming context uses minimal output (final answer only)

**Validation:** Implicit via constraints:
- k must satisfy 1 <= k <= 12 (implied by problem statement)
- T1, T2 must be permutations of 1..N (assumed valid per problem)
- Matching logic assumes complete binary tree structure

**Authentication:** Not applicable; single-process solver

---

*Architecture analysis: 2026-03-28*
