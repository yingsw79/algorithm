package main

import (
	"math"
	"math/bits"
)

// https://leetcode.cn/problems/maximum-students-taking-exam/description/?envType=daily-question&envId=2023-12-26

func maxStudents(seats [][]byte) (res int) {
	m, n := len(seats), len(seats[0])
	g := make([]int, m)
	for i, seat := range seats {
		for j, v := range seat {
			if v == '#' {
				g[i] |= 1 << j
			}
		}
	}
	check := func(st int) bool {
		return st&(st<<1) == 0
	}
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, 1<<n)
	}
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			f[i][j] = math.MinInt
			if (g[i-1]&j == 0) && check(j) {
				for k := 0; k < 1<<n; k++ {
					if check(j | k) {
						f[i][j] = max(f[i][j], f[i-1][k]+bits.OnesCount(uint(j)))
					}
				}
			}
		}
	}
	for i := 0; i < 1<<n; i++ {
		res = max(res, f[m][i])
	}
	return
}
