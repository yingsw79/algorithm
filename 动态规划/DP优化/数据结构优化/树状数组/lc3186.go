package main

// https://leetcode.cn/problems/maximum-total-damage-with-spell-casting/description/

import (
	"slices"
	"sort"
)

type BIT []int

func (b BIT) Update(x, v int) {
	for ; x < len(b); x += x & -x {
		b[x] = max(b[x], v)
	}
}

func (b BIT) Query(x int) (res int) {
	for ; x > 0; x &= x - 1 {
		res = max(res, b[x])
	}
	return
}

func maximumTotalDamage(power []int) (res int64) {
	sorted := slices.Clone(power)
	slices.Sort(sorted)
	sorted = slices.Compact(sorted)
	m := len(sorted)
	tr := make(BIT, m+1)
	find := func(x int) int { return sort.SearchInts(sorted, x) + 1 }

	slices.Sort(power)
	f := map[int]int{}
	for _, v := range power {
		t := max(f[v], tr.Query(find(v-2)-1)) + v //
		f[v] = max(f[v], t)
		tr.Update(find(v), t)
		res = max(res, int64(t))
	}
	return
}
