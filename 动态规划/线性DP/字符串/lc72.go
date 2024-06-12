package main

// https://leetcode.cn/problems/edit-distance/description/

func minDistance(word1 string, word2 string) int {
	n, m := len(word1), len(word2)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, m+1)
	}
	for i := 1; i <= n; i++ {
		f[i][0] = i
	}
	for i := 1; i <= m; i++ {
		f[0][i] = i
	}
	for i, x := range word1 {
		for j, y := range word2 {
			if x == y {
				f[i+1][j+1] = f[i][j]
			} else {
				f[i+1][j+1] = min(f[i][j+1], f[i][j], f[i+1][j]) + 1
			}
		}
	}
	return f[n][m]
}
