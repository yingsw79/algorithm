package main

import "sort"

// https://leetcode.cn/problems/sorting-three-groups/description/
// https://leetcode.cn/problems/longest-increasing-subsequence/

func minimumOperations(nums []int) int {
	g := []int{}
	for _, x := range nums {
		p := sort.SearchInts(g, x+1) // 非递减
		if p < len(g) {
			g[p] = x
		} else {
			g = append(g, x)
		}
	}
	return len(nums) - len(g)
}
