package main

// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func dfs(root *TreeNode, mi, ma int) int {
	if root == nil {
		return 0
	}
	diff := max(abs(root.Val-mi), abs(root.Val-ma))
	mi, ma = min(mi, root.Val), max(ma, root.Val)
	diff = max(diff, dfs(root.Left, mi, ma))
	diff = max(diff, dfs(root.Right, mi, ma))
	return diff
}

func maxAncestorDiff(root *TreeNode) int {
	return dfs(root, root.Val, root.Val)
}
