package main

// https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii/description/

func maximumLength(nums []int, k int) int {
	mx := make([]int, k+1)
	mp := map[int][]int{}
	for _, v := range nums {
		if mp[v] == nil {
			mp[v] = make([]int, k+1)
		}
		f := mp[v]
		for j := k; j >= 0; j-- {
			f[j]++
			if j > 0 {
				f[j] = max(f[j], mx[j-1]+1)
			}
			mx[j] = max(mx[j], f[j])
		}
	}
	return mx[k]
}
