package main

import (
	"fmt"
	"testing"
)

func TestJob(t *testing.T) {
	const maxVal = 1000000
	primes, squares := getPrimeNums(maxVal)
	for _, tt := range []struct {
		l, u           int
		wantC1, wantC2 int
	}{
		{l: 10, u: 20, wantC1: 4, wantC2: 2},
		{l: 11, u: 19, wantC1: 4, wantC2: 2},
		{l: 100, u: 1000, wantC1: 143, wantC2: 69},
	} {
		t.Run(fmt.Sprintf("%d~%d", tt.l, tt.u), func(t *testing.T) {
			c1, c2 := solve(primes, squares, tt.l, tt.u)
			if c1 != tt.wantC1 || c2 != tt.wantC2 {
				t.Errorf("got %d, %d; want %d, %d", c1, c2, tt.wantC1, tt.wantC2)
			}
		})
	}
}
