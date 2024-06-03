package main

import "slices"

// https://leetcode.cn/problems/find-the-number-of-good-pairs-ii/description/

// 枚举倍数
func numberOfPairs(nums1 []int, nums2 []int, k int) (res int64) {
	cnt1 := map[int]int{}
	for _, v := range nums1 {
		if v%k == 0 {
			cnt1[v/k]++
		}
	}
	cnt2 := map[int]int{}
	for _, v := range nums2 {
		cnt2[v]++
	}
	mx := slices.Max(nums1) / k
	for v, c := range cnt2 {
		s := 0
		for i := v; i <= mx; i += v {
			s += cnt1[i]
		}
		res += int64(s * c)
	}
	return
}

// 枚举因数
func _numberOfPairs(nums1 []int, nums2 []int, k int) (res int64) {
	cnt := make(map[int]int)
	for _, v := range nums2 {
		cnt[v]++
	}
	for _, v := range nums1 {
		if v%k > 0 {
			continue
		}
		v /= k
		for i := 1; i*i <= v; i++ {
			if v%i > 0 {
				continue
			}
			res += int64(cnt[i])
			if i*i < v {
				res += int64(cnt[v/i])
			}
		}
	}
	return
}
