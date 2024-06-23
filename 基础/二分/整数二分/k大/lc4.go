package main

// https://leetcode.cn/problems/median-of-two-sorted-arrays/description/

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n := len(nums1) + len(nums2)
	if n%2 > 0 {
		return float64(find(nums1, nums2, n/2+1))
	}
	return float64(find(nums1, nums2, n/2)+find(nums1, nums2, n/2+1)) / 2
}

func find(nums1, nums2 []int, k int) int {
	if len(nums1) == 0 {
		return nums2[k-1]
	}
	if len(nums2) == 0 {
		return nums1[k-1]
	}
	if k == 1 {
		return min(nums1[0], nums2[0])
	}
	i, j := min(k/2, len(nums1)), min(k/2, len(nums2))
	if nums1[i-1] <= nums2[j-1] {
		return find(nums1[i:], nums2, k-i)
	}
	return find(nums1, nums2[j:], k-j)
}
