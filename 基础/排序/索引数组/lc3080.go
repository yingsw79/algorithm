package main

import "slices"

// https://leetcode.cn/problems/mark-elements-on-array-by-performing-queries/description/

func unmarkedSumArray(nums []int, queries [][]int) []int64 {
	n := len(nums)
	idx := make([]int, n)
	sum := int64(0)
	for i := range idx {
		idx[i] = i
		sum += int64(nums[i])
	}
	slices.SortStableFunc(idx, func(a, b int) int { return nums[a] - nums[b] })
	// sort.Slice(idx, func(i, j int) bool {
	// 	return nums[idx[i]] < nums[idx[j]] || (nums[idx[i]] == nums[idx[j]] && idx[i] < idx[j])
	// })
	st := make([]bool, n)
	res := make([]int64, len(queries))
	u := 0
	for i, q := range queries {
		j, k := q[0], q[1]
		if !st[j] {
			st[j] = true
			sum -= int64(nums[j])
		}
		for cnt := 0; u < n && cnt < k; u++ {
			v := idx[u]
			if !st[v] {
				cnt++
				st[v] = true
				sum -= int64(nums[v])
			}
		}
		res[i] = sum
	}
	return res
}
