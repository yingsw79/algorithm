package main

// https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/

func findMaxFish(grid [][]int) (res int) {
	m, n := len(grid), len(grid[0])
	dirs := []struct{ x, y int }{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}
	var dfs func(int, int) int
	dfs = func(x, y int) int {
		s := grid[x][y]
		grid[x][y] = 0
		for _, d := range dirs {
			a, b := x+d.x, y+d.y
			if a >= 0 && a < m && b >= 0 && b < n && grid[a][b] > 0 {
				s += dfs(a, b)
			}
		}
		return s
	}
	for i, g := range grid {
		for j, v := range g {
			if v > 0 {
				res = max(res, dfs(i, j))
			}
		}
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
