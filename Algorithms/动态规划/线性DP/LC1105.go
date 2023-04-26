package main

import "math"

// https://leetcode.cn/problems/filling-bookcase-shelves/

func minHeightShelves(books [][]int, shelfWidth int) int {
	n := len(books)
	f := make([]int, n+1)
	for i := range books {
		f[i+1] = math.MaxInt
		maxH, leftW := 0, shelfWidth
		for j := i; j >= 0; j-- {
			leftW -= books[j][0]
			if leftW < 0 {
				break
			}
			maxH = max(maxH, books[j][1])
			f[i+1] = min(f[i+1], f[j]+maxH)
		}
	}
	return f[n]
}

func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
