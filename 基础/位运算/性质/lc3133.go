package main

// https://leetcode.cn/problems/minimum-array-end/description/?envType=daily-question&envId=2024-08-22

func minEnd(n int, x int) int64 {
	n--
	for i, j := 0, 0; n>>j > 0; i++ {
		if (x>>i)&1 == 0 {
			x |= ((n >> j) & 1) << i
			j++
		}
	}
	return int64(x)
}
