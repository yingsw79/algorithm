package main

// https://leetcode.cn/problems/number-of-subarrays-with-and-value-of-k/description/

func countSubarrays(nums []int, k int) (res int64) {
	left, right := 0, 0
	for i, v := range nums {
		for j := i - 1; j >= 0 && nums[j]&v != nums[j]; j-- {
			nums[j] &= v
		}
		for left <= i && nums[left] < k {
			left++
		}
		for right <= i && nums[right] <= k {
			right++
		}
		res += int64(right - left)
	}
	return
}
