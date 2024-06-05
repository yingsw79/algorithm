package main

// https://leetcode.cn/problems/make-sum-divisible-by-p/description/

// (sum-(s[j]-s[i]))%k==0
// (s[j]-sum)%k==s[i]%k
func minSubarray(nums []int, p int) int {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum%p == 0 {
		return 0
	}
	pos := map[int]int{0: -1}
	pre, res := 0, len(nums)
	for i, v := range nums {
		pre += v
		if j, ok := pos[((pre-sum)%p+p)%p]; ok {
			res = min(res, i-j)
		}
		pos[pre%p] = i
	}
	if res == len(nums) {
		return -1
	}
	return res
}
