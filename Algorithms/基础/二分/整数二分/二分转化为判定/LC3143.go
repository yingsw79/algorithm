package main

import (
	"math/bits"
	"sort"
)

// https://leetcode.cn/problems/maximum-points-inside-the-square/description/

func maxPointsInsideSquare(points [][]int, s string) (res int) {
	sort.Search(1e9+1, func(mid int) bool {
		st := 0
		for i, p := range points {
			j := s[i] - 'a'
			if abs(p[0]) <= mid && abs(p[1]) <= mid {
				if (st>>j)&1 > 0 {
					return true
				}
				st |= 1 << j
			}
		}
		res = bits.OnesCount(uint(st))
		return false
	})
	return
}

func abs(a int) int { if a < 0 { return -a }; return a }
