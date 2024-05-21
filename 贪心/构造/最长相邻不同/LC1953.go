package main

import "slices"

// https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/?envType=daily-question&envId=2024-05-16

func numberOfWeeks(milestones []int) int64 {
	s := 0
	for _, v := range milestones {
		s += v
	}
	mx := slices.Max(milestones)
	if mx > s-mx+1 {
		return int64((s-mx)*2 + 1)
	}
	return int64(s)
}
