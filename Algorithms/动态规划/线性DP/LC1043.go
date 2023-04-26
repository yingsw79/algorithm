package main

// https://leetcode.cn/problems/partition-array-for-maximum-sum/

func maxSumAfterPartitioning(arr []int, k int) int {
	n := len(arr)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		t := arr[i-1]
		for j := i - 1; j >= i-k && j >= 0; j-- {
			f[i] = max(f[i], f[j]+t*(i-j))
			if j > 0 {
				t = max(t, arr[j-1])
			}
		}
	}
	return f[n]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
