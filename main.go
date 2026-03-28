package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var reader *bufio.Reader
var writer *bufio.Writer

func gcd(a, b int) int {
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

type dir struct{ x, y int }

func solve(fruits, endpoints [][2]int) int {
	// 방향별 scale 배열 구성 (사용자 설계)
	dirMap := make(map[dir][]int)
	for _, f := range fruits {
		fx, fy := f[0], f[1]
		g := gcd(fx, fy)
		d := dir{fx / g, fy / g}
		dirMap[d] = append(dirMap[d], g)
	}
	for d := range dirMap {
		sort.Ints(dirMap[d])
	}

	// 끝점마다 binary search로 포함 과일 수 계산
	ans := 0
	for _, e := range endpoints {
		ex, ey := e[0], e[1]
		g := gcd(ex, ey)
		d := dir{ex / g, ey / g}
		scales := dirMap[d]
		// scale <= g 인 과일 수
		cnt := sort.SearchInts(scales, g+1)
		if cnt > ans {
			ans = cnt
		}
	}
	return ans
}

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer func() { _ = writer.Flush() }()

	var n, m int
	fmt.Fscan(reader, &n, &m) //nolint:errcheck,gosec

	fruits := make([][2]int, n)
	for i := range fruits {
		fmt.Fscan(reader, &fruits[i][0], &fruits[i][1]) //nolint:errcheck,gosec
	}

	endpoints := make([][2]int, m)
	for i := range endpoints {
		fmt.Fscan(reader, &endpoints[i][0], &endpoints[i][1]) //nolint:errcheck,gosec
	}

	fmt.Fprintln(writer, solve(fruits, endpoints)) //nolint:errcheck
}
