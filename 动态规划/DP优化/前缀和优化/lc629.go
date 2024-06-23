package main

// https://leetcode.cn/problems/k-inverse-pairs-array/
// https://leetcode.cn/problems/count-the-number-of-inversions/description/

func kInversePairs(n int, k int) int {
	const MOD int = 1e9 + 7
	f := make([]int, k+1)
	f[0] = 1
	for i := 1; i < n; i++ {
		for j := 1; j <= k; j++ {
			f[j] = (f[j] + f[j-1]) % MOD
		}
		for j := k; j > i; j-- {
			f[j] = (f[j] - f[j-i-1] + MOD) % MOD
		}
	}
	return f[k]
}
