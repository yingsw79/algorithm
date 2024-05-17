package main

// https://leetcode.cn/problems/maximum-score-from-removing-stones/description/

func maximumScore(a int, b int, c int) int {
	s := a + b + c
	mx := max(a, b, c)
	if mx > s-mx+1 {
		return s - mx
	}
	return s / 2
}
