package main

import "slices"

// https://leetcode.cn/problems/merge-intervals/
// https://leetcode.cn/problems/count-days-without-meetings/description/

func merge(intervals [][]int) (res [][]int) {
	slices.SortFunc(intervals, func(a, b []int) int { return a[0] - b[0] })
	l, r := intervals[0][0], intervals[0][1]
	for _, v := range intervals[1:] {
		if v[0] > r {
			res = append(res, []int{l, r})
			l = v[0]
		}
		r = max(r, v[1])
	}
	res = append(res, []int{l, r})
	return
}
