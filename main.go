package main

import (
	"bufio"
	"container/list"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader
var writer *bufio.Writer

// cubeState: [바닥=0, 윗=1, 북=2, 남=3, 동=4, 서=5] 포지션에 있는 면 번호
type cubeState [6]int

// rollTable[s][dir] = 다음 s (dir: 0=북,1=남,2=동,3=서)
var rollTable [36][4]int

// applyRoll: 방향별 cubeState 전환
// 북으로 굴리기: 새 바닥←기존 북, 새 북←기존 윗, 새 윗←기존 남, 새 남←기존 바닥 (동/서 불변)
func applyRoll(f cubeState, dir int) cubeState {
	n := f
	switch dir {
	case 0: // 북
		n[0], n[2], n[1], n[3] = f[2], f[1], f[3], f[0]
	case 1: // 남
		n[0], n[3], n[1], n[2] = f[3], f[1], f[2], f[0]
	case 2: // 동
		n[0], n[4], n[1], n[5] = f[4], f[1], f[5], f[0]
	case 3: // 서
		n[0], n[5], n[1], n[4] = f[5], f[1], f[4], f[0]
	}
	return n
}

func stateID(f cubeState) int {
	return f[2]*6 + f[0] // north_face*6 + bottom_face
}

func buildRollTable() {
	init0 := cubeState{0, 1, 2, 3, 4, 5}
	visited := make(map[int]cubeState)
	queue := list.New()
	queue.PushBack(init0)
	visited[stateID(init0)] = init0
	for queue.Len() > 0 {
		cur := queue.Remove(queue.Front()).(cubeState)
		sid := stateID(cur)
		for d := 0; d < 4; d++ {
			nxt := applyRoll(cur, d)
			nid := stateID(nxt)
			rollTable[sid][d] = nid
			if _, ok := visited[nid]; !ok {
				visited[nid] = nxt
				queue.PushBack(nxt)
			}
		}
	}
}

var dr4 = [4]int{-1, 1, 0, 0}
var dc4 = [4]int{0, 0, 1, -1}

// solve: N×M 격자, 탐정 위치 (dr,dc), 도둑 위치 (rr,rc)를 받아
// 최소 굴리기 횟수 반환. 승리 불가 시 -1 반환.
// 상태: dp[r][c][s], s = north_face*6 + bottom_face (0~35, 유효 24개)
// 초기 s = 12 (bottom=0 뚫린면, north=2)
func solve(grid []string, dr, dc, rr, rc int) int {
	n := len(grid)
	m := len(grid[0])
	const inf = math.MaxInt32
	dp := make([][][36]int, n)
	for i := range dp {
		dp[i] = make([][36]int, m)
		for j := range dp[i] {
			for s := range dp[i][j] {
				dp[i][j][s] = inf
			}
		}
	}
	initS := 12 // bottom=0, north=2
	dp[dr][dc][initS] = 0
	type state struct{ r, c, s int }
	queue := list.New()
	queue.PushBack(state{dr, dc, initS})
	for queue.Len() > 0 {
		cur := queue.Remove(queue.Front()).(state)
		cost := dp[cur.r][cur.c][cur.s]
		for d := 0; d < 4; d++ {
			nr, nc := cur.r+dr4[d], cur.c+dc4[d]
			if nr < 0 || nr >= n || nc < 0 || nc >= m {
				continue
			}
			if grid[nr][nc] == '#' {
				continue
			}
			ns := rollTable[cur.s][d]
			bottom := ns % 6
			if nr == rr && nc == rc {
				if bottom == 0 {
					return cost + 1
				}
				continue // 막힌 면 — 스킵
			}
			if cost+1 < dp[nr][nc][ns] {
				dp[nr][nc][ns] = cost + 1
				queue.PushBack(state{nr, nc, ns})
			}
		}
	}
	return -1
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush() //nolint:errcheck
	buildRollTable()
	var n, m int
	fmt.Fscan(reader, &n, &m) //nolint:errcheck,gosec
	grid := make([]string, n)
	var startR, startC, robR, robC int
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &grid[i]) //nolint:errcheck,gosec
		for j, ch := range grid[i] {
			switch ch {
			case 'D':
				startR, startC = i, j
			case 'R':
				robR, robC = i, j
			}
		}
	}
	fmt.Fprintln(writer, solve(grid, startR, startC, robR, robC)) //nolint:errcheck
}
