package main

import "sort"

// https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/
// https://leetcode.cn/problems/sum-of-distances/

func minOperations(nums []int, queries []int) []int64 {
	sort.Ints(nums)
	n := len(nums)
	sum := make([]int64, n+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + int64(v)
	}
	res := make([]int64, len(queries))
	for i, q := range queries {
		x := sort.SearchInts(nums, q)
		res[i] = sum[n] - sum[x]*2 + int64(q*(x*2-n))
	}
	return res
}
