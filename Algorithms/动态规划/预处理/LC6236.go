package main

// https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/submissions/

func maxPalindromes(s string, k int) int {
	n := len(s)
	g := make([][]bool, n+1)
	for i := range g {
		g[i] = make([]bool, n+1)
	}
	for L := 1; L <= n; L++ { // 区间DP预处理
		for i := 1; i+L-1 <= n; i++ {
			j := i + L - 1
			if s[i-1] == s[j-1] && (L <= 2 || g[i+1][j-1]) {
				g[i][j] = true
			}
		}
	}
	f := make([]int, n+1)
	for i := k; i <= n; i++ {
		f[i] = f[i-1]
		for j := i - k + 1; j >= 1; j-- {
			if g[j][i] {
				f[i] = max(f[i], f[j-1]+1)
				break
			}
		}
	}
	return f[n]
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
