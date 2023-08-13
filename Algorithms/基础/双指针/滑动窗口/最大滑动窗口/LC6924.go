package main

// https://leetcode.cn/problems/length-of-the-longest-valid-substring/

func longestValidSubstring(word string, forbidden []string) (res int) {
	mp := make(map[string]bool, len(forbidden))
	for _, v := range forbidden {
		mp[v] = true
	}
	j := 0
	for i := range word {
		for k := i; k >= max(i-10, j); k-- {
			if mp[word[k:i+1]] {
				j = k + 1
				break
			}
		}
		res = max(res, i-j+1)
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }