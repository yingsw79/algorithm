package main

import "strings"

// https://leetcode.cn/problems/shortest-common-supersequence/

func shortestCommonSupersequence(str1 string, str2 string) string {
	m, n := len(str1), len(str2)
	f := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		f[i] = make([]int, n+1)
		f[i][n] = m - i
	}
	for i := 0; i <= n; i++ {
		f[m][i] = n - i
	}
	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if str1[i] == str2[j] {
				f[i][j] = f[i+1][j+1] + 1
			} else {
				f[i][j] = min(f[i+1][j], f[i][j+1]) + 1
			}
		}
	}
	b := strings.Builder{}
	i, j := 0, 0
	for i < m && j < n {
		if str1[i] == str2[j] {
			b.WriteByte(str1[i])
			i++
			j++
		} else if f[i][j] == f[i+1][j]+1 {
			b.WriteByte(str1[i])
			i++
		} else {
			b.WriteByte(str2[j])
			j++
		}
	}
	if i < m {
		b.WriteString(str1[i:])
	}
	if j < n {
		b.WriteString(str2[j:])
	}
	return b.String()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
