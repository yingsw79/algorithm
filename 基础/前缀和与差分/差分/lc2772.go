package main

// https://leetcode.cn/problems/apply-operations-to-make-all-array-elements-equal-to-zero/

func checkArray(nums []int, k int) bool {
	s, n := 0, len(nums)
	diff := make([]int, n+1)
	for i, v := range nums {
		s += diff[i]
		t := v - s
		if t == 0 {
			continue
		}
		if t < 0 || t > 0 && i+k > n {
			return false
		}
		s += t // 直接加
		diff[i+k] -= t
	}
	return true
}
