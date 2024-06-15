package main

import (
	"math"
	"sort"
)

// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/

func findMinArrowShots(points [][]int) (res int) {
	sort.Slice(points, func(i, j int) bool { return points[i][1] < points[j][1] })
	r := math.MinInt
	for _, p := range points {
		if p[0] > r {
			res++
			r = p[1]
		}
	}
	return
}
