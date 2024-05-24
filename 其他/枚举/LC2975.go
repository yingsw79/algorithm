package main

import "slices"

// https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/

func maximizeSquareArea(m, n int, hFences, vFences []int) int {
	const MOD int = 1e9 + 7
	fn := func(nums []int, n int) (set map[int]bool) {
		nums = append(nums, 1, n)
		slices.Sort(nums)
		set = map[int]bool{}
		for i, x := range nums {
			for _, y := range nums[:i] {
				set[x-y] = true
			}
		}
		return
	}
	hset := fn(hFences, m)
	vset := fn(vFences, n)
	res := 0
	for k := range hset {
		if vset[k] {
			res = max(res, k)
		}
	}
	if res == 0 {
		return -1
	}
	return res * res % MOD
}
