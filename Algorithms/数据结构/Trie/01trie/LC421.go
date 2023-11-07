package main

// https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/?envType=daily-question&envId=2023-11-04

// 1.trie
type Node struct {
	next [2]*Node
}

func (node *Node) insert(num int) {
	p := node
	for i := 31; i >= 0; i-- {
		t := (num >> i) & 1
		if p.next[t] == nil {
			p.next[t] = &Node{}
		}
		p = p.next[t]
	}
}

func (node *Node) query(num int) (res int) {
	p := node
	for i := 31; i >= 0; i-- {
		t := (num >> i) & 1
		if p.next[t^1] != nil {
			res |= 1 << i
			p = p.next[t^1]
		} else {
			p = p.next[t]
		}
	}
	return
}

func max(a, b int) int { if a > b { return a }; return b }

func findMaximumXOR(nums []int) (res int) {
	root := &Node{}
	for _, v := range nums {
		root.insert(v)
		res = max(res, root.query(v))
	}
	return
}

// 2.
// func findMaximumXOR(nums []int) (ans int) {
//     highBit := bits.Len(uint(slices.Max(nums))) - 1
//     seen := map[int]bool{}
//     mask := 0
//     for i := highBit; i >= 0; i-- { // 从最高位开始枚举
//         clear(seen)
//         mask |= 1 << i
//         newAns := ans | 1<<i // 这个比特位可以是 1 吗？
//         for _, x := range nums {
//             x &= mask // 低于 i 的比特位置为 0
//             if seen[newAns^x] {
//                 ans = newAns // 这个比特位可以是 1
//                 break
//             }
//             seen[x] = true
//         }
//     }
//     return
// }

