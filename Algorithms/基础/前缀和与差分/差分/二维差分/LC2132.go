package main

// https://leetcode.cn/problems/stamping-the-grid/description/?envType=daily-question&envId=2023-12-14

func possibleToStamp(grid [][]int, stampHeight int, stampWidth int) bool {
	m, n := len(grid), len(grid[0])
	sum := make([][]int, m+1)
	for i := range sum {
		sum[i] = make([]int, n+1)
	}
	for i, g := range grid {
		for j, v := range g {
			sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + v
		}
	}
	d := make([][]int, m+2)
	for i := range d {
		d[i] = make([]int, n+2)
	}
	for i := stampHeight; i <= m; i++ {
		for j := stampWidth; j <= n; j++ {
			a, b := i-stampHeight+1, j-stampWidth+1
			if sum[i][j]-sum[a-1][j]-sum[i][b-1]+sum[a-1][b-1] == 0 {
				d[a][b]++
				d[a][j+1]--
				d[i+1][b]--
				d[i+1][j+1]++
			}
		}
	}
	for i, g := range grid {
		for j, v := range g {
			d[i+1][j+1] += d[i+1][j] + d[i][j+1] - d[i][j]
			if v == 0 && d[i+1][j+1] == 0 {
				return false
			}
		}
	}
	return true
}
