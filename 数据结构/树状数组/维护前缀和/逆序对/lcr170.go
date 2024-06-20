package main

import (
	"slices"
	"sort"
)

// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/

type BIT []int

func (b BIT) Update(x, v int) {
	for ; x < len(b); x += x & -x {
		b[x] += v
	}
}

func (b BIT) Query(x int) (res int) {
	for ; x > 0; x &= (x - 1) {
		res += b[x]
	}
	return
}

func reversePairs(record []int) (res int) {
	sorted := slices.Clone(record)
	slices.Sort(sorted)
	sorted = slices.Compact(sorted)
	m := len(sorted)
	tr := make(BIT, m+1)
	find := func(v int) int { return sort.SearchInts(sorted, v) + 1 }
	// for _, v := range record {
	// 	x := find(v)
	// 	res += tr.Query(m) - tr.Query(x)
	// 	tr.Update(x, 1)
	// }
	for i := len(record) - 1; i >= 0; i-- {
		x := find(record[i])
		res += tr.Query(x - 1)
		tr.Update(x, 1)
	}
	return
}
