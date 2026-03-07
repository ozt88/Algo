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
