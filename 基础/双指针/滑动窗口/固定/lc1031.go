package main

// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/

func maxSumTwoNoOverlap(nums []int, firstLen int, secondLen int) (res int) {
	n := len(nums)
	f, g := make([]int, n+1), make([]int, n+1)
	s, t := 0, 0
	for i, v := range nums {
		s += v
		if i >= firstLen {
			s -= nums[i-firstLen]
		}
		t += v
		if i >= secondLen {
			t -= nums[i-secondLen]
		}
		if i >= firstLen+secondLen-1 {
			res = max(res, max(s+g[i+1-firstLen], t+f[i+1-secondLen]))
		}
		f[i+1] = max(f[i], s)
		g[i+1] = max(g[i], t)
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }