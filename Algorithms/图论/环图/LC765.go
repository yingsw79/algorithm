package main

// https://leetcode.cn/problems/couples-holding-hands/?envType=daily-question&envId=2023-11-11

func minSwapsCouples(row []int) int {
	n := len(row)
	p := make([]int, n/2)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	cnt := n
	for i := 0; i < n; i += 2 {
		if a, b := find(row[i]/2), find(row[i+1]/2); a != b {
			p[a] = b
			cnt--
		}
	}
	return n - cnt
}
