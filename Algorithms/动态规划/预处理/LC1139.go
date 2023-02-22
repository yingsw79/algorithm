package main

// https://leetcode.cn/problems/largest-1-bordered-square/

func largest1BorderedSquare(grid [][]int) (res int) {
	const N int = 100
	m, n := len(grid), len(grid[0])
	L, U := [N][N]int{}, [N][N]int{}
	for i, g := range grid {
		for j, v := range g {
			if j == 0 {
				L[i][j] = v
			} else {
				L[i][j] = v
				if v == 1 {
					L[i][j] += L[i][j-1]
				}
			}
		}
	}
	for j := 0; j < n; j++ {
		for i := 0; i < m; i++ {
			if i == 0 {
				U[i][j] = grid[i][j]
			} else {
				U[i][j] = grid[i][j]
				if grid[i][j] == 1 {
					U[i][j] += U[i-1][j]
				}
			}
		}
	}
	for k := 1; k <= min(m, n); k++ {
		for i := k - 1; i < m; i++ {
			for j := k - 1; j < n; j++ {
				if L[i][j] >= k && U[i][j] >= k && L[i-k+1][j] >= k && U[i][j-k+1] >= k {
					res = max(res, k)
				}
			}
		}
	}
	return res * res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
