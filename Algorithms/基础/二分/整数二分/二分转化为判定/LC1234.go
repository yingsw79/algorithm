package main

import "sort"

// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

func balancedString(s string) int {
	n := len(s)
	prefix := map[rune][]int{}
	for _, ch := range "QWER" {
		prefix[ch] = make([]int, n+1)
	}
	for i, ch := range s {
		for k, v := range prefix {
			if k == ch {
				v[i+1] = v[i] + 1
			} else {
				v[i+1] = v[i]
			}
		}
	}
	check := func(L int) bool {
		for i := 1; i+L-1 <= n; i++ {
			j, cnt := i+L-1, L
			ok := true
			for _, v := range prefix {
				t := v[n] - (v[j] - v[i-1])
				if t > n/4 {
					ok = false
					break
				} else if t+cnt >= n/4 {
					cnt -= n/4 - t
				} else {
					ok = false
					break
				}
			}
			if ok {
				return true
			}
		}
		return false
	}
	return sort.Search(n, check)
}
