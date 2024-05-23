package main

import "slices"

// https://leetcode.cn/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/

func minOperationsToMakeMedianK(nums []int, k int) (res int64) {
	slices.Sort(nums)
	x := len(nums) / 2
	if nums[x] > k {
		for _, v := range nums[:x+1] {
			if v > k {
				res += int64(v - k)
			}
		}
	} else {
		for _, v := range nums[x:] {
			if v < k {
				res += int64(k - v)
			}
		}
	}
	return
}
