package main

import (
	"bufio"
	"fmt"
	"os"
)

// Input holds all parsed values for BOJ 30867.
type Input struct {
	L, N int
	S    string
}

// parseInput reads two lines: "L N" then the string S.
func parseInput(scanner *bufio.Scanner) Input {
	var in Input
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &in.L, &in.N) //nolint:errcheck,gosec
	scanner.Scan()
	in.S = scanner.Text()
	return in
}

// solve applies N headache operations (wh→hw) in O(L) per D-01~D-05.
func solve(in Input) string {
	result := []byte(in.S)
	i := 0
	for i < in.L {
		// skip barrier characters (not 'w' or 'h') per D-01
		if result[i] != 'w' && result[i] != 'h' {
			i++
			continue
		}
		// find end of w/h segment
		j := i
		for j < in.L && (result[j] == 'w' || result[j] == 'h') {
			j++
		}
		processSegment(result[i:j], in.N)
		i = j
	}
	return string(result)
}

// processSegment rearranges h characters within a w/h-only segment per D-02~D-05.
// Each h moves left by min(wLeft, N) positions. No collision occurs (proven by ordering).
func processSegment(seg []byte, n int) {
	segLen := len(seg)
	hPositions := make([]int, 0, segLen)
	for k := 0; k < segLen; k++ {
		if seg[k] == 'h' {
			hPositions = append(hPositions, k)
		}
	}
	if len(hPositions) == 0 {
		return
	}
	newSeg := make([]byte, segLen)
	for hIdx, origPos := range hPositions {
		wLeft := origPos - hIdx // w count to the left of this h
		move := wLeft
		if n < move {
			move = n
		}
		newSeg[origPos-move] = 'h'
	}
	// fill remaining positions with 'w'
	for k := 0; k < segLen; k++ {
		if newSeg[k] == 0 {
			newSeg[k] = 'w'
		}
	}
	copy(seg, newSeg)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 1<<20), 1<<20)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush() //nolint:errcheck

	in := parseInput(scanner)
	fmt.Fprintln(writer, solve(in)) //nolint:errcheck
}
