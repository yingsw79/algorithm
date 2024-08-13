package main

import "slices"

// https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii/description/

func countOfPairs(nums []int) (res int) {
	const MOD int = 1e9 + 7
	n := len(nums)
	mx := slices.Max(nums)
	f := make([][]int, n)
	sum := make([]int, mx+1)
	for i := range f {
		f[i] = make([]int, mx+1)
	}
	for i := 0; i <= nums[0]; i++ {
		f[0][i] = 1
	}
	sum[0] = f[0][0]
	for i := 1; i <= mx; i++ {
		sum[i] = sum[i-1] + f[0][i]
	}
	for i := 1; i < n; i++ {
		for j := 0; j <= nums[i]; j++ {
			if x := min(j, nums[i-1]+j-nums[i]); x >= 0 {
				f[i][j] = sum[x]
			}
		}
		clear(sum)
		sum[0] = f[i][0]
		for j := 1; j <= mx; j++ {
			sum[j] = (sum[j-1] + f[i][j]) % MOD
		}
	}
	for i := 0; i <= nums[n-1]; i++ {
		res = (res + f[n-1][i]) % MOD
	}
	return
}

// func countOfPairs(nums []int) (res int) {
// 	const MOD int = 1e9 + 7
// 	n := len(nums)
// 	f := make([][55]int, n)
// 	for i := 0; i <= nums[0]; i++ {
// 		f[0][i] = 1
// 	}
// 	for i := 1; i < n; i++ {
// 		for j := 0; j <= nums[i]; j++ {
// 			for k := 0; k <= j; k++ { // 前缀和优化掉
// 				if nums[i-1]-k >= nums[i]-j {
// 					f[i][j] = (f[i][j] + f[i-1][k]) % MOD
// 				}
// 			}
// 		}
// 	}
// 	for i := 0; i <= nums[n-1]; i++ {
// 		res = (res + f[n-1][i]) % MOD
// 	}
// 	return
// }
