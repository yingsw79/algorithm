package main

import "sort"

// https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-ii/

func maximumLength(s string) int {
	n := len(s)
	cnt := make([]int, 26)
	return sort.Search(n, func(x int) bool {
		if x == 0 {
			return true
		}
		clear(cnt)
		for i := 0; i < n; i++ {
			j := i + 1
			for ; j < n && s[j] == s[i]; j++ {
			}
			t := s[i] - 'a'
			cnt[t] += max(j-i-x+1, 0)
			if cnt[t] >= 3 {
				return false
			}
			i = j - 1
		}
		return true
	}) - 1
}
