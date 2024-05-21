package main

// https://leetcode.cn/problems/maximum-earnings-from-taxi/description/?envType=daily-question&envId=2023-12-08
// https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/
// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-05-04

func maxTaxiEarnings(n int, rides [][]int) int64 {
	type pair struct{ x, y int }
	g := make([][]pair, n+1)
	for _, v := range rides {
		g[v[1]] = append(g[v[1]], pair{v[0], v[1] - v[0] + v[2]})
	}
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = f[i-1]
		for _, p := range g[i] {
			f[i] = max(f[i], f[p.x]+p.y)
		}
	}
	return int64(f[n])
}
