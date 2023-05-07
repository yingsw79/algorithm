package main

import "sort"

// https://leetcode.cn/problems/longest-string-chain/

func longestStrChain(words []string) (ans int) {
	sort.Slice(words, func(i, j int) bool { return len(words[i]) < len(words[j]) })
	f := map[string]int{}
	for _, s := range words {
		res := 0
		for i := range s { // 枚举去掉 s[i]
			res = max(res, f[s[:i]+s[i+1:]])
		}
		f[s] = res + 1
		ans = max(ans, res+1)
	}
	return
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
