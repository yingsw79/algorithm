package main

// https://leetcode.cn/problems/design-add-and-search-words-data-structure/description/

type WordDictionary struct {
	next  [26]*WordDictionary
	isEnd bool
}

func Constructor() WordDictionary { return WordDictionary{} }

func (this *WordDictionary) AddWord(word string) {
	p := this
	for _, v := range word {
		v -= 'a'
		if p.next[v] == nil {
			p.next[v] = &WordDictionary{}
		}
		p = p.next[v]
	}
	p.isEnd = true
}

func (this *WordDictionary) Search(word string) bool {
	var dfs func(*WordDictionary, int) bool
	dfs = func(p *WordDictionary, i int) bool {
		for j := i; j < len(word); j++ {
			v := word[j]
			if v == '.' {
				for _, ne := range p.next {
					if ne != nil && dfs(ne, j+1) {
						return true
					}
				}
				return false
			}
			v -= 'a'
			if p.next[v] == nil {
				return false
			}
			p = p.next[v]
		}
		return p.isEnd
	}
	return dfs(this, 0)
}
