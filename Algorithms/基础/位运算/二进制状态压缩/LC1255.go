package main

// https://leetcode.cn/problems/maximum-score-words-formed-by-letters/

// https://leetcode.cn/problems/maximum-number-of-achievable-transfer-requests/
// https://leetcode.cn/problems/count-number-of-maximum-bitwise-or-subsets/
// https://leetcode.cn/problems/maximum-rows-covered-by-columns/

func maxScoreWords(words []string, letters []byte, score []int) (res int) {
	cnt := [26]int{}
	for _, v := range letters {
		cnt[v-'a']++
	}
	n := len(words)
	for i := 0; i < 1<<n; i++ {
		cnt1 := [26]int{}
		ok := true
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
				for _, v := range words[j] {
					t := v - 'a'
					cnt1[t]++
					if cnt1[t] > cnt[t] {
						ok = false
						break
					}
				}
			}
			if !ok {
				break
			}
		}
		if ok {
			sum := 0
			for k, v := range cnt1 {
				sum += score[k] * v
			}
			res = max(res, sum)
		}
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
