package main

// https://leetcode.cn/problems/count-complete-subarrays-in-an-array/
// https://leetcode.cn/problems/subarrays-with-k-different-integers/

func countCompleteSubarrays(nums []int) (ans int) {
	set := map[int]struct{}{}
	for _, v := range nums {
		set[v] = struct{}{}
	}
	m := len(set)

	cnt := map[int]int{}
	left := 0
	for _, v := range nums { // 枚举子数组右端点 v=nums[i]
		cnt[v]++
		for len(cnt) == m {
			x := nums[left]
			cnt[x]--
			if cnt[x] == 0 {
				delete(cnt, x)
			}
			left++
		}
		ans += left // 子数组左端点 < left 的都是合法的
	}
	return
}
