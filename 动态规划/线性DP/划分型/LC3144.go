package main

import "math"

// https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequency/description/

func minimumSubstringsInPartition(s string) int {
	n := len(s)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = math.MaxInt
		cnt := [26]int{}
		var k, mx int
		for j := i - 1; j >= 0; j-- {
			c := s[j] - 'a'
			if cnt[c] == 0 {
				k++
			}
			cnt[c]++
			mx = max(mx, cnt[c])
			if i-j == k*mx {
				f[i] = min(f[i], f[j]+1)
			}
		}
	}
	return f[n]
}
