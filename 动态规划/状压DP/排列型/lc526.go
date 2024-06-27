package main

import "math/bits"

// https://leetcode.cn/problems/beautiful-arrangement/description/

func countArrangement(n int) int {
	f := make([]int, 1<<n)
	f[0] = 1
	for s := 0; s < 1<<n; s++ {
		i := bits.OnesCount(uint(s)) + 1
		for j := 0; j < n; j++ {
			if (s>>j)&1 == 0 && ((j+1)%i == 0 || i%(j+1) == 0) {
				f[s|(1<<j)] += f[s]
			}
		}
	}
	return f[(1<<n)-1]
}
