package main

// https://leetcode.cn/problems/construct-product-matrix/

func constructProductMatrix(grid [][]int) [][]int {
	const MOD int = 12345
	m, n := len(grid), len(grid[0])
	p := make([][]int, m)
	t := 1
	for i := m - 1; i >= 0; i-- {
		p[i] = make([]int, n)
		for j := n - 1; j >= 0; j-- {
			p[i][j] = t
			t = grid[i][j] * t % MOD
		}
	}
	t = 1
	for i, g := range grid {
		for j, v := range g {
			p[i][j] = p[i][j] * t % MOD
			t = v * t % MOD
		}
	}
	return p
}
