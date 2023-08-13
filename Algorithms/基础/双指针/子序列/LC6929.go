package main

import "sort"

// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/

func maximumBeauty(nums []int, k int) (res int) {
	sort.Ints(nums)
	j := 0
	for i, v := range nums {
		for v-nums[j] > k*2 {
			j++
		}
		res = max(res, i-j+1)
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }
