package main

import (
	"math"
)

// https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

func minSumOfLengths(arr []int, target int) int {
	n, res := len(arr), math.MaxInt32
	pre, sum := make([]int, n+1), make([]int, n+1)
	pre[0] = math.MaxInt32
	for i, v := range arr {
		sum[i+1] = sum[i] + v
	}
	j := 0
	for i := 1; i <= n; i++ {
		for sum[i]-sum[j] > target {
			j++
		}
		pre[i] = pre[i-1]
		if sum[i]-sum[j] == target {
			res = min(res, i-j+pre[j])
			pre[i] = min(pre[i], i-j)
		}
	}
	if res == math.MaxInt32 {
		return -1
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
