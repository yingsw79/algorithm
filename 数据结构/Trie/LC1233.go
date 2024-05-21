package main

import (
	"strings"
)

// https://leetcode.cn/problems/remove-sub-folders-from-the-filesystem/

type Trie struct {
	Next  map[string]*Trie
	Index int
}

func NewTrie() *Trie {
	return &Trie{Next: map[string]*Trie{}, Index: -1}
}

func (tr *Trie) Insert(i int, words []string) {
	p := tr
	for _, w := range words {
		if p.Next[w] == nil {
			p.Next[w] = NewTrie()
		}
		p = p.Next[w]
	}
	p.Index = i
}

func removeSubfolders(folder []string) (res []string) {
	tr := NewTrie()
	for i, v := range folder {
		tr.Insert(i, strings.Split(v[1:], "/"))
	}
	var dfs func(*Trie)
	dfs = func(p *Trie) {
		if p.Index != -1 {
			res = append(res, folder[p.Index])
			return
		}
		for _, t := range p.Next {
			dfs(t)
		}
	}
	dfs(tr)
	return
}
