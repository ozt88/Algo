package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name      string
		fruits    [][2]int
		endpoints [][2]int
		want      int
	}{
		{
			name: "예제1",
			fruits: [][2]int{
				{-1, -1}, {-1, 0}, {-1, 1},
				{1, 0}, {1, 1}, {1, 2},
				{2, 2}, {2, 4}, {3, 3},
			},
			endpoints: [][2]int{{0, 3}, {1, 1}, {4, 0}, {4, 4}, {3, 6}},
			want:      3,
		},
		{
			name:      "단일과일단일끝점_일치",
			fruits:    [][2]int{{1, 2}},
			endpoints: [][2]int{{1, 2}},
			want:      1,
		},
		{
			name:      "방향불일치",
			fruits:    [][2]int{{1, 2}},
			endpoints: [][2]int{{2, 1}},
			want:      0,
		},
	}
	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			got := solve(tc.fruits, tc.endpoints)
			if got != tc.want {
				t.Errorf("got %d, want %d", got, tc.want)
			}
		})
	}
}
