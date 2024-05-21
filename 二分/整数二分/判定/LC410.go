package main

import "sort"

// https://leetcode.cn/problems/split-array-largest-sum/

func splitArray(nums []int, k int) int {
	return sort.Search(1e9, func(mid int) bool {
		var sum, cnt int
		for _, v := range nums {
			if sum+v <= mid {
				sum += v
			} else {
				cnt++
				sum = v
				if sum > mid {
					return false
				}
			}
		}
		return cnt <= k-1
	})
}
