package main

// https://leetcode.cn/problems/minimum-operations-to-convert-number/description/

func minimumOperations(nums []int, start, goal int) int {
	st := [1001]bool{}
	st[start] = true
	q := []int{start}
	for step := 1; q != nil; step++ {
		tmp := q
		q = nil
		for _, v := range tmp {
			for _, num := range nums {
				for _, x := range []int{v + num, v - num, v ^ num} {
					if x == goal {
						return step
					}
					if 0 <= x && x <= 1000 && !st[x] {
						st[x] = true
						q = append(q, x)
					}
				}
			}
		}
	}
	return -1
}
