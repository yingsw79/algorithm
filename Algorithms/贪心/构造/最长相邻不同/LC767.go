package main

import "slices"

// https://leetcode.cn/problems/reorganize-string/description/

func reorganizeString(s string) string {
	n := len(s)
	cnt := make([]int, 26)
	for _, v := range s {
		cnt[v-'a']++
	}
	mx := slices.Max(cnt)
	if mx > n-mx+1 {
		return ""
	}

	idx := make([]int, 26)
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(a, b int) int { return cnt[b] - cnt[a] })
	b := []byte(s)
	j := 0
	for i := 0; i < n; i += 2 {
		for ; j < 26 && cnt[idx[j]] == 0; j++ {
		}
		c := idx[j]
		b[i] = byte(c + 'a')
		cnt[c]--
	}
	for i := 1; i < n; i += 2 {
		for ; j < 26 && cnt[idx[j]] == 0; j++ {
		}
		c := idx[j]
		b[i] = byte(c + 'a')
		cnt[c]--
	}
	return string(b)
}
