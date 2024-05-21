package main

// https://leetcode.cn/problems/xor-queries-of-a-subarray/description/

func xorQueries(arr []int, queries [][]int) []int {
	sum := make([]int, len(arr)+1)
	for i, v := range arr {
		sum[i+1] = sum[i] ^ v
	}
	res := make([]int, len(queries))
	for i, q := range queries {
		res[i] = sum[q[1]+1] ^ sum[q[0]]
	}
	return res
}
