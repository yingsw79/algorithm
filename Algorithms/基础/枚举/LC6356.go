package main

import "strconv"

// https://leetcode.cn/problems/substring-xor-queries/

func substringXorQueries(s string, queries [][]int) [][]int {
	mp := map[int][]int{}
	for L := 1; L < 31; L++ {
		for i := 0; i+L <= len(s); i++ {
			k, _ := strconv.ParseInt(s[i:i+L], 2, 32)
			if _, ok := mp[int(k)]; !ok {
				mp[int(k)] = append(mp[int(k)], i, i+L-1)
			}
		}
	}
	for i, q := range queries {
		if v, ok := mp[q[0]^q[1]]; ok {
			queries[i] = v
		} else {
			queries[i] = []int{-1, -1}
		}
	}
	return queries
}
