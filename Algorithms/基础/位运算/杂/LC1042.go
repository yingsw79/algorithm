package main

import "math/bits"

// https://leetcode.cn/problems/flower-planting-with-no-adjacent/

func gardenNoAdj(n int, paths [][]int) []int {
	g := make([][]int, n)
	for _, e := range paths {
		x, y := e[0]-1, e[1]-1 // 编号改从 0 开始
		g[x] = append(g[x], y)
		g[y] = append(g[y], x) // 建图
	}
	color := make([]int, n)
	for i, nodes := range g {
		mask := uint8(1) // 由于颜色是 1~4，把 0 加入 mask 保证下面不会算出 0
		for _, j := range nodes {
			mask |= 1 << color[j]
		}
		color[i] = bits.TrailingZeros8(^mask)
	}
	return color
}
