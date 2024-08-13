package main

import "math"

// https://leetcode.cn/problems/maximum-difference-score-in-a-grid/description/

func maxScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	res := math.MinInt
	for i, row := range grid {
		f[i] = make([]int, n)
		for j, v := range row {
			mn := math.MaxInt
			if i > 0 {
				mn = min(mn, f[i-1][j])
			}
			if j > 0 {
				mn = min(mn, f[i][j-1])
			}
			res = max(res, v-mn)
			f[i][j] = min(mn, v)
		}
	}
	return res
}
