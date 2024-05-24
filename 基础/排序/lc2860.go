package main

import "sort"

// https://leetcode.cn/problems/happy-students/

func countWays(nums []int) (res int) {
	sort.Ints(nums)
	if nums[0] > 0 {
		res++
	}
	for i, x := range nums[:len(nums)-1] {
		if x < i+1 && i+1 < nums[i+1] {
			res++
		}
	}
	return res + 1
}
