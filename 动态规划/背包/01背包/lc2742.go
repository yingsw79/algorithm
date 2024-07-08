package main

import "math"

// https://leetcode.cn/problems/painting-the-walls/description/?envType=daily-question&envId=2024-06-28

func paintWalls(cost []int, time []int) int {
	n := len(cost)
	f := make([]int, n+1)
	for i := range f {
		f[i] = math.MaxInt32
	}
	f[0] = 0
	for i, v := range time {
		for j := n; j > 0; j-- {
			f[j] = min(f[j], f[max(j-v-1, 0)]+cost[i])
		}
	}
	return f[n]
}
