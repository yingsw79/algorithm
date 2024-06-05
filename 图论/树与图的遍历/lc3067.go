package main

// https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/?envType=daily-question&envId=2024-06-04

func countPairsOfConnectableServers(edges [][]int, signalSpeed int) []int {
	type pair struct{ v, w int }
	n := len(edges) + 1
	g := make([][]pair, n)
	for _, e := range edges {
		a, b, w := e[0], e[1], e[2]
		g[a] = append(g[a], pair{b, w})
		g[b] = append(g[b], pair{a, w})
	}
	res := make([]int, n)
	for i, ps := range g {
		cnt := 0
		var dfs func(int, int, int)
		dfs = func(u, fa, d int) {
			if d%signalSpeed == 0 {
				cnt++
			}
			for _, p := range g[u] {
				if p.v != fa {
					dfs(p.v, u, d+p.w)
				}
			}
		}
		sum := 0
		for _, p := range ps {
			cnt = 0
			dfs(p.v, i, p.w)
			res[i] += sum * cnt
			sum += cnt
		}
	}
	return res
}
