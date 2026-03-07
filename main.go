package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const (
	dirUp = iota
	dirDown
	dirLeft
	dirRight
	dirLeftUp
	dirLeftDown
	dirRightUp
	dirRightDown
)

type Input struct {
	NoteRaw string
	KeysRaw string
	Note    []int
	Keys    []int
}

func parseInput(r io.Reader) Input {
	reader := bufio.NewReader(r)

	var noteRaw, keysRaw string
	fmt.Fscan(reader, &noteRaw)
	fmt.Fscan(reader, &keysRaw)

	return Input{
		NoteRaw: noteRaw,
		KeysRaw: keysRaw,
		Note:    parseNote(noteRaw),
		Keys:    parseKeys(keysRaw),
	}
}

func parseNote(s string) []int {
	note := make([]int, 0, len(s))
	for i := 0; i < len(s); {
		dir, next := parseDirectionToken(s, i)
		if next < len(s) && s[next] == '!' {
			dir = reverseDirection(dir)
			next++
		}
		note = append(note, dir)
		i = next
	}
	return note
}

func parseDirectionToken(s string, i int) (int, int) {
	switch s[i] {
	case 'W':
		return dirUp, i + 1
	case 'A':
		return dirLeft, i + 1
	case 'S':
		return dirDown, i + 1
	case 'D':
		return dirRight, i + 1
	case 'L':
		if s[i+1] == 'U' {
			return dirLeftUp, i + 2
		}
		return dirLeftDown, i + 2
	case 'R':
		if s[i+1] == 'U' {
			return dirRightUp, i + 2
		}
		return dirRightDown, i + 2
	default:
		panic("invalid direction token")
	}
}

func reverseDirection(dir int) int {
	switch dir {
	case dirUp:
		return dirDown
	case dirDown:
		return dirUp
	case dirLeft:
		return dirRight
	case dirRight:
		return dirLeft
	case dirLeftUp:
		return dirRightDown
	case dirLeftDown:
		return dirRightUp
	case dirRightUp:
		return dirLeftDown
	default:
		return dirLeftUp
	}
}

func parseKeys(s string) []int {
	keys := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		keys[i] = keyToDirection(s[i])
	}
	return keys
}

func keyToDirection(ch byte) int {
	switch ch {
	case 'W', '8':
		return dirUp
	case 'S', '2':
		return dirDown
	case 'A', '4':
		return dirLeft
	case 'D', '6':
		return dirRight
	case '7':
		return dirLeftUp
	case '1':
		return dirLeftDown
	case '9':
		return dirRightUp
	case '3':
		return dirRightDown
	default:
		panic("invalid input key")
	}
}

func solve(input Input) string {
	return judgeSkeleton(input.Note, input.Keys)
}

func judgeSkeleton(note, keys []int) string {
	matched := 0
	lv := len(note)

	for _, key := range keys {
		_ = key
		if matched == lv {
			matched = 0
			continue
		}

		// TODO(user): complete state transition.
		// If key matches note[matched], increment matched.
		// Otherwise reset matched to 0.
		matched = 0
	}

	if matched == lv {
		return "Yes"
	}
	return "No"
}

func main() {
	input := parseInput(os.Stdin)
	fmt.Println(solve(input))
}
