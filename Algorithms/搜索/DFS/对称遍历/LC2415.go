package main

// https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2023-12-15

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(root1 *TreeNode, root2 *TreeNode, isOdd bool) {
	if root1 == nil {
		return
	}
	if isOdd {
		root1.Val, root2.Val = root2.Val, root1.Val
	}
	dfs(root1.Left, root2.Right, !isOdd)
	dfs(root1.Right, root2.Left, !isOdd)
}

func reverseOddLevels(root *TreeNode) *TreeNode {
	dfs(root.Left, root.Right, true)
	return root
}
