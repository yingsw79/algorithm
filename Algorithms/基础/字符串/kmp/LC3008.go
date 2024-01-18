package main

// https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-ii/

func beautifulIndices(s string, a string, b string, k int) (res []int) {
	pa, pb := kmp(s, a), kmp(s, b)
	j, n := 0, len(pb)
	for _, v := range pa {
		for ; j < n && pb[j] < v-k; j++ {
		}
		if j >= n {
			break
		}
		if abs(v-pb[j]) <= k {
			res = append(res, v)
		}
	}
	return
}

func kmp(s, pattern string) (res []int) {
	m := len(pattern)
	ne := make([]int, m)
	for i, j := 1, 0; i < m; i++ {
		for ; j > 0 && pattern[j] != pattern[i]; j = ne[j-1] {
		}
		if pattern[j] == pattern[i] {
			j++
		}
		ne[i] = j
	}

	j := 0
	for i, v := range s {
		for ; j > 0 && pattern[j] != byte(v); j = ne[j-1] {
		}
		if pattern[j] == byte(v) {
			j++
		}
		if j == m {
			res = append(res, i-m+1)
			j = ne[j-1]
		}
	}
	return
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
