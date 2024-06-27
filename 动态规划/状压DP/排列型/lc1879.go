package main

import (
	"math"
	"math/bits"
)

// https://leetcode.cn/problems/minimum-xor-sum-of-two-arrays/description/

func minimumXORSum(nums1 []int, nums2 []int) int {
	n := len(nums1)
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = math.MaxInt
	}
	f[0] = 0
	for s := 0; s < 1<<n; s++ {
		i := bits.OnesCount(uint(s))
		for j := 0; j < n; j++ {
			if (s>>j)&1 > 0 {
				continue
			}
			f[s|(1<<j)] = min(f[s|(1<<j)], f[s]+(nums1[i]^nums2[j]))
		}
	}
	return f[(1<<n)-1]
}
