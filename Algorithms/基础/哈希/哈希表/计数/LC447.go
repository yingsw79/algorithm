package main

// https://leetcode.cn/problems/number-of-boomerangs/description/?envType=daily-question&envId=2024-01-08

func numberOfBoomerangs(points [][]int) (ans int) {
	cnt := map[int]int{}
	for _, p1 := range points {
		clear(cnt)
		for _, p2 := range points {
			d2 := (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1])
			ans += cnt[d2] * 2
			cnt[d2]++
		}
	}
	return ans
}
