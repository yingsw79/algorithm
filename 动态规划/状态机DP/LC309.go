package main

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/?envType=daily-question&envId=2023-10-05

func maxProfit(prices []int) int {
	n := len(prices)
	f := [2][3]int{}
	f[0][1] = -prices[0]
	for i := 1; i < n; i++ {
		j := i & 1
		f[j][0] = max(f[j^1][0], f[j^1][2])
		f[j][1] = max(f[j^1][1], f[j^1][0]-prices[i])
		f[j][2] = f[j^1][1] + prices[i]
	}
	return max(f[(n-1)&1][0], f[(n-1)&1][2])
}

func max(a, b int) int { if a > b { return a }; return b }