package main

import "strings"

// https://leetcode.cn/problems/minimum-deletions-to-make-string-balanced/

func minimumDeletions(s string) int {
	n := len(s)
	sum := make([]int, n+1)
	for i, ch := range s {
		sum[i+1] = sum[i] + int(('c'-ch)/2)
	}
	res := n
	for i := 0; i <= n; i++ {
		res = min(res, i-sum[i]+sum[n]-sum[i])
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _minimumDeletions(s string) int {
	del := strings.Count(s, "a")
	ans := del
	for _, c := range s {
		// 'a' -> -1    'b' -> 1
		del += int((c-'a')*2 - 1)
		if del < ans {
			ans = del
		}
	}
	return ans
}
