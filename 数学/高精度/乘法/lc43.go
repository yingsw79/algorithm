package main

import "strings"

// https://leetcode.cn/problems/multiply-strings/

func multiply(num1 string, num2 string) string {
	m, n := len(num1), len(num2)
	s := make([]int, m+n)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			s[i+j] += int(num1[m-1-i]-'0') * int(num2[n-1-j]-'0')
			if s[i+j] >= 10 {
				s[i+j+1] += s[i+j] / 10
				s[i+j] %= 10
			}
		}
	}
	i := len(s) - 1
	for ; i > 0 && s[i] == 0; i-- {
	}
	b := strings.Builder{}
	for ; i >= 0; i-- {
		b.WriteByte(byte(s[i]) + '0')
	}
	return b.String()
}
