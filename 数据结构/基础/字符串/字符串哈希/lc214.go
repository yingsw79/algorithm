package main

import "strings"

// https://leetcode.cn/problems/shortest-palindrome/description/

func shortestPalindrome(s string) string {
	const B = 131
	n := len(s)
	var h1, h2, p uint64
	p = 1
	pos := 0
	for i := 0; i < n; i++ {
		v := uint64(s[i])
		h1 = h1*B + v
		h2 += v * p
		p *= B
		if h1 == h2 {
			pos = i
		}
	}
	sb := strings.Builder{}
	for i := n - 1; i > pos; i-- {
		sb.WriteByte(s[i])
	}
	sb.WriteString(s)
	return sb.String()
}
