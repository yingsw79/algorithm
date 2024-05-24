package main

// https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

func minEdgeReversals(n int, edges [][]int) []int {
	type pair struct{ x, y int }
	res := make([]int, n)
	g := make([][]pair, n)
	for _, v := range edges {
		a, b := v[0], v[1]
		g[a] = append(g[a], pair{b, 1})
		g[b] = append(g[b], pair{a, -1})
	}
	var dfs1 func(int, int)
	dfs1 = func(u, fa int) {
		for _, p := range g[u] {
			v := p.x
			if v != fa {
				if p.y < 0 {
					res[0]++
				}
				dfs1(v, u)
			}
		}
	}
	dfs1(0, -1)

	var dfs2 func(int, int)
	dfs2 = func(u, fa int) {
		for _, p := range g[u] {
			v := p.x
			if v != fa {
				res[v] = res[u] + p.y
				dfs2(v, u)
			}
		}
	}
	dfs2(0, -1)
	return res
}
