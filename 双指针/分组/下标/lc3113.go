package main

// https://leetcode.cn/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/

func numberOfSubarrays(nums []int) (res int64) {
	pos := map[int][]int{}
	left := make([]int, len(nums))
	st := []int{}
	for i, v := range nums {
		for len(st) > 0 && v >= nums[st[len(st)-1]] {
			st = st[:len(st)-1]
		}
		left[i] = -1
		if len(st) > 0 {
			left[i] = st[len(st)-1]
		}
		st = append(st, i)
		pos[v] = append(pos[v], i)
	}
	for _, idx := range pos {
		j, n := 0, len(idx)
		for i, v := range idx {
			for ; j < n && idx[j] <= left[v]; j++ {
			}
			res += int64(i - j + 1)
		}
	}
	return
}
