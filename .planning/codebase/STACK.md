# Technology Stack

**Analysis Date:** 2026-03-28

## Languages

**Primary:**
- Go 1.18 - Algorithm problem solving and core logic implementation

## Runtime

**Environment:**
- Go 1.18 runtime

**Package Manager:**
- Go Modules
- Lockfile: Not detected (no go.sum present)

## Frameworks

**Testing:**
- Go standard testing package - Native test framework for unit testing
- Location: `main_test.go`

**Build/Dev:**
- Just - Command runner for task automation
- golangci-lint - Comprehensive Go linting and code quality tool
- go build - Standard Go build tool

## Key Dependencies

**External:**
- None detected - Project uses only Go standard library

**Standard Library Imports:**
- `bufio` - Buffered I/O operations (`main.go`)
- `fmt` - Formatted I/O (`main.go`)
- `io` - Input/output interfaces (`main.go`)
- `os` - Operating system interactions (`main.go`)
- `strings` - String manipulation (`main_test.go`)
- `testing` - Testing framework (`main_test.go`)

## Configuration

**Linting:**
- `.golangci.yml` - GoLangCI-Lint configuration with strict linting rules
  - Line length limit: 140 characters
  - Cyclomatic complexity minimum: 15
  - Local import prefix: `algo`
  - Enabled linters: errcheck, goconst, gocritic, gocyclo, gosec, govet, ineffassign, lll, misspell, nolintlint, staticcheck, unconvert, unparam, unused, whitespace
  - Test exclusions for: errcheck, gosec, gocyclo

**Build:**
- `go.mod` - Module declaration with Go 1.18

**Editor:**
- `.editorconfig` - Editor configuration for code formatting consistency

**Task Runner:**
- `justfile` - Just configuration with tasks for lint, test, build, and run operations

## Platform Requirements

**Development:**
- Go 1.18 or later
- Just (command runner)
- golangci-lint (linting tool, installable via scoop or cargo)
- Windows PowerShell (for just tasks - shell is set to powershell.exe)

**Production:**
- Go 1.18 runtime
- Executable: `algo.exe` (Windows binary)

---

*Stack analysis: 2026-03-28*
