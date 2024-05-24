package main

import "math"

// https://leetcode.cn/problems/number-of-visible-people-in-a-queue/description/?envType=daily-question&envId=2024-01-05

func canSeePersonsCount(heights []int) []int {
	n := len(heights)
	res := make([]int, n)
	st := []int{math.MaxInt}
	for i := n - 1; i >= 0; i-- {
		for st[len(st)-1] < heights[i] {
			st = st[:len(st)-1]
			res[i]++
		}
		if len(st) > 1 {
			res[i]++
		}
		st = append(st, heights[i])
	}
	return res
}
