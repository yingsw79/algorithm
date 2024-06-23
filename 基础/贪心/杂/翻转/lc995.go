package main

// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/

func minKBitFlips(nums []int, k int) (res int) {
	n := len(nums)
	d := make([]int, n+1)
	s := 0
	for i, v := range nums {
		s += d[i]
		if v == s%2 {
			if i > n-k {
				return -1
			}
			res++
			s++
			d[i+k]--
		}
	}
	return
}
