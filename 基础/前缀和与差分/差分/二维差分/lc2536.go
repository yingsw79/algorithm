package main

// https://leetcode.cn/problems/increment-submatrices-by-one/

func rangeAddQueries(n int, queries [][]int) [][]int {
	a := make([][]int, n+2)
	for i := range a {
		a[i] = make([]int, n+2)
	}
	for _, v := range queries {
		x1, y1, x2, y2 := v[0]+1, v[1]+1, v[2]+1, v[3]+1
		a[x1][y1] += 1
		a[x1][y2+1] -= 1
		a[x2+1][y1] -= 1
		a[x2+1][y2+1] += 1
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1]
		}
	}
	a = a[1 : n+1]
	for i, v := range a {
		a[i] = v[1 : n+1]
	}
	return a
}
