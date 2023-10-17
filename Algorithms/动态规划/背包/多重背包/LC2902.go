package main

// https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum/description/

func countSubMultisets(nums []int, l int, r int) (res int) {
	const MOD int = 1e9 + 7
	f, g := make([]int, r+1), make([]int, r+1)
	f[0] = 1
	mp := map[int]int{}
	for _, v := range nums {
		mp[v]++
	}
	for k, v := range mp {
		if k == 0 {
			continue
		}
		for i := range g {
			g[i] = 0
		}
		for i := range g {
			g[i] = f[i]
			if i >= k {
				g[i] = (g[i] + g[i-k]) % MOD
			}
		}
		for i := range g {
			f[i] = g[i]
			if i >= (v+1)*k {
				f[i] = (f[i] - g[i-(v+1)*k] + MOD) % MOD
			}
		}
	}
	for i := l; i <= r; i++ {
		res = (res + f[i]) % MOD
	}
	return res * (mp[0] + 1) % MOD
}
