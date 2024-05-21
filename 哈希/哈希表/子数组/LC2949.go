package main

import "strings"

// https://leetcode.cn/problems/count-beautiful-substrings-ii/description/

func beautifulSubstrings(s string, k int) (res int64) {
	for i := 1; ; i++ {
		if i*i%(k*4) == 0 {
			k = i
			break
		}
	}
	type pair struct{ x, y int }
	mp := map[pair]int{{0, k - 1}: 1} // sum[−1]=0
	sum := 0
	for i, v := range s {
		if strings.Contains("aeiou", string(v)) {
			sum++
		} else {
			sum--
		}
		t := pair{sum, i % k}
		res += int64(mp[t])
		mp[t]++
	}
	return
}
