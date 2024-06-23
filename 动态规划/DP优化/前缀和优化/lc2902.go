package main

// https://leetcode.cn/problems/count-of-sub-multisets-with-bounded-sum/description/
// https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/
// 前缀和优化

func countSubMultisets(nums []int, l int, r int) (res int) {
	const MOD int = 1e9 + 7
	f := make([]int, r+1)
	f[0] = 1
	mp := map[int]int{}
	for _, v := range nums {
		mp[v]++
	}
	for k, v := range mp {
		if k == 0 {
			continue
		}
		for i := k; i <= r; i++ {
			f[i] = (f[i] + f[i-k]) % MOD
		}
		for i, t := r, (v+1)*k; i >= t; i-- {
			f[i] = (f[i] - f[i-t] + MOD) % MOD
		}
	}
	for i := l; i <= r; i++ {
		res = (res + f[i]) % MOD
	}
	return res * (mp[0] + 1) % MOD
}
