package main

import (
	"fmt"
	"sort"
)

func getPrimeNums(maxVal int) (primes []int, squarePrimes []int) {
	isNotPrime := make([]bool, maxVal+1)
	for i := 2; i*i <= maxVal; i++ {
		if isNotPrime[i] {
			continue
		}
		for j := i * 2; j <= maxVal; j += i {
			isNotPrime[j] = true
		}
	}
	for i := 2; i <= maxVal; i++ {
		if !isNotPrime[i] {
			primes = append(primes, i)
			if i == 2 || i%4 == 1 {
				squarePrimes = append(squarePrimes, i)
			}
		}
	}
	return
}

func solve(primes, squares []int, l, u int) (c1, c2 int) {
	li := sort.Search(len(primes), func(i int) bool {
		return primes[i] >= l
	})
	ui := sort.Search(len(primes), func(i int) bool {
		return primes[i] > u
	})
	ls := sort.Search(len(squares), func(i int) bool {
		return squares[i] >= l
	})
	us := sort.Search(len(squares), func(i int) bool {
		return squares[i] > u
	})
	c1 = ui - li
	c2 = us - ls
	return
}

func main() {
	const maxVal = 1000000
	primes, squares := getPrimeNums(maxVal)
	for {
		var l, u int
		_, err := fmt.Scan(&l, &u)
		if err != nil {
			panic(err)
		}
		if l == -1 && u == -1 {
			break
		}
		c1, c2 := solve(primes, squares, l, u)
		fmt.Println(l, u, c1, c2)
	}
}
