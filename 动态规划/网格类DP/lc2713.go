package main

import "slices"

// https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/description/?envType=daily-question&envId=2024-06-19

func maxIncreasingCells(mat [][]int) int {
	type pair struct{ i, j int }
	mp := map[int][]pair{}
	for i, row := range mat {
		for j, v := range row {
			mp[v] = append(mp[v], pair{i, j})
		}
	}
	keys := make([]int, 0, len(mp))
	for k := range mp {
		keys = append(keys, k)
	}
	slices.Sort(keys)
	r := make([]int, len(mat))
	c := make([]int, len(mat[0]))
	for _, k := range keys {
		pos := mp[k]
		mx := make([]int, len(pos))
		for i, p := range pos {
			mx[i] = max(r[p.i], c[p.j]) + 1
		}
		for i, p := range pos {
			r[p.i] = max(r[p.i], mx[i])
			c[p.j] = max(c[p.j], mx[i])
		}
	}
	return slices.Max(r)
}
