package main

// https://leetcode.cn/problems/special-array-ii/description/

func isArraySpecial(nums []int, queries [][]int) []bool {
	sum := make([]int, len(nums))
	for i, v := range nums[1:] {
		sum[i+1] = sum[i]
		if (nums[i] % 2) == (v % 2) {
			sum[i+1]++
		}
	}
	res := make([]bool, len(queries))
	for i, q := range queries {
		res[i] = sum[q[0]] == sum[q[1]]
	}
	return res
}
