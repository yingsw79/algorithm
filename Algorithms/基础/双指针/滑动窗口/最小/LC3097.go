package main

import "math"

// https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii/description/

func minimumSubarrayLength(nums []int, k int) int {
	cnt := [32]int{}
	j, sum := 0, 0
	res := math.MaxInt
	for i, v := range nums {
		sum |= v
		for c := 0; c < 32; c++ {
			if (v>>c)&1 > 0 {
				cnt[c]++
			}
		}
		for ; j <= i && sum >= k; j++ {
			res = min(res, i-j+1)
			for c := 0; c < 32; c++ {
				if (nums[j]>>c)&1 > 0 {
					cnt[c]--
					if cnt[c] == 0 {
						sum ^= 1 << c
					}
				}
			}
		}
	}
	if res == math.MaxInt {
		return -1
	}
	return res
}
