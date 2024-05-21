package main

// https://leetcode.cn/problems/maximum-alternating-subsequence-sum/

func maxAlternatingSum(nums []int) int64 {
	n, f := len(nums), [2][2]int64{}
	f[0][1] = int64(nums[0])
	for i := 1; i < n; i++ {
		j := i & 1
		f[j][0] = max(f[j^1][0], f[j^1][1]-int64(nums[i]))
		f[j][1] = max(f[j^1][1], f[j^1][0]+int64(nums[i]))
	}
	return max(f[(n-1)&1][0], f[(n-1)&1][1])
}

func max(a, b int64) int64 { if a > b { return a }; return b }
