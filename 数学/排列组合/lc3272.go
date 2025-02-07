package main

import (
	"math"
	"slices"
	"strconv"
)

// https://leetcode.cn/problems/find-the-count-of-good-integers/description/
// https://leetcode.cn/problems/minimum-cost-to-make-array-equalindromic/description/

func countGoodIntegers(n, k int) (ans int64) {
	fact := make([]int, n+1)
	fact[0] = 1
	for i := 1; i <= n; i++ {
		fact[i] = fact[i-1] * i
	}
	vis := map[string]bool{}
	base := int(math.Pow10((n - 1) / 2))
	for i := base; i < base*10; i++ { // 枚举回文数左半边
		x := i
		t := i
		if n%2 > 0 {
			t /= 10
		}
		for ; t > 0; t /= 10 {
			x = x*10 + t%10
		}
		if x%k > 0 { // 回文数不能被 k 整除
			continue
		}

		bs := []byte(strconv.Itoa(x))
		slices.Sort(bs)
		s := string(bs)
		if vis[s] { // 不能重复统计
			continue
		}
		vis[s] = true

		cnt := [10]int{}
		for _, c := range bs {
			cnt[c-'0']++
		}
		res := (n - cnt[0]) * fact[n-1]
		for _, c := range cnt {
			res /= fact[c]
		}
		ans += int64(res)
	}
	return
}
