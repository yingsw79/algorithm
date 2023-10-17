package main

// https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

func getWordsInLongestSubsequence(n int, words []string, groups []int) (res []string) {
	f := make([]int, n)
	pre := make([]int, n)
	check := func(s1, s2 string) bool {
		if len(s1) != len(s2) {
			return false
		}
		cnt := 0
		for i, v := range s1 {
			if byte(v) != s2[i] {
				cnt++
			}
		}
		return cnt == 1
	}
	k := 0
	for i, v := range groups {
		f[i] = 1
		for j := 0; j < i; j++ {
			if v != groups[j] && check(words[i], words[j]) && f[j]+1 > f[i] {
				f[i] = f[j] + 1
				pre[i] = j
			}
		}
		if f[i] > f[k] {
			k = i
		}
	}
	res = make([]string, f[k])
	for i := f[k] - 1; i >= 0; i, k = i-1, pre[k] {
		res[i] = words[k]
	}
	return
}
