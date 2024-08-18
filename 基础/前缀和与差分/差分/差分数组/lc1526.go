package main

// https://leetcode.cn/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description//

func minNumberOperations(target []int) int {
	res := target[0]
	for i := 1; i < len(target); i++ {
		res += max(target[i]-target[i-1], 0)
	}
	return res
}
