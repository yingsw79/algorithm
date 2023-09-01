package main

import "sort"

// https://leetcode.cn/problems/longest-increasing-subsequence/
// https://leetcode.cn/problems/sorting-three-groups/description/

func lengthOfLIS(nums []int) int {
	a := []int{}
	for _, v := range nums {
		x := sort.SearchInts(a, v) // 递增
		if x < len(a) {
			a[x] = v
		} else {
			a = append(a, v)
		}
	}
	return len(a)
}
