package main

import "math"

// https://leetcode.cn/problems/find-subarray-with-bitwise-and-closest-to-k/description/
// https://leetcode.cn/problems/number-of-subarrays-with-and-value-of-k/description/

func minimumDifference(nums []int, k int) int {
	res := math.MaxInt
	for i, v := range nums {
		res = min(res, abs(v-k))
		for j := i - 1; j >= 0 && nums[j]&v < nums[j]; j-- {
			nums[j] &= v
			res = min(res, abs(nums[j]-k))
		}
	}
	return res
}

func abs(a int) int { if a < 0 { return -a }; return a }
