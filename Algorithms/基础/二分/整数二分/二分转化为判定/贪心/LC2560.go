package main

import "sort"

// https://leetcode.cn/problems/house-robber-iv/
// https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/

func minCapability(nums []int, k int) int {
	return sort.Search(1e9, func(x int) bool {
		cnt, pre := 0, -2
		for i, v := range nums {
			if v <= x && i-pre > 1 {
				cnt++
				pre = i
			}
		}
		return cnt >= k
	})
}

// func minCapability(nums []int, k int) int {
// 	check := func(mid int) bool {
// 		cnt, pre := 0, -2
// 		for i, v := range nums {
// 			if v <= mid && i != pre+1 {
// 				pre = i
// 				cnt++
// 			}
// 		}
// 		return cnt >= k
// 	}
// 	l, r := 1, int(1e9)
// 	for l < r {
// 		mid := (l + r) >> 1
// 		if check(mid) {
// 			r = mid
// 		} else {
// 			l = mid + 1
// 		}
// 	}
// 	return l
// }
