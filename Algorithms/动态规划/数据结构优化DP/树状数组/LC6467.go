package main

import "sort"

// https://leetcode.cn/problems/find-the-longest-equal-subarray/

func maximizeTheProfit(n int, offers [][]int) (res int) {
	sort.Slice(offers, func(i, j int) bool { return offers[i][1] < offers[j][1] })
	tr := make([]int, n+1)
	update := func(x, c int) {
		for ; x <= n; x += x & -x {
			tr[x] = max(tr[x], c)
		}
	}
	query := func(x int) (res int) {
		for ; x > 0; x &= x - 1 {
			res = max(res, tr[x])
		}
		return
	}
	for _, v := range offers {
		t := query(v[0]) + v[2]
		update(v[1]+1, t)
		res = max(res, t)
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }
