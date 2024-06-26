package main

// https://leetcode.cn/problems/implement-magic-dictionary/description/

type MagicDictionary struct {
	next  [26]*MagicDictionary
	isEnd bool
}

func Constructor() MagicDictionary { return MagicDictionary{} }

func (this *MagicDictionary) BuildDict(dictionary []string) {
	for _, word := range dictionary {
		p := this
		for _, v := range word {
			v -= 'a'
			if p.next[v] == nil {
				p.next[v] = &MagicDictionary{}
			}
			p = p.next[v]
		}
		p.isEnd = true
	}
}

func (this *MagicDictionary) Search(searchWord string) bool {
	var dfs func(*MagicDictionary, int, bool) bool
	dfs = func(p *MagicDictionary, i int, replaced bool) bool {
		if i == len(searchWord) {
			return p.isEnd && replaced
		}
		c := searchWord[i] - 'a'
		if p.next[c] != nil && dfs(p.next[c], i+1, replaced) {
			return true
		}
		if !replaced {
			for j, ne := range p.next {
				if c != byte(j) && ne != nil && dfs(ne, i+1, true) {
					return true
				}
			}
		}
		return false
	}
	return dfs(this, 0, false)
}
