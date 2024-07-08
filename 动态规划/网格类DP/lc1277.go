package main

// https://leetcode.cn/problems/count-square-submatrices-with-all-ones/
// https://leetcode.cn/problems/maximal-square/description/

func countSquares(matrix [][]int) (res int) {
	m, n := len(matrix), len(matrix[0])
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	for i, r := range matrix {
		for j, v := range r {
			if v == 1 {
				f[i+1][j+1] = min(f[i][j+1], f[i+1][j], f[i][j]) + 1
				res += f[i+1][j+1]
			}
		}
	}
	return
}
