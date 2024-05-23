package main

// https://leetcode.cn/problems/find-the-longest-equal-subarray/description/?envType=daily-question&envId=2024-05-23

func longestEqualSubarray(nums []int, k int) (res int) {
	pos := map[int][]int{}
	for i, v := range nums {
		pos[v] = append(pos[v], i)
	}
	for _, idx := range pos {
		j, n := 0, len(idx)
		for i, v := range idx {
			for ; j < n && v-idx[j]-(i-j) > k; j++ {
			}
			res = max(res, i-j+1)
		}
	}
	return
}
