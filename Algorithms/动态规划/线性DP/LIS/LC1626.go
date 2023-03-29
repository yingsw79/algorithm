package main

import "sort"

// https://leetcode.cn/problems/best-team-with-no-conflicts/
// https://leetcode.cn/problems/russian-doll-envelopes/
// https://leetcode.cn/problems/longest-increasing-subsequence/
// https://leetcode.cn/problems/longest-increasing-subsequence-ii/
// https://leetcode.cn/problems/maximum-height-by-stacking-cuboids/
// 二维LIS
// 二分 或 树状数组优化(前缀最大值)

func bestTeamScore(scores []int, ages []int) (res int) {
	idx := make([]int, len(scores))
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		return ages[idx[i]] < ages[idx[j]] || ages[idx[i]] == ages[idx[j]] && scores[idx[i]] < scores[idx[j]]
	})
	f := make([]int, len(scores))
	for i, v := range idx {
		for j := 0; j < i; j++ {
			if scores[v] >= scores[idx[j]] {
				f[i] = max(f[i], f[j])
			}
		}
		f[i] += scores[v]
		res = max(res, f[i])
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
