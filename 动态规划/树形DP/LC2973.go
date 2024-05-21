package main

import "slices"

// https://leetcode.cn/problems/find-number-of-coins-to-place-in-tree-nodes/description/

func placedCoins(edges [][]int, cost []int) []int64 {
	g := make([][]int, len(cost))
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	res := make([]int64, len(cost))
	var dfs func(int, int) []int
	dfs = func(u, fa int) []int {
		costs := []int{cost[u]}
		for _, v := range g[u] {
			if v != fa {
				costs = append(costs, dfs(v, u)...)
			}
		}
		slices.Sort(costs)
		n := len(costs)
		if n < 3 {
			res[u] = 1
		} else {
			res[u] = int64(max(costs[n-1]*costs[n-2]*costs[n-3], costs[0]*costs[1]*costs[n-1], 0))
		}
		if n > 5 {
			costs = append(costs[:2], costs[n-3:]...)
		}
		return costs
	}
	dfs(0, -1)
	return res
}
