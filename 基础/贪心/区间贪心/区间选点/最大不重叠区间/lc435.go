package main

import (
	"math"
	"slices"
)

// https://leetcode.cn/problems/non-overlapping-intervals/description/

func eraseOverlapIntervals(intervals [][]int) int {
	slices.SortFunc(intervals, func(a, b []int) int { return a[1] - b[1] })
	r := math.MinInt
	s := 0
	for _, p := range intervals {
		if p[0] >= r {
			s++
			r = p[1]
		}
	}
	return len(intervals) - s
}
