package main

// https://leetcode.cn/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-01-09
// https://leetcode.cn/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

type node struct {
	next  [26]*node
	isEnd bool
}

func (nd *node) insert(word string) {
	p := nd
	for i := len(word) - 1; i >= 0; i-- { // 后缀
		c := word[i] - 'a'
		if p.next[c] == nil {
			p.next[c] = &node{}
		}
		p = p.next[c]
	}
	p.isEnd = true
}

func (nd *node) query(s string, x int) (res []int) {
	p := nd
	for i := x; i >= 0; i-- {
		c := s[i] - 'a'
		if p.next[c] == nil {
			break
		}
		p = p.next[c]
		if p.isEnd {
			res = append(res, i)
		}
	}
	return
}

func minExtraChar(s string, dictionary []string) int {
	n := len(s)
	f := make([]int, n+1)
	tr := &node{}
	for _, v := range dictionary {
		tr.insert(v)
	}
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] + 1
		for _, j := range tr.query(s, i-1) {
			f[i] = min(f[i], f[j])
		}
	}
	return f[n]
}

// func minExtraChar(s string, dictionary []string) int {
// 	n := len(s)
// 	set := map[string]bool{}
// 	for _, v := range dictionary {
// 		set[v] = true
// 	}
// 	f := make([]int, n+1)
// 	for i := 1; i <= n; i++ {
// 		f[i] = f[i-1] + 1
// 		for j := 0; j < i; j++ {
// 			if set[s[j:i]] { // trie 优化
// 				f[i] = min(f[i], f[j])
// 			}
// 		}
// 	}
// 	return f[n]
// }
