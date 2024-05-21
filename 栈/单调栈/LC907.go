package main

// https://leetcode.cn/problems/sum-of-subarray-minimums/?envType=daily-question&envId=2023-11-27

func sumSubarrayMins(arr []int) (res int) {
	const MOD int = 1e9 + 7
	n := len(arr)
	L, R := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		L[i], R[i] = -1, n
	}
	st := []int{}
	for i, v := range arr {
		for len(st) > 0 && arr[st[len(st)-1]] > v {
			R[st[len(st)-1]] = i
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			L[i] = st[len(st)-1]
		}
		st = append(st, i)
	}
	for i := 0; i < n; i++ {
		res += (i - L[i]) * (R[i] - i) * arr[i]
		res %= MOD
	}
	return
}
