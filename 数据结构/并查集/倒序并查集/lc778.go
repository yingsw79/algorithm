package main

import "sort"

// https://leetcode.cn/problems/swim-in-rising-water/

type pair struct{ x, y int }
var dirs = []pair{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

func swimInWater(grid [][]int) int {
	n := len(grid)
	idx := []pair{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			idx = append(idx, pair{i, j})
		}
	}
	p := make([]int, n*n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	sort.Slice(idx, func(i, j int) bool {
		return grid[idx[i].x][idx[i].y] < grid[idx[j].x][idx[j].y]
	})
	for _, v := range idx {
		x, y := v.x, v.y
		t := find(x*n + y)
		for _, d := range dirs {
			a, b := x+d.x, y+d.y
			if a >= 0 && a < n && b >= 0 && b < n && grid[a][b] <= grid[x][y] {
				p[find(a*n+b)] = t
			}
			if find(0) == find(n*n-1) {
				return grid[x][y]
			}
		}
	}
	return -1
}
