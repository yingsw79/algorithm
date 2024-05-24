package main

// https://leetcode.cn/problems/find-the-most-competitive-subsequence/description/?envType=daily-question&envId=2024-05-24

func mostCompetitive(nums []int, k int) []int {
	st := []int{}
	for i, v := range nums {
		for len(st) > 0 && v < st[len(st)-1] && len(st)+len(nums)-i > k {
			st = st[:len(st)-1]
		}
		if len(st) < k {
			st = append(st, v)
		}
	}
	return st
}
