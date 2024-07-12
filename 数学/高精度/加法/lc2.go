package main

// https://leetcode.cn/problems/add-two-numbers/description/

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := &ListNode{}
	p := dummy
	for c := 0; l1 != nil || l2 != nil || c > 0; p = p.Next {
		if l1 != nil {
			c += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			c += l2.Val
			l2 = l2.Next
		}
		p.Next = &ListNode{Val: c % 10}
		c /= 10
	}
	return dummy.Next
}
