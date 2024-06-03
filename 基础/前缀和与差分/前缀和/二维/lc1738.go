package main

import "slices"

// https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/description/?envType=daily-question&envId=2024-05-26

func kthLargestValue(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	a := make([]int, 0, m*n)
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i, row := range matrix {
		for j, v := range row {
			s[i+1][j+1] = s[i+1][j] ^ s[i][j+1] ^ s[i][j] ^ v
		}
		a = append(a, s[i+1][1:]...)
	}
	slices.Sort(a)
	return a[len(a)-k]
}
