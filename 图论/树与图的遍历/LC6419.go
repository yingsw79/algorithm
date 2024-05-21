package main

// https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree/

func minIncrements(n int, cost []int) (ans int) {
	for i := n / 2; i > 0; i-- { // 从最后一个非叶节点开始算
		left, right := cost[i*2-1], cost[i*2]
		if left > right { // 保证 left <= right
			left, right = right, left
		}
		ans += right - left // 两个子节点变成一样的
		cost[i-1] += right  // 累加路径和
	}
	return
}
