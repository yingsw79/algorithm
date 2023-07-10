package main

// https://leetcode.cn/problems/longest-non-decreasing-subarray-from-two-arrays/

func maxNonDecreasingLength(nums1 []int, nums2 []int) (res int) {
	f := [2][2]int{}
	for i, v := range nums1 {
		j := i & 1
		f[j][0], f[j][1] = 1, 1
		if i > 0 {
			if v >= nums1[i-1] {
				f[j][0] = f[j^1][0] + 1
			}
			if v >= nums2[i-1] {
				f[j][0] = max(f[j][0], f[j^1][1]+1)
			}
			if nums2[i] >= nums1[i-1] {
				f[j][1] = f[j^1][0] + 1
			}
			if nums2[i] >= nums2[i-1] {
				f[j][1] = max(f[j][1], f[j^1][1]+1)
			}
		}
		res = max(res, max(f[j][0], f[j][1]))
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }