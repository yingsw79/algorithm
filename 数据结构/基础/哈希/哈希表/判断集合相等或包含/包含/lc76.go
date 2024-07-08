package main

// https://leetcode.cn/problems/minimum-window-substring/description/

func minWindow(s string, t string) (res string) {
	cnt := [128]int{}
	for i := range t {
		cnt[t[i]]++
	}
	var sum, j int
	for i := range s {
		if cnt[s[i]]--; cnt[s[i]] >= 0 {
			sum++
		}
		for sum == len(t) {
			if len(res) == 0 || i-j+1 < len(res) {
				res = s[j : i+1]
			}
			c := s[j]
			if cnt[c]++; cnt[c] > 0 {
				sum--
			}
			j++
		}
	}
	return
}
