package main

// https://leetcode.cn/problems/longest-arithmetic-subsequence/

func longestArithSeqLength(a []int) (ans int) {
	n := len(a)
	f := make([]map[int]int, n)
	f[0] = map[int]int{}
	for i := 1; i < n; i++ {
		f[i] = map[int]int{}
		for j := i - 1; j >= 0; j-- {
			d := a[i] - a[j] // 公差
			if f[i][d] == 0 {
				f[i][d] = f[j][d] + 1 // 默认的 1 在下面返回时加上
				ans = max(ans, f[i][d])
			}
		}
	}
	return ans + 1
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
