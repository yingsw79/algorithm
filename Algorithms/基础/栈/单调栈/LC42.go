package main

// https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

func trap(height []int) (res int) {
	st := []int{}
	for i, v := range height {
		for len(st) > 0 && v > height[st[len(st)-1]] {
			t := height[st[len(st)-1]]
			st = st[:len(st)-1]
			if len(st) > 0 {
				j := st[len(st)-1]
				res += (min(v, height[j]) - t) * (i - j - 1)
			}
		}
		st = append(st, i)
	}
	return
}
