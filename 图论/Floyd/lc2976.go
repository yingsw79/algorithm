package main

import "math"

// https://leetcode.cn/problems/minimum-cost-to-convert-string-i/description/
// https://leetcode.cn/problems/minimum-cost-to-convert-string-ii/

func minimumCost(source string, target string, original []byte, changed []byte, cost []int) int64 {
	const INF int = math.MaxInt / 2
	d := [26][26]int{}
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			if i != j {
				d[i][j] = INF
			}
		}
	}
	for i, v := range original {
		a, b := v-'a', changed[i]-'a'
		d[a][b] = min(d[a][b], cost[i])
	}
	for k := 0; k < 26; k++ {
		for i := 0; i < 26; i++ {
			if d[i][k] >= INF {
				continue
			}
			for j := 0; j < 26; j++ {
				if d[i][j] > d[i][k]+d[k][j] {
					d[i][j] = d[i][k] + d[k][j]
				}
			}
		}
	}
	res := 0
	for i, v := range source {
		a, b := byte(v)-'a', target[i]-'a'
		if a == b {
			continue
		}
		if d[a][b] >= INF {
			return -1
		} else {
			res += d[a][b]
		}
	}
	return int64(res)
}
