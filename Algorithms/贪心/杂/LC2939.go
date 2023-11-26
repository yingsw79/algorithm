package main

// https://leetcode.cn/problems/maximum-xor-product/

func maximumXorProduct(a int64, b int64, n int) int {
	const MOD int64 = 1e9 + 7
	mask := ^((int64(1) << n) - 1)
	c, d := a&mask, b&mask
	for i := n - 1; i >= 0; i-- {
		if x, y := (a>>i)&1, (b>>i)&1; x == y {
			c |= int64(1) << i
			d |= int64(1) << i
		} else if c < d {
			c |= int64(1) << i
		} else {
			d |= int64(1) << i
		}
	}
	return int((c % MOD * (d % MOD)) % MOD)
}
