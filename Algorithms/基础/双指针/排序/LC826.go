package main

import "slices"

// https://leetcode.cn/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-05-17

func maxProfitAssignment(difficulty []int, profit []int, worker []int) (res int) {
	n := len(profit)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	slices.Sort(worker)
	slices.SortFunc(idx, func(a, b int) int { return difficulty[a] - difficulty[b] })
	var j, mx int
	for _, v := range worker {
		for ; j < n && difficulty[idx[j]] <= v; j++ {
			mx = max(mx, profit[idx[j]])
		}
		res += mx
	}
	return
}
