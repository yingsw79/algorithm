package main

// https://leetcode.cn/problems/minimum-operations-to-make-array-equal-to-target/description/

func minimumOperations(nums, target []int) int64 {
	n := len(nums)
	res := max(target[0]-nums[0], 0)
	for i := 1; i < n; i++ {
		res += max((target[i]-nums[i])-(target[i-1]-nums[i-1]), 0)
	}
	res += max(-(target[n-1] - nums[n-1]), 0)
	return int64(res)
}
