package main

import (
	"math"
)

// https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/description/?envType=daily-question&envId=2024-01-26

func minOperationsQueries(n int, edges [][]int, queries [][]int) []int {
	type pair struct{ x, y int }
	g := make([][]pair, n+1)
	for _, e := range edges {
		a, b, w := e[0]+1, e[1]+1, e[2]
		g[a] = append(g[a], pair{b, w})
		g[b] = append(g[b], pair{a, w})
	}
	t := int(math.Log2(float64(n))) + 1
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, t+1)
	}
	depth := make([]int, n+1)
	sum := make([][27]int, n+1)

	var dfs func(int, int)
	dfs = func(u, fa int) {
		depth[u] = depth[fa] + 1
		f[u][0] = fa
		for i := 1; i <= t; i++ {
			f[u][i] = f[f[u][i-1]][i-1]
		}
		for _, p := range g[u] {
			if v := p.x; v != fa {
				sum[v] = sum[u]
				sum[v][p.y]++
				dfs(v, u)
			}
		}
	}
	dfs(1, 0)

	lca := func(a, b int) int {
		if depth[a] < depth[b] {
			a, b = b, a
		}
		for i := t; i >= 0; i-- {
			if depth[f[a][i]] >= depth[b] {
				a = f[a][i]
			}
		}
		if a == b {
			return a
		}
		for i := t; i >= 0; i-- {
			if f[a][i] != f[b][i] {
				a, b = f[a][i], f[b][i]
			}
		}
		return f[a][0]
	}

	res := make([]int, len(queries))
	for i, q := range queries {
		a, b := q[0]+1, q[1]+1
		mx, s := 0, 0
		for j := 1; j <= 26; j++ {
			x := sum[a][j] + sum[b][j] - sum[lca(a, b)][j]*2
			s += x
			mx = max(mx, x)
		}
		res[i] = s - mx
	}
	return res
}
