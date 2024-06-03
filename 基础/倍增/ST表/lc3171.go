package main

import "math"

// https://leetcode.cn/problems/find-subarray-with-bitwise-and-closest-to-k/description/

const N int = 1e5 + 10

var log2 [N]int
var f [N][17]int

func init() {
	for i := 2; i < N; i++ {
		log2[i] = log2[i>>1] + 1
	}
}

func minimumDifference(nums []int, k int) int {
	n := len(nums)
	m := log2[n] + 1
	for i := 1; i <= n; i++ {
		f[i][0] = nums[i-1]
	}
	for j := 1; j < m; j++ {
		for i := 1; i+(1<<j)-1 <= n; i++ {
			f[i][j] = f[i][j-1] & f[i+(1<<(j-1))][j-1]
		}
	}
	query := func(l, r int) int {
		x := log2[r-l+1]
		return f[l][x] & f[r-(1<<x)+1][x]
	}
	res := math.MaxInt
	for i := 1; i <= n; i++ {
		l, r := i, n
		for l < r {
			mid := (l + r) >> 1
			if query(i, mid) <= k {
				r = mid
			} else {
				l = mid + 1
			}
		}
		res = min(res, abs(query(i, l)-k))
		if l > i {
			res = min(res, abs(query(i, l-1)-k))
		}
	}
	return res
}

func abs(a int) int { if a < 0 { return -a }; return a }