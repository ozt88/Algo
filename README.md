# 알고리즘 문제 풀이

## Go Linter 설정

이 프로젝트는 `golangci-lint`를 사용합니다.

### 설치 방법

#### Windows (scoop 사용)
```powershell
scoop install golangci-lint
```

#### Windows (직접 설치)
1. [golangci-lint 릴리즈 페이지](https://github.com/golangci/golangci-lint/releases)에서 최신 버전 다운로드
2. 압축 해제 후 PATH에 추가

#### 다른 방법
```bash
# Go 1.21+ 사용 시
go install github.com/golangci/golangci-lint/cmd/golangci-lint@latest
```

### Just 설치

이 프로젝트는 `just`를 사용합니다.

#### Windows (scoop 사용)
```powershell
scoop install just
```

#### 다른 방법
```bash
# cargo 사용
cargo install just

# 또는 공식 설치 스크립트 사용
# https://github.com/casey/just#installation
```

### 사용 방법

```bash
# Linter 실행
just lint

# 자동 수정 가능한 문제 수정
just lint-fix

# 테스트 실행
just test

# 빌드
just build

# 실행 (input.txt 사용)
just run

# 모든 검사 (lint + test)
just check
```

또는 직접 실행:
```bash
golangci-lint run
golangci-lint run --fix
go test -v ./...
```

