package main

import "slices"

// https://leetcode.cn/problems/maximum-total-reward-using-operations-i/description/

func maxTotalReward(rewardValues []int) int {
	slices.Sort(rewardValues)
	rewardValues = slices.Compact(rewardValues)
	mx := slices.Max(rewardValues) * 2
	f := make([]bool, mx+1)
	f[0] = true
	for _, v := range rewardValues {
		for j := v*2 - 1; j >= v; j-- { // 0<=j-v<v
			f[j] = f[j] || f[j-v]
		}
	}
	for i := mx; i >= 0; i-- {
		if f[i] {
			return i
		}
	}
	return -1
}
