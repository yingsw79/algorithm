package main

// https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree/

func maximumScoreAfterOperations(edges [][]int, values []int) int64 {
	g := make([][]int, len(values))
	g[0] = append(g[0], -1)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) (int, int)
	dfs = func(u, fa int) (int, int) {
		var c, d int
		for _, v := range g[u] {
			if v != fa {
				a, b := dfs(v, u)
				c += a
				d += b
			}
		}
		if len(g[u]) > 1 {
			c += values[u]
		}
		return max(c, d), d + values[u]
	}
	res, _ := dfs(0, -1)
	return int64(res)
}

func max(a, b int) int { if a > b { return a }; return b }