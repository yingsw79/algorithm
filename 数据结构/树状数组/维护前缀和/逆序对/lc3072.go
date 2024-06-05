package main

import (
	"slices"
	"sort"
)

// https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/description/?envType=daily-question&envId=2024-06-05

type BIT []int

func (b BIT) Update(x, v int) {
	for ; x < len(b); x += x & -x {
		b[x] += v
	}
}

func (b BIT) Query(x int) (res int) {
	for ; x > 0; x &= x - 1 {
		res += b[x]
	}
	return
}

func resultArray(nums []int) []int {
	sorted := slices.Clone(nums)
	slices.Sort(sorted)
	sorted = slices.Compact(sorted)
	m := len(sorted)
	find := func(v int) int { return sort.SearchInts(sorted, v) + 1 }

	a1 := []int{nums[0]}
	tr1 := make(BIT, m+1)
	tr1.Update(find(nums[0]), 1)

	a2 := []int{nums[1]}
	tr2 := make(BIT, m+1)
	tr2.Update(find(nums[1]), 1)
	for _, v := range nums[2:] {
		x := find(v)
		c1 := len(a1) - tr1.Query(x)
		c2 := len(a2) - tr2.Query(x)
		if c1 > c2 || c1 == c2 && len(a1) <= len(a2) {
			a1 = append(a1, v)
			tr1.Update(x, 1)
		} else {
			a2 = append(a2, v)
			tr2.Update(x, 1)
		}
	}
	return slices.Concat(a1, a2)
}
