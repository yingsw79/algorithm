package main

// https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/description/?envType=daily-question&envId=2024-01-18

import "sort"

func minimumRemoval(beans []int) int64 {
	sort.Ints(beans)
	sum := 0
	for _, v := range beans {
		sum += v
	}
	res := sum
	for i, v := range beans {
		res = min(res, sum-v*(len(beans)-i))
	}
	return int64(res)
}
