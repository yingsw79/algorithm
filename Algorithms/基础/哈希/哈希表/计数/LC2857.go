package main

// https://leetcode.cn/problems/count-pairs-of-points-with-distance-k/

func countPairs(coordinates [][]int, k int) (res int) {
	type pair struct{ x, y int }
	mp := map[pair]int{}
	for _, c := range coordinates {
		a, b := c[0], c[1]
		for i := 0; i <= k; i++ {
			res += mp[pair{a ^ i, b ^ (k - i)}]
		}
		mp[pair{a, b}]++
	}
	return
}
