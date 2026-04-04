package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Input holds all parsed values for BOJ 30398.
type Input struct {
	N, D, P int
	Points  [][]int // length P, each length D; 중간점 좌표
}

// parseInput reads the problem input: first line "N D P", then P lines each with D integers.
func parseInput(scanner *bufio.Scanner) Input {
	var in Input
	scanner.Scan()
	fmt.Sscan(scanner.Text(), &in.N, &in.D, &in.P) //nolint:errcheck,gosec
	in.Points = make([][]int, 0, in.P)
	for i := 0; i < in.P; i++ {
		scanner.Scan()
		fields := strings.Fields(scanner.Text())
		pt := make([]int, in.D)
		for j := 0; j < in.D; j++ {
			pt[j], _ = strconv.Atoi(fields[j])
		}
		in.Points = append(in.Points, pt)
	}
	return in
}

// modpow computes base^exp mod m using fast exponentiation.
func modpow(base, exp, m int64) int64 {
	result := int64(1)
	base %= m
	for exp > 0 {
		if exp%2 == 1 {
			result = result * base % m
		}
		base = base * base % m
		exp /= 2
	}
	return result
}

// solve computes the number of lattice paths from (1,...,1) to (N,...,N) passing through
// P intermediate points in order, modulo 10^9+7.
// Uses multinomial coefficients with factorial precomputation (D-01~D-08).
func solve(in Input) int64 {
	const mod = int64(1_000_000_007)
	maxN := in.N * in.D
	fact := make([]int64, maxN+1)
	invFact := make([]int64, maxN+1)
	fact[0] = 1
	for i := 1; i <= maxN; i++ {
		fact[i] = fact[i-1] * int64(i) % mod
	}
	// Fermat's little theorem: inv(k!) = (k!)^(MOD-2) mod MOD (D-06)
	invFact[maxN] = modpow(fact[maxN], mod-2, mod)
	for i := maxN - 1; i >= 0; i-- {
		invFact[i] = invFact[i+1] * int64(i+1) % mod
	}

	// Build allPoints: [start, points..., end] (D-01)
	start := make([]int, in.D)
	end := make([]int, in.D)
	for j := 0; j < in.D; j++ {
		start[j] = 1
		end[j] = in.N
	}
	allPoints := make([][]int, 0, in.P+2)
	allPoints = append(allPoints, start)
	allPoints = append(allPoints, in.Points...)
	allPoints = append(allPoints, end)

	// Multiply multinomial coefficient for each segment (D-02~D-07)
	ans := int64(1)
	for i := 0; i < len(allPoints)-1; i++ {
		A := allPoints[i]
		B := allPoints[i+1]
		S := 0
		for j := 0; j < in.D; j++ {
			diff := B[j] - A[j]
			if diff < 0 {
				return 0 // impossible segment (D-07)
			}
			S += diff
		}
		// multinomial = S! / (d_1! × ... × d_D!) (D-03)
		coeff := fact[S]
		for j := 0; j < in.D; j++ {
			coeff = coeff * invFact[B[j]-A[j]] % mod
		}
		ans = ans * coeff % mod
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 1<<20), 1<<20)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush() //nolint:errcheck

	in := parseInput(scanner)
	fmt.Fprintln(writer, solve(in)) //nolint:errcheck
}
