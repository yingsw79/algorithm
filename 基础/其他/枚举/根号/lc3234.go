package main

// https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/description/

func numberOfSubstrings(s string) (ans int) {
	tot1 := 0
	a := []int{-1} // 哨兵
	for right, b := range s {
		if b == '0' {
			a = append(a, right)
		} else {
			ans += right - a[len(a)-1]
			tot1++
		}
		for k := len(a) - 1; k > 0 && (len(a)-k)*(len(a)-k) <= tot1; k-- {
			cnt0 := len(a) - k
			cnt1 := right - a[k] + 1 - cnt0
			ans += max(a[k]-a[k-1]-max(cnt0*cnt0-cnt1, 0), 0)
		}
	}
	return
}
