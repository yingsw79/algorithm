package main

// https://leetcode.cn/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2024-01-09

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

type trie struct {
	root, p *node
}

func (tr *trie) query(c byte) bool {
	c -= 'a'
	if tr.p == nil || tr.p.next[c] == nil {
		tr.p = nil
		return false
	}
	tr.p = tr.p.next[c]
	return tr.p.isEnd
}

func minExtraChar(s string, dictionary []string) int {
	n := len(s)
	f := make([]int, n+1)
	root := &node{}
	for _, v := range dictionary {
		root.insert(v)
	}
	tr := &trie{root: root}

	for i := 1; i <= n; i++ {
		f[i] = i
		tr.p = root
		for j := i - 1; j >= 0; j-- {
			if tr.query(s[j]) { // trie 优化
				f[i] = min(f[i], f[j])
			} else {
				f[i] = min(f[i], f[j]+i-j)
			}
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
// 		f[i] = i
// 		for j := 0; j < i; j++ {
// 			if set[s[j:i]] { // trie 优化
// 				f[i] = min(f[i], f[j])
// 			} else {
// 				f[i] = min(f[i], f[j]+i-j)
// 			}
// 		}
// 	}
// 	return f[n]
// }
