package main

import "math"

// https://leetcode.cn/problems/maximize-total-cost-of-alternating-subarrays/description/

func maximumTotalCost(nums []int) int64 {
	n := len(nums)
	f := [2][2]int{}
	f[0][0] = nums[0]
	f[0][1] = math.MinInt
	for i := 1; i < n; i++ {
		j := i & 1
		f[j][0] = max(f[j^1][0], f[j^1][1]) + nums[i]
		f[j][1] = f[j^1][0] - nums[i]
	}
	return int64(max(f[(n-1)&1][0], f[(n-1)&1][1]))
}
