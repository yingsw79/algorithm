package main

// https://leetcode.cn/problems/longest-alternating-subarray/description/?envType=daily-question&envId=2024-01-23

func alternatingSubarray(nums []int) int {
	res := -1
	n := len(nums)
	for i := 0; i < n-1; i++ {
		if nums[i+1]-nums[i] != 1 {
			continue
		}
		j := i + 2
		for ; j < n && nums[j] == nums[j-2]; j++ {
		}
		res = max(res, j-i)
		i = j - 2
	}
	return res
}
