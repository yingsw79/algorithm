package main

import "sort"

// https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/

func maximumTastiness(price []int, k int) int {
	sort.Ints(price)
	return sort.Search(1e9, func(x int) bool {
		pre, cnt := price[0], 1
		for _, v := range price[1:] {
			if v-pre >= x {
				pre = v
				cnt++
			}
		}
		return cnt < k
	}) - 1
}
