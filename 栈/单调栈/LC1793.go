package main

// https://leetcode.cn/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2024-03-19

func maximumScore(nums []int, k int) (res int) {
	n := len(nums)
	left := make([]int, n)
	right := make([]int, n)
	st := []int{}
	for i, v := range nums {
		left[i] = -1
		for len(st) > 0 && v <= nums[st[len(st)-1]] {
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			left[i] = st[len(st)-1]
		}
		st = append(st, i)
	}
	st = []int{}
	for i, v := range nums {
		right[i] = n
		for len(st) > 0 && v < nums[st[len(st)-1]] {
			right[st[len(st)-1]] = i
			st = st[:len(st)-1]
		}
		st = append(st, i)
	}
	for i, v := range nums {
		if left[i] < k && right[i] > k {
			res = max(res, v*(right[i]-left[i]-1))
		}
	}
	return
}
