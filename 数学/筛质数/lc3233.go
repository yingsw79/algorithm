package main

import "math"

// https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/description/

const mx = 31622

var sp = [mx + 1]int{}

func init() {
	for i := 2; i <= mx; i++ {
		if sp[i] == 0 {
			sp[i] = sp[i-1] + 1
			for j := i * i; j <= mx; j += i {
				sp[j] = -1
			}
		} else {
			sp[i] = sp[i-1]
		}
	}
}

func nonSpecialCount(l, r int) int {
	cntR := sp[int(math.Sqrt(float64(r)))]
	cntL := sp[int(math.Sqrt(float64(l-1)))]
	return r - l + 1 - (cntR - cntL)
}
