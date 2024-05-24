package main

import "sort"

// https://leetcode.cn/problems/movement-of-robots/?envType=daily-question&envId=2023-10-10

func sumDistance(nums []int, s string, d int) (res int) {
	const MOD int = 1e9 + 7
	for i, v := range s {
		if v == 'L' {
			nums[i] -= d
		} else {
			nums[i] += d
		}
	}
	sort.Ints(nums)
	sum := 0
	for i, v := range nums {
		res = (res + v*i - sum) % MOD
		sum = (sum + v) % MOD
	}
	return
}
