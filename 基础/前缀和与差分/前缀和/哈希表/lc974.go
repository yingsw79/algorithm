package main

// https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/

func subarraysDivByK(nums []int, k int) (res int) {
	cnt := map[int]int{0: 1}
	pre := 0
	for _, v := range nums {
		pre += v
		t := ((pre % k) + k) % k
		res += cnt[t]
		cnt[t]++
	}
	return
}
