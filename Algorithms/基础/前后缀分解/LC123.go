package main

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=daily-question&envId=2023-10-03

func maxProfit(prices []int) (res int) {
	mi, n := prices[0], len(prices)
	pre := make([]int, n)
	for i := 1; i < n; i++ {
		pre[i] = max(pre[i-1], prices[i]-mi)
		mi = min(mi, prices[i])
	}
	mx, t := prices[n-1], 0
	for i := n - 2; i >= 0; i-- {
		t = max(t, mx-prices[i])
		mx = max(mx, prices[i])
		res = max(res, t+pre[i])
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }
func min(a, b int) int { if a < b { return a }; return b }