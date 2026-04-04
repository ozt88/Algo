package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   Input
		want int64
	}{
		// BOJ 30398 예제 및 계산 검증
		// N=4, d=2, P=1, point=(2,3): seg1 diffs=[1,2] S=3→3, seg2 diffs=[2,1] S=3→3, 3×3=9
		{
			name: "예제_N4d2P1",
			in:   Input{N: 4, D: 2, P: 1, Points: [][]int{{2, 3}}},
			want: 9,
		},
		// N=3, d=2, P=0: seg diffs=[2,2] S=4 → 4!/(2!2!)=6
		{
			name: "P0_N3d2",
			in:   Input{N: 3, D: 2, P: 0, Points: nil},
			want: 6,
		},
		// 불가능 케이스: N=2, d=2, P=1, point=(3,1) → seg1 diffs=[2,-1] → 0
		{
			name: "불가능_역방향",
			in:   Input{N: 2, D: 2, P: 1, Points: [][]int{{3, 1}}},
			want: 0,
		},
		// N=3, d=2, P=1, point=(1,3): seg1 diffs=[0,2] S=2→1, seg2 diffs=[2,0] S=2→1, 1×1=1
		{
			name: "경계점_N3d2P1",
			in:   Input{N: 3, D: 2, P: 1, Points: [][]int{{1, 3}}},
			want: 1,
		},
		// N=1, d=1, P=0: seg diffs=[0] S=0 → 0!/0!=1
		{
			name: "최소_N1d1P0",
			in:   Input{N: 1, D: 1, P: 0, Points: nil},
			want: 1,
		},
	}
	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			got := solve(tc.in)
			if got != tc.want {
				t.Errorf("got %d, want %d", got, tc.want)
			}
		})
	}
}
