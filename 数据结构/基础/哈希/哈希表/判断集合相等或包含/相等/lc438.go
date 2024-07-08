package main

// https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// https://leetcode.cn/problems/permutation-in-string/description/

// 1.
func findAnagrams(s string, p string) (res []int) {
	cnt0 := make([]int, 26)
	for _, v := range p {
		cnt0[v-'a']++
	}
	m := len(p)
	t := 0
	cnt := make([]int, 26)
	for i, v := range s {
		v -= 'a'
		if cnt[v]++; cnt[v] <= cnt0[v] {
			t++
		}
		if i >= m {
			c := s[i-m] - 'a'
			if cnt[c]--; cnt[c] < cnt0[c] {
				t--
			}
		}
		if t == m {
			res = append(res, i-m+1)
		}
	}
	return
}

// 2.
func _findAnagrams(s string, p string) (res []int) {
	cnt := make([]int, 26)
	for _, v := range p {
		cnt[v-'a']++
	}
	j := 0
	for i, v := range s {
		v -= 'a'
		cnt[v]--
		for ; cnt[v] < 0; j++ {
			cnt[s[j]-'a']++
		}
		if i-j+1 == len(p) {
			res = append(res, j)
		}
	}
	return
}
