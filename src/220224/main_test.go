package main

import (
	"fmt"
	"testing"
)

func TestSolve(t *testing.T) {
	for i, tt := range []struct {
		n    int
		want int
	}{
		{25, 1},
		{26, 2},
		{11339, 3},
		{34567, 4},
	} {
		t.Run(fmt.Sprint(i), func(t *testing.T) {
			if got := solve(tt.n); got != tt.want {
				t.Fatalf("in: %v got: %v want: %v", tt.n, got, tt.want)
			}
		})
	}
}
