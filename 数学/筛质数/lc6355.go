package main

import "sort"

// https://leetcode.cn/problems/prime-subtraction-operation/

var primes []int

func init() {
	const N = 1000
	st := [N]bool{}
	for i := 2; i < N; i++ {
		if !st[i] {
			primes = append(primes, i)
			for j := i * i; j < N; j += i {
				st[j] = true
			}
		}
	}
}

func primeSubOperation(nums []int) bool {
	for i := len(nums) - 2; i >= 0; i-- {
		if nums[i] >= nums[i+1] {
			x := sort.SearchInts(primes, nums[i]-nums[i+1]+1)
			if x == len(primes) {
				return false
			}
			nums[i] -= primes[x]
			if nums[i] <= 0 {
				return false
			}
		}
	}
	return true
}
