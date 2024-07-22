package main

import "slices"

// https://leetcode.cn/problems/combination-sum/description/

func combinationSum(candidates []int, target int) (res [][]int) {
	n := len(candidates)
	f := make([][]bool, n+1)
	for i := range f {
		f[i] = make([]bool, target+1)
	}
	f[0][0] = true
	for i, v := range candidates {
		for j := 0; j <= target; j++ {
			f[i+1][j] = f[i][j] || j >= v && f[i+1][j-v]
		}
	}
	tmp := []int{}
	var dfs func(int, int)
	dfs = func(i, t int) {
		if t == 0 {
			res = append(res, slices.Clone(tmp))
			return
		}
		if t < 0 || !f[i+1][t] {
			return
		}
		dfs(i-1, t)
		tmp = append(tmp, candidates[i])
		dfs(i, t-candidates[i])
		tmp = tmp[:len(tmp)-1]
	}
	dfs(n-1, target)
	return res
}
