package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   Input
		want string
	}{
		// BOJ 30867 예제 입출력
		{name: "예제1_what", in: Input{L: 4, N: 1, S: "what"}, want: "hwat"},
		{name: "예제2_hcpc", in: Input{L: 4, N: 200000, S: "hcpc"}, want: "hcpc"},
		{name: "예제3_whwwhw", in: Input{L: 6, N: 2, S: "whwwhw"}, want: "hwhwww"},
		// 엣지 케이스
		{name: "h없는세그먼트", in: Input{L: 1, N: 1, S: "w"}, want: "w"},
		{name: "w없는세그먼트", in: Input{L: 1, N: 1, S: "h"}, want: "h"},
		{name: "장벽만", in: Input{L: 3, N: 1, S: "abc"}, want: "abc"},
		{name: "N보다w가적음", in: Input{L: 3, N: 100, S: "wwh"}, want: "hww"},
		{name: "여러세그먼트", in: Input{L: 7, N: 1, S: "wh_wh_w"}, want: "hw_hw_w"},
	}
	for _, tc := range tests {
		t.Run(tc.name, func(t *testing.T) {
			got := solve(tc.in)
			if got != tc.want {
				t.Errorf("got %q, want %q", got, tc.want)
			}
		})
	}
}
