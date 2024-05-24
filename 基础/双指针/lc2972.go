package main

// https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-ii/description/
// https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/

func incremovableSubarrayCount(nums []int) int64 {
	i, n := 0, len(nums)
	for ; i+1 < n && nums[i] < nums[i+1]; i++ {
	}
	if i == n-1 {
		return int64(n * (n + 1) / 2)
	}
	j := n - 2
	for ; j >= 0 && nums[j] < nums[j+1]; j-- {
	}
	res := n - j
	for k := 0; k <= i; k++ {
		for ; j+1 < n && nums[j+1] <= nums[k]; j++ {
		}
		res += n - j
	}
	return int64(res)
}
