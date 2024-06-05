package main

// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxAncestorDiff(root *TreeNode) int {
	return dfs(root, root.Val, root.Val)
}

func dfs(root *TreeNode, mn, mx int) int {
	if root == nil {
		return 0
	}
	diff := max(abs(root.Val-mn), abs(root.Val-mx))
	mn, mx = min(mn, root.Val), max(mx, root.Val)
	diff = max(diff, dfs(root.Left, mn, mx))
	diff = max(diff, dfs(root.Right, mn, mx))
	return diff
}

func abs(a int) int { if a < 0 { return -a }; return a }