package main

// https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/

func beautifulSubarrays(nums []int) (res int64) {
	mp := map[int]int{}
	mp[0] = 1
	s := 0
	for _, v := range nums {
		s ^= v
		res += int64(mp[s])
		mp[s]++
	}
	return
}
