package main

// https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/

func divisibilityArray(word string, m int) []int {
	res := make([]int, len(word))
	t := 0
	for i, v := range word {
		t = (t*10 + int(v-'0')) % m
		if t == 0 {
			res[i] = 1
		}
	}
	return res
}
