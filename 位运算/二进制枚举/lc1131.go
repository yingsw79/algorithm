package main

import "math"

// https://leetcode.cn/problems/maximum-of-absolute-value-expression/description/

func maxAbsValExpr(arr1 []int, arr2 []int) (res int) {
	arr3 := make([]int, len(arr1))
	for i := range arr3 {
		arr3[i] = i
	}
	arr := [][]int{arr1, arr2, arr3}
	for i := 0; i < 1<<3; i++ {
		mx, mn := math.MinInt, math.MaxInt
		for j := range arr1 {
			t := 0
			for k := 0; k < 3; k++ {
				if (i>>k)&1 > 0 {
					t += arr[k][j]
				} else {
					t -= arr[k][j]
				}
			}
			mx = max(mx, t)
			mn = min(mn, t)
		}
		res = max(res, mx-mn)
	}
	return
}
