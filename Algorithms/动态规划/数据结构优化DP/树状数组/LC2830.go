package main

import "sort"

// https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/

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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// func maximizeTheProfit(n int, offers [][]int) int {
// 	type pair struct{ start, gold int }
// 	groups := make([][]pair, n)
// 	for _, offer := range offers {
// 		start, end, gold := offer[0], offer[1], offer[2]
// 		groups[end] = append(groups[end], pair{start, gold})
// 	}

// 	f := make([]int, n+1)
// 	for end, g := range groups {
// 		f[end+1] = f[end]
// 		for _, p := range g {
// 			f[end+1] = max(f[end+1], f[p.start]+p.gold)
// 		}
// 	}
// 	return f[n]
// }

// func max(a, b int) int { if b > a { return b }; return a }
