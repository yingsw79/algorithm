package main

import (
	"slices"
	"sort"
)

// https://leetcode.cn/problems/make-lexicographically-smallest-array-by-swapping-elements/

func lexicographicallySmallestArray(nums []int, limit int) []int {
	n := len(nums)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return nums[idx[i]] < nums[idx[j]] })
	res := make([]int, n)
	for i := 0; i < n; {
		st := i
		for i++; i < n && nums[idx[i]]-nums[idx[i-1]] <= limit; i++ {
		}
		tmp := slices.Clone(idx[st:i])
		sort.Ints(tmp)
		for j, i := range tmp {
			res[i] = nums[idx[st+j]]
		}
	}
	return res
}
