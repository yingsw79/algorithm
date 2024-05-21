package main

// https://leetcode.cn/problems/number-of-wonderful-substrings/description/

func wonderfulSubstrings(word string) (res int64) {
	const N = 10
	cnt := [1 << N]int{0: 1}
	pre := 0
	for _, v := range word {
		pre ^= 1 << (v - 'a')
		res += int64(cnt[pre])
		for j := 0; j < N; j++ {
			res += int64(cnt[pre^(1<<j)])
		}
		cnt[pre]++
	}
	return
}
