package main

// https://leetcode.cn/problems/split-array-into-maximum-number-of-subarrays/description/

func maxSubarrays(nums []int) (res int) {
	and := -1
	for _, v := range nums {
		and &= v
		if and == 0 {
			res++
			and = -1
		}
	}
	return max(res, 1)
}

func max(a, b int) int { if a > b { return a }; return b }
