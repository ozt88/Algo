# Testing Patterns

**Analysis Date:** 2026-03-28

## Test Framework

**Runner:**
- Go standard library `testing` package
- Version: Go 1.18 (from `go.mod`)
- Config: `.golangci.yml` for linting configuration

**Assertion Library:**
- Standard library `testing.T` with manual assertions

**Run Commands:**
```bash
go test ./...              # Run all tests
go test -v ./...           # Run with verbose output
go test -cover ./...       # Run with coverage reporting
```

## Test File Organization

**Location:**
- Co-located with source files in same directory
- Pattern: `*_test.go` for test files

**Naming:**
- Test functions: `Test<FunctionName>` format
  - `TestParseInput` for `parseInput()` function
  - `TestSolve` for `solve()` function

**Structure:**
```
main_test.go
├── TestParseInput          # Unit test for parseInput
└── TestSolve               # Table-driven test with subtests
```

## Test Structure

**Suite Organization:**
```go
func TestParseInput(t *testing.T) {
	in := `4
4 2 1 3 6 7 5 8
2 7 4 8 3 1 6 5`

	got := parseInput(strings.NewReader(in))

	// Assertion checks
	if got.K != 4 {
		t.Fatalf("K = %d, want 4", got.K)
	}
	// ... more assertions
}

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   string
		want int
	}{
		// ... test cases
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			// ... test implementation
		})
	}
}
```

**Patterns:**
- Direct function calls without setup/teardown
- Input data provided as test parameters (inline strings)
- Multiple assertions per test (fail-fast approach with `t.Fatalf`)
- Table-driven tests used for parametrized test cases (`TestSolve`)
- Subtests using `t.Run()` for organization within table-driven tests

## Mocking

**Framework:** Not used

**Patterns:**
- No mocking observed; functions accept `io.Reader` interface for flexibility
- Direct dependency injection: `parseInput(strings.NewReader(in))`

**What to Mock:**
- I/O operations use interfaces: `io.Reader` allows testing with `strings.NewReader`

**What NOT to Mock:**
- Core algorithm logic (`solve`, `solveBlock`) is tested directly
- No external dependencies to mock

## Fixtures and Factories

**Test Data:**
```go
tests := []struct {
	name string
	in   string
	want int
}{
	{
		name: "sample",
		in: `4
4 2 1 3 6 7 5 8
2 7 4 8 3 1 6 5`,
		want: 4,
	},
	{
		name: "identical trees",
		in: `3
1 2 3 4
1 2 3 4`,
		want: 4,
	},
	// ... more test cases
}
```

**Location:**
- Test data defined inline within test functions
- No separate fixture files

## Coverage

**Requirements:** Not enforced

**View Coverage:**
```bash
go test -cover ./...           # Summary coverage
go test -coverprofile=cov.out ./...
go tool cover -html=cov.out    # HTML report
```

## Test Types

**Unit Tests:**
- Direct function testing via `parseInput()` and `solve()` functions
- Scope: Individual function behavior with known inputs/outputs

**Integration Tests:**
- Not explicitly present
- Could be added via end-to-end input/output scenarios

**E2E Tests:**
- Not used
- Manual testing via `input.txt` and compiled `test.exe` binary

## Common Patterns

**Async Testing:**
- Not applicable (no concurrency in current tests)

**Error Testing:**
```go
if got.K != 4 {
	t.Fatalf("K = %d, want 4", got.K)
}
if got.T1[0] != 4 || got.T1[7] != 8 {
	t.Fatalf("T1 parse failed: got %v", got.T1)
}
```

Pattern: Direct comparison with `if` statements, fail with `t.Fatalf()` on mismatch.

**Test Case Definition:**
- Struct-based table-driven testing
- Named test cases via `name` field for `t.Run()` identification
- Multi-line input strings for complex parsing tests

## Linting Configuration for Tests

From `.golangci.yml`:
- Test files (matching `_test.go`) have reduced linting requirements:
  - `errcheck` disabled (error checking not required in tests)
  - `gosec` disabled (security checks relaxed in tests)
  - `gocyclo` disabled (complexity limits relaxed in tests)

---

*Testing analysis: 2026-03-28*
