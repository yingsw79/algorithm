package main

// https://leetcode.cn/problems/number-of-ways-to-earn-points/

func waysToReachTarget(target int, types [][]int) int {
	const MOD int = 1e9 + 7
	f := make([]int, target+1)
	f[0] = 1
	for _, v := range types {
		for j := target; j >= v[1]; j-- {
			for k := 1; k <= min(v[0], j/v[1]); k++ {
				f[j] = (f[j] + f[j-k*v[1]]) % MOD
			}
		}
	}
	return f[target]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
