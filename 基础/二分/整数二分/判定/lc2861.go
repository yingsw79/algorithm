package main

import "sort"

// https://leetcode.cn/problems/maximum-number-of-alloys/description/

func maxNumberOfAlloys(n int, k int, budget int, composition [][]int, stock []int, cost []int) (res int) {
	for _, c := range composition {
		res = max(res, sort.Search(1e9, func(x int) bool {
			sum := 0
			for i, v := range c {
				sum += max(v*x-stock[i], 0) * cost[i]
				if sum > budget {
					return true
				}
			}
			return false
		})-1)
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }
