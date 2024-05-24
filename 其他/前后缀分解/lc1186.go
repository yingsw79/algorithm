package main

// https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/

func maximumSum(arr []int) int {
	n := len(arr)
	f := make([]int, n+2)
	for i := n - 1; i >= 0; i-- {
		f[i] = arr[i] + max(f[i+1], 0)
	}
	pre, res := 0, int(-1e4)
	for i, v := range arr {
		pre = v + max(pre, 0)
		res = max(res, pre+max(max(f[i+1], f[i+2]), 0))
	}
	return res
}

func max(a, b int) int { if a > b { return a }; return b }
