package main

import "testing"

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   Input
		want int64
	}{
		{
			name: "기본_세로접기없음",
			// W=10,H=10,f=1,x1=1,y1=1,x2=2,y2=2,c=0
			// overlap=min(1,9)=1, doubled=max(0,min(2,1)-1)=0, single=1, paintedX=1
			// paintedY=(2-1)*(0+1)=1, answer=100-1=99
			in:   Input{W: 10, H: 10, F: 1, X1: 1, Y1: 1, X2: 2, Y2: 2, C: 0},
			want: 99,
		},
		{
			name: "세로접기_가로접기",
			// W=10,H=10,f=3,x1=1,y1=1,x2=2,y2=2,c=1
			// overlap=min(3,7)=3, doubled=max(0,min(2,3)-1)=1, single=0, paintedX=2
			// paintedY=(2-1)*(1+1)=2, answer=100-4=96
			in:   Input{W: 10, H: 10, F: 3, X1: 1, Y1: 1, X2: 2, Y2: 2, C: 1},
			want: 96,
		},
		{
			name: "int64_오버플로검증",
			// W=H=10^9, f=5e8: overlap=5e8, doubled=5e8, single=0, paintedX=10^9
			// paintedY=5e8, answer=10^18-5*10^17=5*10^17
			in: Input{
				W: 1_000_000_000, H: 1_000_000_000, F: 500_000_000,
				X1: 0, Y1: 0, X2: 500_000_000, Y2: 500_000_000, C: 0,
			},
			want: 500_000_000_000_000_000,
		},
		{
			name: "f=0_접기선왼쪽끝",
			// overlap=min(0,W)=0, doubled=0, single=x2-x1, paintedX=x2-x1
			// paintedY=(y2-y1)*(c+1), answer=W*H - paintedX*paintedY
			in:   Input{W: 10, H: 10, F: 0, X1: 1, Y1: 1, X2: 3, Y2: 3, C: 0},
			want: 96,
		},
		{
			name: "x1=x2_painted_x=0",
			// x1==x2 → x2-x1=0 → paintedX=0, answer=W*H
			in:   Input{W: 10, H: 10, F: 5, X1: 3, Y1: 1, X2: 3, Y2: 5, C: 2},
			want: 100,
		},
		{
			name: "c최대값",
			// c=10^9, W=10,H=10,f=5,x1=0,y1=0,x2=1,y2=1,c=1000000000
			// overlap=5, doubled=1, single=0, paintedX=2
			// paintedY=1*(1000000000+1)=1000000001, answer=100-2*1000000001<0? no
			// answer=100-(2*1000000001)=100-2000000002=-1999999902 → but that can't be right
			// actually W=100,H=100 to avoid negative answer
			// W=10^9,H=10^9,f=5,x1=0,y1=0,x2=1,y2=1,c=10^9-1
			// paintedX=2, paintedY=1*10^9=10^9, answer=10^18-2*10^9
			in:   Input{W: 1_000_000_000, H: 1_000_000_000, F: 5, X1: 0, Y1: 0, X2: 1, Y2: 1, C: 1_000_000_000 - 1},
			want: 1_000_000_000_000_000_000 - 2_000_000_000,
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
