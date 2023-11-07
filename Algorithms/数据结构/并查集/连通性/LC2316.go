package main

// https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/?envType=daily-question&envId=2023-10-21

func countPairs(n int, edges [][]int) int64 {
	p, sz := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		sz[i] = 1
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, e := range edges {
		if a, b := find(e[0]), find(e[1]); a != b {
			p[a] = b
			sz[b] += sz[a]
		}
	}
	res := 0
	for i := 0; i < n; i++ {
		if p[i] == i {
			res += (n - sz[i]) * sz[i]
		}
	}
	return int64(res / 2)
}
