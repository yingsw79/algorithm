package main

import "slices"

// https://leetcode.cn/problems/find-the-integer-added-to-array-ii/description/?envType=daily-question&envId=2024-08-09

func minimumAddedInteger(nums1, nums2 []int) int {
	slices.Sort(nums1)
	slices.Sort(nums2)
	for i := 2; i > 0; i-- {
		x := nums2[0] - nums1[i]
		// 在 {nums1[i] + x} 中找子序列 nums2
		j := 0
		for _, v := range nums1[i:] {
			if nums2[j] == v+x {
				j++
				// nums2 是 {nums1[i] + x} 的子序列
				if j == len(nums2) {
					return x
				}
			}
		}
	}
	return nums2[0] - nums1[0]
}
