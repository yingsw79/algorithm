package main

// https://leetcode.cn/problems/sliding-subarray-beauty/

func getSubarrayBeauty(nums []int, k int, x int) []int {
	B := 50
	cnt := make([]int, B*2+1)
	res := make([]int, len(nums)-k+1)
	for i, v := range nums {
		cnt[v+B]++
		if i >= k {
			cnt[nums[i-k]+B]--
		}
		if i >= k-1 {
			s := 0
			for j, c := range cnt[:B] {
				s += c
				if s >= x {
					res[i+1-k] = j - B
					break
				}
			}
		}
	}
	return res
}
