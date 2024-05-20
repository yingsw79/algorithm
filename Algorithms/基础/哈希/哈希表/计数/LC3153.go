package main

import "strconv"

// https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/description/

func sumDigitDifferences(nums []int) int64 {
	n := len(strconv.Itoa(nums[0]))
	cnt := make([][10]int, n)
	res := 0
	for i, v := range nums {
		s := strconv.Itoa(v)
		for j := 0; j < n; j++ {
			res += i - cnt[j][s[j]-'0']
		}
		for j := 0; j < n; j++ {
			cnt[j][s[j]-'0']++
		}
	}
	return int64(res)
}
