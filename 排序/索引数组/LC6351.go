package main

import "sort"

// https://leetcode.cn/problems/find-score-of-an-array-after-marking-all-elements/

func findScore(nums []int) (res int64) {
	idx := make([]int, len(nums))
	for i := range idx {
		idx[i] = i
	}
	sort.SliceStable(idx, func(i, j int) bool { return nums[idx[i]] < nums[idx[j]] })
	for _, i := range idx {
		if nums[i] == -1 {
			continue
		}
		res += int64(nums[i])
		nums[i] = -1
		if i > 0 {
			nums[i-1] = -1
		}
		if i < len(nums)-1 {
			nums[i+1] = -1
		}
	}
	return
}
