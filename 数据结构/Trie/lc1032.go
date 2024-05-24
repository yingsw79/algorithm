package main

// https://leetcode.cn/problems/stream-of-characters/

type StreamChecker struct {
	root   *trie
	stream []byte
}

func Constructor(words []string) StreamChecker {
	root := &trie{next: [26]*trie{}}
	for _, w := range words {
		root.insert(w)
	}
	return StreamChecker{root: root}
}

func (this *StreamChecker) Query(letter byte) bool {
	this.stream = append(this.stream, letter)
	return this.root.query(this.stream)
}

type trie struct {
	next  [26]*trie
	isEnd bool
}

func (t *trie) insert(word string) {
	p := t
	for i := len(word) - 1; i >= 0; i-- {
		c := word[i] - 'a'
		if p.next[c] == nil {
			p.next[c] = &trie{next: [26]*trie{}}
		}
		p = p.next[c]
	}
	p.isEnd = true
}

func (t *trie) query(bs []byte) bool {
	p := t
	for i := len(bs) - 1; i >= 0; i-- {
		c := bs[i] - 'a'
		if p.next[c] == nil {
			return false
		}
		p = p.next[c]
		if p.isEnd {
			return true
		}
	}
	return false
}
