package main

// https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences/description/

func sumOfPower(nums []int, k int) (res int) {
	const MOD int = 1e9 + 7
	n := len(nums)
	f := make([][]int, k+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := k; j >= nums[i-1]; j-- {
			for c := i; c >= 1; c-- {
				f[j][c] = (f[j][c] + f[j-nums[i-1]][c-1]) % MOD // 二维01背包
			}
		}
	}
	p := 1
	for i := n; i >= 1; i-- {
		res = (res + f[k][i]*p) % MOD
		p = p * 2 % MOD
	}
	return
}
