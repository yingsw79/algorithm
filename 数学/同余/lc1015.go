package main

// https://leetcode.cn/problems/smallest-integer-divisible-by-k/

func smallestRepunitDivByK(k int) int {
	seen := map[int]bool{}
	x := 1 % k
	for x > 0 && !seen[x] {
		seen[x] = true
		x = (x*10 + 1) % k
	}
	if x > 0 {
		return -1
	}
	return len(seen) + 1
}
