package main

// https://leetcode.cn/problems/count-the-number-of-good-subarrays/

func countGood(nums []int, k int) (res int64) {
	n := len(nums)
	mp := make(map[int]int, n)
	for i, j, s := 0, 0, 0; i < n; i++ {
		for ; s < k && j < n; j++ {
			s += mp[nums[j]]
			mp[nums[j]]++
		}
		if s < k && j == n {
			break
		}
		res += int64(n - j + 1)
		mp[nums[i]]--
		s -= mp[nums[i]]
	}
	return
}