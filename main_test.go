package main

import (
	"reflect"
	"strings"
	"testing"
)

func TestParseNote(t *testing.T) {
	got := parseNote("WLU!LDAS!D!RD!")
	want := []int{
		dirUp,
		dirRightDown,
		dirLeftDown,
		dirLeft,
		dirUp,
		dirLeft,
		dirLeftUp,
	}

	if !reflect.DeepEqual(got, want) {
		t.Fatalf("parseNote() = %v, want %v", got, want)
	}
}

func TestParseKeys(t *testing.T) {
	got := parseKeys("W31A447")
	want := []int{
		dirUp,
		dirRightDown,
		dirLeftDown,
		dirLeft,
		dirLeft,
		dirLeft,
		dirLeftUp,
	}

	if !reflect.DeepEqual(got, want) {
		t.Fatalf("parseKeys() = %v, want %v", got, want)
	}
}

func TestParseInput(t *testing.T) {
	input := parseInput(strings.NewReader("DD!DDDD!\nDDDDDDDDDDDD\n"))

	if input.NoteRaw != "DD!DDDD!" {
		t.Fatalf("note raw parse failed: got %q", input.NoteRaw)
	}
	if input.KeysRaw != "DDDDDDDDDDDD" {
		t.Fatalf("keys raw parse failed: got %q", input.KeysRaw)
	}
	if len(input.Note) != 6 {
		t.Fatalf("note length = %d, want 6", len(input.Note))
	}
	if len(input.Keys) != 12 {
		t.Fatalf("keys length = %d, want 12", len(input.Keys))
	}
}

func TestSolve(t *testing.T) {
	tests := []struct {
		name string
		in   string
		want string
	}{
		{
			name: "sample 1",
			in: "WLU!LDAS!D!RD!\nW31AW47\n",
			want: "Yes",
		},
		{
			name: "sample 2",
			in: "DDDDDD\nDDDDDDD\n",
			want: "No",
		},
		{
			name: "sample 3",
			in: "DD!DDDD!\nDDDDDDDDDDDD\n",
			want: "No",
		},
		{
			name: "sample 4",
			in: "WLU!LDAS!D!RD!\nW31A447W\n",
			want: "No",
		},
		{
			name: "extra key makes length mismatch",
			in: "DDDDDD\nDDDDDD6\n",
			want: "No",
		},
		{
			name: "mixed key representation matches",
			in: "WDRD\n863\n",
			want: "Yes",
		},
		{
			name: "same length but one direction differs",
			in: "WDRD\n861\n",
			want: "No",
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			input := parseInput(strings.NewReader(tt.in))
			got := solve(input)
			if got != tt.want {
				t.Fatalf("solve() = %q, want %q", got, tt.want)
			}
		})
	}
}
