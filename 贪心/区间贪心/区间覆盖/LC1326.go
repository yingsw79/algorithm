package main

import "sort"

// https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

func minTaps(n int, ranges []int) (res int) {
	q := make([][]int, n+1)
	for i, v := range ranges {
		q[i] = []int{i - v, i + v}
	}
	sort.Slice(q, func(i, j int) bool { return q[i][0] < q[j][0] })
	for st, i := 0, 0; i < n+1; {
		j, r := i, -1
		for ; j < n+1 && q[j][0] <= st; j++ {
			r = max(r, q[j][1])
		}
		if r < st {
			break
		}
		res++
		if r >= n {
			return
		}
		i, st = j, r
	}
	return -1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
