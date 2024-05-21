package main

// https://leetcode.cn/problems/count-the-number-of-good-partitions/description/

func numberOfGoodPartitions(nums []int) int {
	mp := map[int]int{}
	for i, v := range nums {
		mp[v] = i
	}
	var cnt, r int
	for i, v := range nums {
		r = max(r, mp[v])
		if r == i {
			cnt++
		}
	}
	return pow(2, cnt-1, 1e9+7)
}

func pow(a, b, p int) int {
	res := 1
	for ; b > 0; b >>= 1 {
		if b&1 > 0 {
			res = (res * a) % p
		}
		a = a * a % p
	}
	return res
}
