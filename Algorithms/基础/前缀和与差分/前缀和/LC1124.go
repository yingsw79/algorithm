package main

import "math"

// https://leetcode.cn/problems/longest-well-performing-interval/

func longestWPI(hours []int) (res int) {
	const (
		N int = 2e4 + 10
		B int = 1e4
	)
	prefix := [N]int{}
	for i := range prefix {
		prefix[i] = math.MaxInt32
	}
	prefix[B] = 0
	sum := 0
	for i, v := range hours {
		if v > 8 {
			sum++
		} else {
			sum--
		}
		if prefix[sum+B] == math.MaxInt32 {
			prefix[sum+B] = i + 1
		}
	}
	for i := 1; i < N; i++ {
		prefix[i] = min(prefix[i], prefix[i-1])
	}
	sum = 0
	for i, v := range hours {
		if v > 8 {
			sum++
		} else {
			sum--
		}
		j := prefix[sum+B-1]
		res = max(res, i+1-j)
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
