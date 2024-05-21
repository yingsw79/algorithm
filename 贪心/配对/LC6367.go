package main

import "sort"

// https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/

func maxNumOfMarkedIndices(nums []int) (res int) {
	n := len(nums)
	sort.Ints(nums)
	for i, j := 0, n/2; i < n/2; i++ {
		for j < n && nums[j] < nums[i]*2 {
			j++
		}
		if j >= n {
			break
		}
		res += 2
		j++
	}
	return
}
