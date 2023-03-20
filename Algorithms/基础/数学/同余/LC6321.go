package main

// https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/

func findSmallestInteger(nums []int, value int) (res int) {
	mp := map[int]int{}
	for _, v := range nums {
		mp[((v%value)+value)%value]++
	}
	for mp[res%value] > 0 {
		mp[res%value]--
		res++
	}
	return
}
