package main

// https://leetcode.cn/problems/count-substrings-with-k-frequency-characters-i/description/

func numberOfSubstrings(s string, k int) (res int) {
	j := 0
	cnt := [26]int{}
	for _, v := range s {
		v -= 'a'
		cnt[v]++
		for ; cnt[v] >= k; j++ {
			cnt[s[j]-'a']--
		}
		res += j
	}
	return
}
