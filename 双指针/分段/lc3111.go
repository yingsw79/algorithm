package main

import "slices"

// https://leetcode.cn/problems/minimum-rectangles-to-cover-points/description/

func minRectanglesToCoverPoints(points [][]int, w int) (res int) {
	slices.SortFunc(points, func(a, b []int) int { return a[0] - b[0] })
	n := len(points)
	for i := 0; i < n; i++ {
		j := i + 1
		for ; j < n && points[j][0]-points[i][0] <= w; j++ {
		}
		res++
		i = j - 1
	}
	return
}
