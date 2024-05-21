package main

import (
	"slices"
	"sort"
)

// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-05-04
// https://leetcode.cn/problems/maximum-earnings-from-taxi/description/?envType=daily-question&envId=2023-12-08

// 二分
func jobScheduling(startTime []int, endTime []int, profit []int) int {
	n := len(startTime)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(a, b int) int { return endTime[a] - endTime[b] })
	f := make([]int, n+1)
	for i, x := range idx {
		j := sort.Search(i, func(j int) bool { return endTime[idx[j]] > startTime[x] })
		f[i+1] = max(f[i], f[j]+profit[x])
	}
	return f[n]
}

// 树状数组
func _jobScheduling(startTime []int, endTime []int, profit []int) int {
	allTime := append(slices.Clone(startTime), endTime...)
	slices.Sort(allTime)
	n := len(allTime)
	tr := make([]int, n+1)
	update := func(x, v int) {
		for ; x <= n; x += x & -x {
			tr[x] = max(tr[x], v)
		}
	}
	query := func(x int) (res int) {
		for ; x > 0; x &= x - 1 {
			res = max(res, tr[x])
		}
		return
	}
	idx := make([]int, len(startTime))
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(a, b int) int { return endTime[a] - endTime[b] })
	for _, i := range idx {
		update(sort.SearchInts(allTime, endTime[i])+1, query(sort.SearchInts(allTime, startTime[i])+1)+profit[i])
	}
	return query(n)
}
