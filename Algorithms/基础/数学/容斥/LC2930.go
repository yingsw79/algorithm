package main

// https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/

// A: 无l B:不超过一个e C:无t
const MOD int = 1e9 + 7

func stringCount(n int) int {
	return ((pow(26, n)-pow(25, n-1)*(n+75)+pow(24, n-1)*(n*2+72)-pow(23, n-1)*(n+23))%MOD + MOD) % MOD
}

func pow(a, b int) int {
	res := 1
	for ; b > 0; b >>= 1 {
		if b&1 > 0 {
			res = (res * a) % MOD
		}
		a = a * a % MOD
	}
	return res
}
