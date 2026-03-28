package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		grid []string
		dr   int
		dc   int
		rr   int
		rc   int
		want int
	}{
		{
			name: "예제1_4회",
			grid: []string{
				"#####",
				"#D..#",
				"#.#.#",
				"#..R#",
				"#####",
			},
			dr: 1, dc: 1,
			rr: 3, rc: 3,
			want: 4,
		},
		{
			name: "예제2_7회",
			grid: []string{
				"#####",
				"#..##",
				"#..R#",
				"##.##",
				"##D##",
				"#####",
			},
			dr: 4, dc: 2,
			rr: 2, rc: 3,
			want: 7,
		},
		{
			name: "예제3_불가능",
			grid: []string{
				"######",
				"#R..D#",
				"#.##.#",
				"######",
			},
			dr: 1, dc: 4,
			rr: 1, rc: 1,
			want: -1,
		},
	}
	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			buildRollTable()
			got := solve(tc.grid, tc.dr, tc.dc, tc.rr, tc.rc)
			if got != tc.want {
				t.Errorf("got %d, want %d", got, tc.want)
			}
		})
	}
}
