package main

import (
	"bufio"
	"fmt"
	"os"
)

const maxK = 4_000_001

var dist [maxK]int

func bfs() {
	for i := range dist {
		dist[i] = -1
	}
	queue := make([]int, 0, maxK)
	dist[1] = 0
	queue = append(queue, 1)
	for head := 0; head < len(queue); head++ {
		v := queue[head]
		if next := v * 2; next < maxK && dist[next] == -1 {
			dist[next] = dist[v] + 1
			queue = append(queue, next)
		}
		if next := v - 1; next > 0 && dist[next] == -1 {
			dist[next] = dist[v] + 1
			queue = append(queue, next)
		}
	}
}

var reader *bufio.Reader
var writer *bufio.Writer

func main() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	bfs()

	var t int
	fmt.Fscan(reader, &t)
	for i := 0; i < t; i++ {
		var k int
		fmt.Fscan(reader, &k)
		if dist[k] == -1 {
			fmt.Fprintln(writer, "Wrong proof!")
		} else {
			fmt.Fprintln(writer, dist[k])
		}
	}
}
