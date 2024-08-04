package main

import "strconv"

// https://leetcode.cn/problems/find-duplicate-subtrees/?

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findDuplicateSubtrees(root *TreeNode) (res []*TreeNode) {
	id := 1
	mp := map[string]int{}
	cnt := map[int]int{}
	var dfs func(*TreeNode) int
	dfs = func(u *TreeNode) int {
		if u == nil {
			return 0
		}
		k := strconv.Itoa(u.Val) + "#" + strconv.Itoa(dfs(u.Left)) + "#" + strconv.Itoa(dfs(u.Right))
		if mp[k] == 0 {
			mp[k] = id
			id++
		}
		t := mp[k]
		cnt[t]++
		if cnt[t] == 2 {
			res = append(res, u)
		}
		return t
	}
	dfs(root)
	return
}
