package main

// https://leetcode.cn/problems/water-and-jug-problem/description/?envType=daily-question&envId=2024-01-28

func canMeasureWater(jug1Capacity int, jug2Capacity int, targetCapacity int) bool {
	type pair struct{ x, y int }
	memo := map[pair]bool{}
	var dfs func(int, int) bool
	dfs = func(x, y int) bool {
		if x == targetCapacity || y == targetCapacity || x+y == targetCapacity {
			return true
		}
		if memo[pair{x, y}] {
			return false
		}
		memo[pair{x, y}] = true
		if dfs(0, y) || dfs(x, 0) || dfs(jug1Capacity, y) || dfs(x, jug2Capacity) ||
			dfs(max(x-(jug2Capacity-y), 0), min(y+x, jug2Capacity)) ||
			dfs(min(x+y, jug1Capacity), max(y-(jug1Capacity-x), 0)) {
			return true
		}
		return false
	}
	return dfs(0, 0)
}
