package main

// https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/

func maximumSum(arr []int) int {
	n := len(arr)
	f := make([][2]int, n)
	f[0][0] = arr[0]
	res := arr[0]
	for i := 1; i < n; i++ {
		f[i][0] = max(f[i-1][0], 0) + arr[i]
		f[i][1] = max(f[i-1][0], f[i-1][1]+arr[i])
		res = max(res, f[i][0], f[i][1])
	}
	return res
}
