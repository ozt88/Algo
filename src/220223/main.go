package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(nums []int, n int) int {
	notSortedIndex := -1
	for i := range nums {
		if i > 0 && nums[i] < nums[i-1] {
			if notSortedIndex != -1 {
				return 0
			}
			notSortedIndex = i
		}
	}
	if notSortedIndex == -1 {
		return n
	}
	ret := 0
	// try to remove notSortedIndex - 1
	if notSortedIndex < 2 || nums[notSortedIndex] >= nums[notSortedIndex-2] {
		ret++
	}
	// try to remove notSortedIndex
	if notSortedIndex == n-1 || nums[notSortedIndex-1] <= nums[notSortedIndex+1] {
		ret++
	}
	return ret
}

func main() {
	in := bufio.NewReader(os.Stdin)
	n := readInt(in)
	nums := readArrInt(in)
	if len(nums) != n {
		panic("len(nums) != n")
	}
	fmt.Println(solve(nums, n))
	return
}

func readInt(in *bufio.Reader) int {
	nStr, _ := in.ReadString('\n')
	nStr = strings.ReplaceAll(nStr, "\r", "")
	nStr = strings.ReplaceAll(nStr, "\n", "")
	n, _ := strconv.Atoi(nStr)
	return n
}

func readLineNumbs(in *bufio.Reader) []string {
	line, _ := in.ReadString('\n')
	line = strings.ReplaceAll(line, "\r", "")
	line = strings.ReplaceAll(line, "\n", "")
	numbs := strings.Split(line, " ")
	return numbs
}

func readArrInt(in *bufio.Reader) []int {
	numbs := readLineNumbs(in)
	arr := make([]int, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.Atoi(n)
		arr[i] = val
	}
	return arr
}

func readArrInt64(in *bufio.Reader) []int64 {
	numbs := readLineNumbs(in)
	arr := make([]int64, len(numbs))
	for i, n := range numbs {
		val, _ := strconv.ParseInt(n, 10, 64)
		arr[i] = val
	}
	return arr
}
