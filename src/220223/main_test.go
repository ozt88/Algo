package main

import (
	"testing"
)

func TestSolve(t *testing.T) {
	for _, tt := range []struct {
		desc string
		give []int
		want int
	}{
		{give: []int{1, 2, 3, 2}, want: 2},
		{give: []int{1, 2, 3, 3}, want: 4},
		{give: []int{1, 2, 1, 0}, want: 0},
		{give: []int{1, 1}, want: 2},
		{give: []int{9, 1}, want: 2},
		{give: []int{9, 1, 3}, want: 1},
		{give: []int{0, 1, 3, 2, 2}, want: 1},
		{give: []int{0, 9, 1}, want: 2},
	} {
		t.Run(tt.desc, func(t *testing.T) {
			if got := solve(tt.give, len(tt.give)); got != tt.want {
				t.Fatalf("in: %v got: %v want: %v", tt.give, got, tt.want)
			}
		})
	}
}
