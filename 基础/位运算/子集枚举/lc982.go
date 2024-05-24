package main

// https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/

func countTriplets(nums []int) (ans int) {
	cnt := [1 << 16]int{}
	for _, x := range nums {
		for _, y := range nums {
			cnt[x&y]++
		}
	}
	for x, c := range cnt {
		for _, y := range nums {
			if x&y == 0 {
				ans += c
			}
		}
	}
	return
}

func _countTriplets(nums []int) (ans int) {
	cnt := [1 << 16]int{}
	for _, x := range nums {
		for _, y := range nums {
			cnt[x&y]++
		}
	}
	for _, m := range nums {
		m ^= 0xffff
		s := m
		for { // 枚举 m 的子集（包括空集）
			ans += cnt[s]
			s = (s - 1) & m
			if s == m {
				break
			}
		}
	}
	return
}
