package main

import "slices"

// https://leetcode.cn/problems/minimum-amount-of-damage-dealt-to-bob/description/

// 1 2
// 79 80
// 79+80*3  80*2+79*3
// 80 79*2

func minDamage(power int, damage []int, health []int) (res int64) {
	idx := make([]int, len(damage))
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int {
		return damage[j]*((health[i]+power-1)/power) - damage[i]*((health[j]+power-1)/power)
	})
	s := 0
	for _, i := range idx {
		s += (health[i] + power - 1) / power
		res += int64(s * damage[i])
	}
	return
}
