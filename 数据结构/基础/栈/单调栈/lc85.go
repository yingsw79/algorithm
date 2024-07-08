package main

// https://leetcode.cn/problems/maximal-rectangle/description/
// https://leetcode.cn/problems/largest-rectangle-in-histogram/

func maximalRectangle(matrix [][]byte) (res int) {
	m, n := len(matrix), len(matrix[0])
	h := make([][]int, m+1)
	for i := range h {
		h[i] = make([]int, n)
	}
	for j := 0; j < n; j++ {
		for i, row := range matrix {
			if row[j] == '1' {
				h[i+1][j] = h[i][j] + 1
			}
		}
	}
	for i := 1; i <= m; i++ {
		res = max(res, largestRectangleArea(h[i]))
	}
	return
}

func largestRectangleArea(heights []int) (res int) {
	heights = append(heights, 0)
	f := make([]int, len(heights))
	st := []int{}
	for i, v := range heights {
		w := 0
		for len(st) > 0 && heights[st[len(st)-1]] >= v {
			j := st[len(st)-1]
			w += f[j]
			res = max(res, w*heights[j])
			st = st[:len(st)-1]
		}
		f[i] = w + 1
		st = append(st, i)
	}
	return
}
