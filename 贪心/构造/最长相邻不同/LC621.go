package main

import "slices"

// https://leetcode.cn/problems/task-scheduler/description/

func leastInterval(tasks []byte, n int) int {
	cnt := make([]int, 26)
	for _, v := range tasks {
		cnt[v-'A']++
	}
	mx := slices.Max(cnt)
	k := 0
	for _, v := range cnt {
		if v == mx {
			k++
		}
	}
	return max((mx-1)*(n+1)+k, len(tasks))
}
