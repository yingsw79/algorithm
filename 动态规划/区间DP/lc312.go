package main

import "slices"

// https://leetcode.cn/problems/burst-balloons/description/?envType=daily-question&envId=2024-06-09

func maxCoins(nums []int) int {
	nums = slices.Insert(append(nums, 1), 0, 1)
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for L := 3; L <= n; L++ {
		for i := 0; i+L-1 < n; i++ {
			j := i + L - 1
			for k := i + 1; k < j; k++ {
				f[i][j] = max(f[i][j], f[i][k]+f[k][j]+nums[i]*nums[k]*nums[j])
			}
		}
	}
	return f[0][n-1]
}
