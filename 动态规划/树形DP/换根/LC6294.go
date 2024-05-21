package main

// https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum/

func maxOutput(n int, edges [][]int, price []int) (res int64) {
	g := make([][]int, n)
	for _, v := range edges {
		a, b := v[0], v[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	d1, d2, up := make([]int64, n), make([]int64, n), make([]int64, n)
	var dfs_d, dfs_u func(int, int)

	dfs_d = func(u, fa int) {
		d1[u] = int64(price[u])
		for _, v := range g[u] {
			if v == fa {
				continue
			}
			dfs_d(v, u)
			d := d1[v] + int64(price[u])
			if d > d1[u] {
				d2[u], d1[u] = d1[u], d
			} else if d > d2[u] {
				d2[u] = d
			}
		}
	}

	dfs_u = func(u, fa int) {
		for _, v := range g[u] {
			if v == fa {
				continue
			}
			if d1[v]+int64(price[u]) == d1[u] {
				up[v] = max(up[u], d2[u]) + int64(price[v])
			} else {
				up[v] = max(up[u], d1[u]) + int64(price[v])
			}
			dfs_u(v, u)
		}
	}
	
	dfs_d(0, -1)
	dfs_u(0, -1)

	for i := 0; i < n; i++ {
		res = max(res, max(d1[i], up[i])-int64(price[i]))
	}
	return
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
