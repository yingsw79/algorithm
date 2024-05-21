package main

// https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

func countPalindromePaths(parent []int, s string) (res int64) {
	n := len(parent)
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		p := parent[i]
		g[p] = append(g[p], i)
	}
	cnt := map[int]int{0: 1}
	pre := 0
	var dfs func(int)
	dfs = func(u int) {
		for _, v := range g[u] {
			pre ^= 1 << (s[v] - 'a')
			res += int64(cnt[pre])
			for i := 0; i < 26; i++ {
				res += int64(cnt[pre^(1<<i)])
			}
			cnt[pre]++
			dfs(v)
			pre ^= 1 << (s[v] - 'a') // 回溯
		}
	}
	dfs(0)
	return
}
