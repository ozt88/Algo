package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   Input
		want int64
	}{
		// BOJ 예제 입출력
		{name: "예제1", in: Input{W: 5, H: 6, F: 2, C: 2, X1: 1, Y1: 1, X2: 3, Y2: 2}, want: 21},
		{name: "예제2", in: Input{W: 3, H: 13, F: 1, C: 0, X1: 1, Y1: 8, X2: 2, Y2: 12}, want: 35},
		{name: "예제3", in: Input{W: 12, H: 12, F: 7, C: 3, X1: 3, Y1: 1, X2: 6, Y2: 2}, want: 124},
		{name: "예제4", in: Input{W: 4, H: 5, F: 4, C: 0, X1: 0, Y1: 0, X2: 1, Y2: 1}, want: 19},
		{name: "예제5", in: Input{W: 4, H: 8, F: 4, C: 3, X1: 0, Y1: 1, X2: 2, Y2: 2}, want: 24},
		{name: "예제6", in: Input{W: 4, H: 8, F: 3, C: 0, X1: 1, Y1: 1, X2: 3, Y2: 2}, want: 30},
		// 엣지 케이스
		{
			name: "int64_오버플로검증",
			in: Input{
				W: 1_000_000_000, H: 1_000_000_000, F: 500_000_000, C: 0,
				X1: 0, Y1: 0, X2: 500_000_000, Y2: 500_000_000,
			},
			want: 500_000_000_000_000_000,
		},
		{
			name: "f=0_접기선왼쪽끝",
			in:   Input{W: 10, H: 10, F: 0, C: 0, X1: 1, Y1: 1, X2: 3, Y2: 3},
			want: 96,
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
