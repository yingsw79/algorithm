package main

import "math"

// https://leetcode.cn/problems/minimum-number-of-operations-to-satisfy-conditions/description/

// 1.
func minimumOperations(grid [][]int) int {
	n := len(grid[0])
	f := make([][10]int, n)
	g := make([][10]int, n)
	for i := 0; i < n; i++ {
		for j := 0; j < 10; j++ {
			f[i][j] = math.MaxInt
			for _, v := range grid {
				if v[i] != j {
					g[i][j]++
				}
			}
		}
	}
	f[0] = g[0]
	for i := 1; i < n; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				if k != j {
					f[i][j] = min(f[i][j], f[i-1][k]+g[i][j])
				}
			}
		}
	}
	res := math.MaxInt
	for i := 0; i < 10; i++ {
		res = min(res, f[n-1][i])
	}
	return res
}

// 2.
func _minimumOperations(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][10]int, n)
	cnt := make([][10]int, n)
	for _, row := range grid {
		for j, v := range row {
			cnt[j][v]++
		}
	}
	f[0] = cnt[0]
	for i := 1; i < n; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 10; k++ {
				if k != j {
					f[i][j] = max(f[i][j], f[i-1][k]+cnt[i][j])
				}
			}
		}
	}
	res := 0
	for i := 0; i < 10; i++ {
		res = max(res, f[n-1][i])
	}
	return m*n - res
}
