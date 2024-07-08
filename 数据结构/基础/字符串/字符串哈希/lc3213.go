package main

import "math"

// https://leetcode.cn/problems/construct-string-with-minimum-cost/

func minimumCost(target string, words []string, costs []int) int {
	const B = 131
	n := len(target)
	h := make([]uint64, n+1)
	p := make([]uint64, n+1)
	p[0] = 1
	for i, v := range target {
		h[i+1] = h[i]*B + uint64(v-'a'+1)
		p[i+1] = p[i] * B
	}
	getHash := func(l, r int) uint64 { return h[r] - h[l-1]*p[r-l+1] }

	mp := map[int]map[uint64]int{}
	for i, w := range words {
		x := uint64(0)
		for _, v := range w {
			x = x*B + uint64(v-'a'+1)
		}
		m := len(w)
		if mp[m] == nil {
			mp[m] = map[uint64]int{}
		}
		if mp[m][x] == 0 {
			mp[m][x] = costs[i]
		} else {
			mp[m][x] = min(mp[m][x], costs[i])
		}
	}

	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = math.MaxInt / 2
		for k, cs := range mp {
			j := i - k
			if j < 0 {
				continue
			}
			c := cs[getHash(j+1, i)]
			if c > 0 {
				f[i] = min(f[i], f[j]+c)
			}
		}
	}
	if f[n] == math.MaxInt/2 {
		return -1
	}
	return f[n]
}
