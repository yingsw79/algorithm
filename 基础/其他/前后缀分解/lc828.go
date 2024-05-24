package main

// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/?envType=daily-question&envId=2023-11-26

func uniqueLetterString(s string) (res int) {
	n := len(s)
	pre := make([]int, n)
	pos := [26]int{}
	for i := range pos {
		pos[i] = -1
	}
	for i, v := range s {
		v -= 'A'
		pre[i] = pos[v]
		pos[v] = i
	}
	for i := range pos {
		pos[i] = n
	}
	for i := n - 1; i >= 0; i-- {
		c := s[i] - 'A'
		res += (i - pre[i]) * (pos[c] - i)
		pos[c] = i
	}
	return
}
