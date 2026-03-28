# Coding Conventions

**Analysis Date:** 2026-03-28

## Naming Patterns

**Files:**
- Go source files use lowercase with underscores for separation: `main.go`, `main_test.go`
- Test files follow Go convention: `*_test.go` suffix for files containing tests

**Functions:**
- PascalCase for exported functions: `Input`, `TestParseInput`, `TestSolve`
- camelCase for unexported functions: `parseInput`, `solve`, `solveBlock`
- Single letter names acceptable for loop variables: `h`, `i`, `j`, `k`, `n`

**Variables:**
- camelCase for local variables: `reader`, `maxLevel`, `blockCount`, `dpTable`
- camelCase for struct fields (both exported and unexported): `K`, `N`, `T1`, `T2` (exported); `ret` (unexported)
- Abbreviations used when standard: `K` (parameter K), `N` (parameter N), `T1`/`T2` (tree arrays)
- Short names for temporary/loop variables: `h`, `i`, `j`, `in`, `got`, `want`, `tt`

**Types:**
- PascalCase for struct names: `Input`
- Struct fields use PascalCase: `K`, `N`, `T1`, `T2`

**Constants:**
- Not observed in codebase

## Code Style

**Formatting:**
- Configured via golangci-yml with goimports
- Line length limit: 140 characters (configured in `.golangci.yml`)
- EditorConfig enforces: Unix line endings (LF), final newline required

**Linting:**
- Tool: golangci-lint v2 (`.golangci.yml`)
- Key rules enabled:
  - `errcheck`: Type assertion and blank checks enabled
  - `gocritic`: All enabled tags (diagnostic, experimental, opinionated, performance, style)
  - `gocyclo`: Minimum complexity threshold of 15
  - `goimports`: Local prefix `algo` for import organization
  - `govet`: Shadow variable checking enabled
  - `staticcheck`: Used for static analysis
  - `gosec`: Security linting (disabled for test files)
- Formatters: `gofmt` and `goimports`

## Import Organization

**Order:**
1. Standard library imports (e.g., `"bufio"`, `"fmt"`, `"io"`, `"os"`, `"strings"`, `"testing"`)
2. Third-party imports (none observed in codebase)
3. Local imports (none observed in codebase)

**Path Aliases:**
- Local prefix set to `algo` in goimports configuration

## Error Handling

**Patterns:**
- Direct return of error-prone function results without wrapping (e.g., `fmt.Fscan`)
- No explicit error handling with error returns observed in main functions
- Testing uses `t.Fatalf()` for error conditions with formatted output

## Logging

**Framework:** Standard library `fmt` package used

**Patterns:**
- `fmt.Fscan()` for input reading with side effects
- `fmt.Println()` for output
- No structured logging observed
- No debug-level logging patterns used

## Comments

**When to Comment:**
- No comments observed in production code
- Code is self-documenting through clear function and variable names
- Test names provide documentation through descriptive strings in table-driven tests

**JSDoc/TSDoc:**
- Not applicable (Go codebase, no JavaScript/TypeScript)

## Function Design

**Size:**
- Functions kept reasonably small: `parseInput` ~23 lines, `solve` ~47 lines
- Nested functions used when appropriate: `solveBlock` defined within `solve`

**Parameters:**
- Functions accept minimal parameters: `parseInput(r io.Reader)`, `solve(input Input)`
- Receiver pattern not heavily used (not an OOP-heavy codebase)

**Return Values:**
- Simple return types: `(Input)`, `(int)`
- Named returns not used

## Module Design

**Exports:**
- Minimal exports: `Input` struct, test functions
- Most functions unexported (lowercase): `parseInput`, `solve`
- Single package `main` used throughout

**Barrel Files:**
- Not applicable to Go codebase

## Testing Locations

Test files co-located with source:
- `main.go` paired with `main_test.go` in same directory
- Testing package from standard library: `"testing"`

---

*Convention analysis: 2026-03-28*
