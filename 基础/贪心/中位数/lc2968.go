package main

import "sort"

// https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score/description/
// https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/

func maxFrequencyScore(nums []int, k int64) (res int) {
	sort.Ints(nums)
	sum := make([]int, len(nums)+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}
	calc := func(l, r int) int64 {
		mid := (l + r) >> 1
		return int64(nums[mid]*(mid-l) - (sum[mid] - sum[l]) + sum[r+1] - sum[mid+1] - nums[mid]*(r-mid))
	}
	j := 0
	for i := range nums {
		for calc(j, i) > k {
			j++
		}
		res = max(res, i-j+1)
	}
	return
}
