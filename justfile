# Go 알고리즘 문제 풀이 프로젝트

set shell := ["powershell.exe", "-c"]

# Linter 실행
lint:
    @$ErrorActionPreference = 'SilentlyContinue'; $env:GOLANGCI_LINT_CACHE = "$env:TEMP\golangci-lint"; $env:GOCACHE = "$env:TEMP\go-build"; golangci-lint run --allow-parallel-runners .; if ($LASTEXITCODE -eq 0) { exit 0 } else { exit 1 }

# Linter 자동 수정
lint-fix:
    golangci-lint run --fix

# 테스트 실행
test:
    go test -v ./...

# 빌드
build:
    go build -o algo.exe main.go

# 실행 (input.txt 사용)
run:
    Get-Content input.txt | go run main.go

# 모든 검사 (lint + test)
check: lint test
