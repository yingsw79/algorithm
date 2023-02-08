package main

// https://leetcode.cn/problems/maximize-win-from-two-segments/

func maximizeWin(prizePositions []int, k int) (res int) {
	pre := make([]int, len(prizePositions)+1)
	j := 0
	for i, v := range prizePositions {
		for v-prizePositions[j] > k {
			j++
		}
		res = max(res, i-j+1+pre[j])
		pre[i+1] = max(pre[i], i-j+1)
	}
	return
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
