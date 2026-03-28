# Codebase Structure

**Analysis Date:** 2026-03-28

## Directory Layout

```
algo/
├── main.go                 # Core solver: input parsing, DP logic, entry point
├── main_test.go            # Unit and integration tests
├── plan.md                 # Active problem solving plan document
├── README.md               # Setup and tool usage instructions
├── AGENTS.md               # Collaboration protocol and conventions for this project
├── go.mod                  # Go module definition
├── justfile                # Task automation (lint, test, build, run)
├── .golangci.yml           # Go linter configuration
├── history/                # Archive of completed problem solutions
│   ├── README.md
│   ├── TEMPLATE.md
│   └── 2026-Www-BOJ-xxxxx.md   # Historical solutions with plans
└── .planning/
    └── codebase/           # Strategic analysis documents (this directory)
        ├── ARCHITECTURE.md
        ├── STRUCTURE.md
        ├── CONVENTIONS.md
        ├── TESTING.md
        ├── STACK.md
        ├── INTEGRATIONS.md
        └── CONCERNS.md
```

## Directory Purposes

**Root (`algo/`):**
- Purpose: Single-problem Go module for algorithm competition solutions
- Contains: Main source files, test files, configuration, documentation
- Key files: `main.go`, `main_test.go`, `go.mod`, `justfile`

**`history/`:**
- Purpose: Archive and reference library of previously completed problems
- Contains: Markdown plan documents for each solved problem
- Key files: `TEMPLATE.md` (reusable format), `README.md` (archive guide), individual problem docs

**`.planning/codebase/`:**
- Purpose: Strategic codebase analysis and navigation documents
- Contains: Architecture, structure, conventions, testing patterns, stack analysis, integration details, and technical concerns
- Key files: This document set (ARCHITECTURE.md, STRUCTURE.md, CONVENTIONS.md, TESTING.md, STACK.md, INTEGRATIONS.md, CONCERNS.md)

## Key File Locations

**Entry Points:**
- `main.go`: Program entry via main() function; single package execution point

**Configuration:**
- `.golangci.yml`: Linter configuration for code quality enforcement
- `go.mod`: Module declaration with Go version 1.18 requirement
- `justfile`: Task automation with PowerShell target (build, test, lint, run)
- `README.md`: Tool setup instructions (golangci-lint, just installation and usage)

**Core Logic:**
- `main.go` lines 42-88: solve() function with memoized recursive DP algorithm
- `main.go` lines 17-40: parseInput() for stdin parsing

**Testing:**
- `main_test.go`: TestParseInput() and TestSolve() covering parsing and end-to-end solving

**Documentation:**
- `plan.md`: Active problem breakdown (observations, algorithm design, test notes)
- `AGENTS.md`: Collaboration protocol (role boundaries, response format, hint depth policy)
- `history/`: Completed problem archive with Korean Markdown documents

## Naming Conventions

**Files:**
- Source: `main.go`, `main_test.go` (standard Go naming)
- Plans: `plan.md` (active), `YYYY-Www-BOJ-<id>.md` in history/ (completed problems)
- Configuration: `.golangci.yml` (dotfile for tools), `justfile` (task runner config), `go.mod` (module manifest)

**Directories:**
- Lowercase with underscores: `history/`, `.planning/` (internal directories)
- Dotfiles and underscores: `.golangci.yml`, `justfile` follow Go convention

**Functions:**
- camelCase (standard Go): `parseInput`, `solve`, `solveBlock`, `main`
- Exported (capitalized): None in main package (all helpers private)
- Test functions: `TestParseInput`, `TestSolve` (Go testing convention)

**Types:**
- PascalCase: `Input` (struct for input representation)
- Field names: camelCase within structs (K, N, T1, T2)

**Variables:**
- Short loop counters: `h`, `i`, `j` (standard for indices and heights)
- Descriptive names: `maxLevel`, `blockCount`, `sameOrder`, `crossOrder`, `solveBlock`

## Where to Add New Code

**New Feature/Problem:**
- Primary code: `main.go` (modify solve() and related helpers)
- Entry point: Keep main() and parseInput() as provided
- Tests: `main_test.go` (extend TestSolve with new test cases)

**New Function/Helper:**
- Location: `main.go` in main package
- Pattern: Define as private function (lowercase) unless exported
- Scope: Keep algorithmic helpers within solve() as nested functions or defined at package level

**Utilities/Constants:**
- Shared helpers: Keep in `main.go` at package level above main function
- Problem-specific constants: Define near top of file or within solve() as needed

**Test Data:**
- Location: `main_test.go` within test struct literals (TestSolve.tests slice)
- Pattern: Use strings.NewReader() for stdin simulation
- Expansion: Add test cases to the tests slice in TestSolve

## Special Directories

**`history/`:**
- Purpose: Preserve completed problem analyses and learning artifacts
- Generated: No (manually archived from plan.md)
- Committed: Yes (git tracked; provides reference for future problems)
- Naming: `YYYY-Www-BOJ-<id>.md` format with week number
- Language: Korean Markdown (UTF-8 with BOM for Windows compatibility)

**`.planning/codebase/`:**
- Purpose: Strategic codebase documentation for navigator/executor agents
- Generated: Yes (created by `/gsd:map-codebase` workflow)
- Committed: Yes (tracks current codebase understanding)
- Contents: ARCHITECTURE.md, STRUCTURE.md, CONVENTIONS.md, TESTING.md, STACK.md, INTEGRATIONS.md, CONCERNS.md

**`.claude/`:**
- Purpose: Claude IDE workspace settings
- Generated: Yes (IDE-managed)
- Committed: Partially (settings.local.json present)

## File Reading Order

When navigating this codebase:

1. Start with `AGENTS.md` to understand collaboration protocol
2. Read `plan.md` for current problem understanding
3. Read `main.go` for complete algorithm implementation
4. Reference `main_test.go` for expected behavior
5. Consult `README.md` for tool setup
6. Check `history/` for related solved problems

---

*Structure analysis: 2026-03-28*
