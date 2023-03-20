package main

import "sort"

// https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func kthLargestLevelSum(root *TreeNode, k int) int64 {
	nums := []int64{}
	q := []*TreeNode{root}
	for len(q) > 0 {
		tmp := q
		q = nil
		sum := int64(0)
		for _, t := range tmp {
			sum += int64(t.Val)
			if t.Left != nil {
				q = append(q, t.Left)
			}
			if t.Right != nil {
				q = append(q, t.Right)
			}
		}
		nums = append(nums, sum)
	}
	if len(nums) < k {
		return -1
	}
	sort.Slice(nums, func(i, j int) bool { return nums[i] > nums[j] })
	return nums[k-1]
}
