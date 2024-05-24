package main

import "sort"

// https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs/
// https://leetcode.cn/problems/house-robber-iv/

func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	return sort.Search(1e9, func(x int) bool {
		cnt, pre := 0, -2
		for i, v := range nums[1:] {
			if v-nums[i] <= x && i-pre > 1 {
				cnt++
				pre = i
			}
		}
		return cnt >= p
	})
}
