package main

import "math"

// https://leetcode.cn/problems/minimum-cost-to-convert-string-i/description/
// https://leetcode.cn/problems/minimum-cost-to-convert-string-ii/

func minimumCost(source string, target string, original []string, changed []string, cost []int) int64 {
	const INF int = math.MaxInt / 2
	m := 0
	index := map[string]int{}
	mp := map[int]map[string]bool{}
	stoi := func(strs []string) {
		for _, s := range strs {
			x := len(s)
			if mp[x] == nil {
				mp[x] = map[string]bool{}
			}
			mp[x][s] = true
			if _, ok := index[s]; !ok {
				index[s] = m
				m++
			}
		}
	}
	stoi(original)
	stoi(changed)
	d := make([][]int, m)
	for i := range d {
		d[i] = make([]int, m)
		for j := 0; j < m; j++ {
			if j != i {
				d[i][j] = INF
			}
		}
	}
	for i, v := range original {
		a, b := index[v], index[changed[i]]
		d[a][b] = min(d[a][b], cost[i])
	}
	for _, strs := range mp {
		for s1 := range strs {
			k := index[s1]
			for s2 := range strs {
				i := index[s2]
				if d[i][k] >= INF {
					continue
				}
				for s3 := range strs {
					j := index[s3]
					if d[i][j] > d[i][k]+d[k][j] {
						d[i][j] = d[i][k] + d[k][j]
					}
				}
			}
		}
	}
	n := len(source)
	f := make([]int, n+1)
	for i := range f {
		f[i] = INF
	}
	f[0] = 0
	for i := 1; i <= n; i++ {
		if source[i-1] == target[i-1] {
			f[i] = f[i-1]
		}
		for k, strs := range mp {
			if i < k {
				continue
			}
			s, t := source[i-k:i], target[i-k:i]
			if strs[s] && strs[t] {
				f[i] = min(f[i], f[i-k]+d[index[s]][index[t]])
			}
		}
	}
	if f[n] >= INF {
		return -1
	}
	return int64(f[n])
}
