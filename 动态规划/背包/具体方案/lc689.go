package main

// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/?envType=daily-question&envId=2023-11-19

func maxSumOfThreeSubarrays(nums []int, k int) (res []int) {
	n := len(nums)
	if n < k*3 {
		return
	}
	sum := make([]int, n+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}
	f := make([][4]int, n+2)
	for i := n - k + 1; i >= 1; i-- {
		for j := 0; j <= 3; j++ {
			f[i][j] = f[i+1][j]
			if j > 0 {
				f[i][j] = max(f[i][j], f[i+k][j-1]+sum[i+k-1]-sum[i-1])
			}
		}
	}
	for i, j := 1, 3; j > 0; i++ {
		if f[i][j] == f[i+k][j-1]+sum[i+k-1]-sum[i-1] {
			res = append(res, i-1)
			i += k - 1
			j--
		}
	}
	return
}
