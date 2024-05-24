package main

// https://leetcode.cn/problems/subsequence-with-the-minimum-score/

func minimumScore(s, t string) int {
	n, m := len(s), len(t)
	suf := make([]int, n+1)
	suf[n] = m
	for i, j := n-1, m-1; i >= 0; i-- {
		if j >= 0 && s[i] == t[j] {
			j--
		}
		suf[i] = j + 1
	}
	ans := suf[0] // 删除 t[:suf[0]]
	if ans == 0 {
		return 0
	}
	for i, j := 0, 0; i < n; i++ {
		if s[i] == t[j] { // 注意 j 不会等于 m，因为上面 suf[0]>0 表示 t 不是 s 的子序列
			j++
			ans = min(ans, suf[i+1]-j) // 删除 t[j:suf[i+1]]
		}
	}
	return ans
}

func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}
