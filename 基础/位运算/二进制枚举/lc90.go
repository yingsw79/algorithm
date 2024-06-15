package main

import "slices"

// https://leetcode.cn/problems/subsets-ii/description/

func subsetsWithDup(nums []int) (res [][]int) {
	slices.Sort(nums)
	n := len(nums)
	for i := 0; i < 1<<n; i++ {
		tmp := []int{}
		ok := true
		for j := 0; j < n; j++ {
			if (i>>j)&1 > 0 {
				if j > 0 && nums[j] == nums[j-1] && (i>>(j-1))&1 == 0 {
					ok = false
					break
				}
				tmp = append(tmp, nums[j])
			}
		}
		if ok {
			res = append(res, tmp)
		}
	}
	return
}
