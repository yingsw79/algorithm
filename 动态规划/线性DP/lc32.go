package main

// https://leetcode.cn/problems/longest-valid-parentheses/description/

func longestValidParentheses(s string) (res int) {
	n := len(s)
	f := make([]int, n+1)
	for i := 1; i < n; i++ {
		if s[i] == '(' {
			continue
		}
		if s[i-1] == '(' {
			f[i+1] = f[i-1] + 2
		} else if i > f[i] && s[i-f[i]-1] == '(' {
			f[i+1] = f[i] + f[i-f[i]-1] + 2
		}
		res = max(res, f[i+1])
	}
	return
}
