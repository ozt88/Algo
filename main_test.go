package main

import (
	"testing"
)

func TestBFS(t *testing.T) {
	bfs()

	tests := []struct {
		k    int
		want int
	}{
		{1, 0},
		{7, 4},
		{2, 1},
		{4, 2},
		{3, 3},
		{4_000_000, 30}, // 경계값, Wrong proof! 안 나옴 확인
	}

	for _, tt := range tests {
		got := dist[tt.k]
		if got != tt.want {
			t.Errorf("dist[%d] = %d, want %d", tt.k, got, tt.want)
		}
	}
}
