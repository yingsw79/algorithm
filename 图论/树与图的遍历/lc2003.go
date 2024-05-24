package main

import "slices"

// https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree/description/?envType=daily-question&envId=2023-10-31

func smallestMissingValueSubtree(parents []int, nums []int) []int {
	n := len(nums)
	res := make([]int, n)
	for i := range res {
		res[i] = 1
	}
	idx := slices.Index(nums, 1)
	if idx < -1 {
		return res
	}
	g := make([][]int, n)
	for i, p := range parents[1:] {
		g[p] = append(g[p], i+1)
	}
	mp := make(map[int]bool, n)
	var dfs func(int)
	dfs = func(u int) {
		mp[nums[u]] = true
		for _, v := range g[u] {
			if !mp[nums[v]] {
				dfs(v)
			}
		}
	}
	for ms := 2; idx >= 0; idx = parents[idx] {
		dfs(idx)
		for mp[ms] {
			ms++
		}
		res[idx] = ms
	}
	return res
}
