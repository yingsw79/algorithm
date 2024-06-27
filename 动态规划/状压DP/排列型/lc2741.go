package main

// https://leetcode.cn/problems/special-permutations/description/?envType=daily-question&envId=2024-06-26

func specialPerm(nums []int) (res int) {
	const MOD int = 1e9 + 7
	n := len(nums)
	f := make([][]int, 1<<n)
	for i := range f {
		f[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		f[1<<i][i] = 1
	}
	for s := 0; s < 1<<n; s++ {
		for j := 0; j < n; j++ {
			if (s>>j)&1 > 0 {
				continue
			}
			for k := 0; k < n; k++ {
				if (s>>k)&1 > 0 && (nums[j]%nums[k] == 0 || nums[k]%nums[j] == 0) {
					f[s|(1<<j)][j] = (f[s|(1<<j)][j] + f[s][k]) % MOD
				}
			}
		}
	}
	for i := 0; i < n; i++ {
		res = (res + f[(1<<n)-1][i]) % MOD
	}
	return
}
