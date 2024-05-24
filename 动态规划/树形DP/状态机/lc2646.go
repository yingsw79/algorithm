package main

// https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/description/?envType=daily-question&envId=2023-12-06

func minimumTotalPrice(n int, edges [][]int, price []int, trips [][]int) int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	cnt := make([]int, n)
	var dfs1 func(int, int, int) bool
	dfs1 = func(u, fa, target int) bool {
		if u == target {
			cnt[u]++
			return true
		}
		for _, v := range g[u] {
			if v != fa && dfs1(v, u, target) {
				cnt[u]++
				return true
			}
		}
		return false
	}
	for _, v := range trips {
		dfs1(v[0], -1, v[1])
	}
	var dfs2 func(int, int) (int, int)
	dfs2 = func(u, fa int) (int, int) {
		a := cnt[u] * price[u]
		b := a / 2
		for _, v := range g[u] {
			if v != fa {
				c, d := dfs2(v, u)
				a += min(c, d)
				b += c
			}
		}
		return a, b
	}
	return min(dfs2(0, -1))
}
