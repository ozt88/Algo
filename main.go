package main

import (
	"bufio"
	"fmt"
	"os"
)

var writer *bufio.Writer

// Input holds all parsed values for BOJ 1117.
type Input struct {
	W, H, F, C, X1, Y1, X2, Y2 int64
}

func minInt64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func maxInt64(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

// parseInput reads one line and parses 8 space-separated integers.
func parseInput(scanner *bufio.Scanner) Input {
	scanner.Scan()
	line := scanner.Text()
	var in Input
	fmt.Sscan(line, &in.W, &in.H, &in.F, &in.C, &in.X1, &in.Y1, &in.X2, &in.Y2) //nolint:errcheck,gosec
	return in
}

// solve computes the uncoloured area after folding and painting per D-01~D-07.
func solve(in Input) int64 {
	// x-direction: vertical fold at x=f
	// overlap = [0, min(f, W-f)] — region covered by both halves when folded
	overlap := minInt64(in.F, in.W-in.F)

	// doubled: portion of [x1,x2] that lands in the overlap zone → painted on 2 original strips
	doubled := maxInt64(0, minInt64(in.X2, overlap)-in.X1)
	single := (in.X2 - in.X1) - doubled
	paintedX := doubled*2 + single

	// y-direction: horizontal fold c times → c+1 original strips covered
	paintedY := (in.Y2 - in.Y1) * (in.C + 1)

	return in.W*in.H - paintedX*paintedY
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 1<<20), 1<<20)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush() //nolint:errcheck

	in := parseInput(scanner)
	fmt.Fprintln(writer, solve(in)) //nolint:errcheck
}
