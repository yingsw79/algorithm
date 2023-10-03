package main

// https://leetcode.cn/problems/count-valid-paths-in-a-tree/description/

const N int = 1e5 + 1

var st = [N]bool{1: true}

func init() {
	for i := 2; i*i < N; i++ {
		if !st[i] {
			for j := i * i; j < N; j += i {
				st[j] = true
			}
		}
	}
}

func countPaths(n int, edges [][]int) (res int64) {
	g := make([][]int, n+1)
	p, sz := make([]int, n+1), make([]int, n+1)
	for i := range p {
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
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
		if st[a] && st[b] {
			a, b = find(p[a]), find(p[b])
			if a != b {
				p[a] = b
				sz[b] += sz[a]
			}
		}
	}
	for u := 1; u <= n; u++ {
		if st[u] {
			continue
		}
		sum := 1
		for _, v := range g[u] {
			if st[v] {
				t := sz[find(v)]
				res += int64(sum * t)
				sum += t
			}
		}
	}
	return
}
