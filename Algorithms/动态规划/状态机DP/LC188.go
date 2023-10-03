package main

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

func maxProfit(k int, prices []int) (res int) {
	f := [2][2][101]int{}
	for i := 0; i < k; i++ {
		f[0][1][i] = -prices[0]
	}
	for i := 1; i < len(prices); i++ {
		t := i & 1
		for j := 0; j <= k; j++ {
			f[t][0][j] = f[t^1][0][j]
			if j > 0 {
				f[t][0][j] = max(f[t][0][j], f[t^1][1][j-1]+prices[i])
			}
			f[t][1][j] = max(f[t^1][1][j], f[t^1][0][j]-prices[i])
			res = max(res, max(f[t][0][j], f[t][1][j]))
		}
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }
