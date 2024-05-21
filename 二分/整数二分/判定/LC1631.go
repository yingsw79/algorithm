package main

import "sort"

// https://leetcode.cn/problems/path-with-minimum-effort/description/?envType=daily-question&envId=2023-12-11

func minimumEffortPath(heights [][]int) int {
	m, n := len(heights), len(heights[0])
	dirs := []struct{ x, y int }{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}
	st := make([]bool, m*n)
	var dfs func(int, int, int) bool
	dfs = func(x, y, d int) bool {
		if x == m-1 && y == n-1 {
			return true
		}
		st[x*n+y] = true
		for _, v := range dirs {
			a, b := x+v.x, y+v.y
			if a >= 0 && a < m && b >= 0 && b < n &&
				!st[a*n+b] && abs(heights[a][b]-heights[x][y]) <= d &&
				dfs(a, b, d) {
				return true
			}
		}
		return false
	}
	return sort.Search(1e6, func(d int) bool {
		clear(st)
		return dfs(0, 0, d)
	})
}

func abs(a int) int { if a < 0 { return -a }; return a }
