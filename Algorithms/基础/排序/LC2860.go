package main

import "sort"

// https://leetcode.cn/problems/happy-students/

func countWays(nums []int) (ans int) {
	sort.Ints(nums)
	if nums[0] > 0 {
		ans++
	}
	for i, x := range nums[:len(nums)-1] {
		if x < i+1 && i+1 < nums[i+1] {
			ans++
		}
	}
	return ans + 1
}
