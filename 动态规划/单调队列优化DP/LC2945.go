package main

// https://leetcode.cn/problems/find-maximum-non-decreasing-array-length/description/

func findMaximumLength(nums []int) int {
	n := len(nums)
	f := make([]int, n+1)
	last := make([]int, n+1)
	sum := make([]int, n+1)
	q := []int{0}
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}
	for i := 1; i <= n; i++ {
		for len(q) > 1 && sum[q[1]]+last[q[1]] <= sum[i] {
			q = q[1:]
		}
		f[i] = f[q[0]] + 1
		last[i] = sum[i] - sum[q[0]]
		for len(q) > 0 && sum[q[len(q)-1]]+last[q[len(q)-1]] >= sum[i]+last[i] {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}
	return f[n]
}
