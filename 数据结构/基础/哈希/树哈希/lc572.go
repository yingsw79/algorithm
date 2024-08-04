package main

import "strconv"

// https://leetcode.cn/problems/subtree-of-another-tree/description/?envType=daily-question&envId=2024-08-04

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubtree(root *TreeNode, subRoot *TreeNode) (res bool) {
	id := 1
	target := -1
	mp := map[string]int{}
	var dfs func(*TreeNode) int
	dfs = func(u *TreeNode) int {
		if u == nil {
			return 0
		}
		s := strconv.Itoa(dfs(u.Left)) + "#" + strconv.Itoa(u.Val) + "#" + strconv.Itoa(dfs(u.Right))
		if mp[s] == 0 {
			mp[s] = id
			id++
		}
		x := mp[s]
		if x == target {
			res = true
		}
		return x
	}
	target = dfs(subRoot)
	dfs(root)
	return
}
