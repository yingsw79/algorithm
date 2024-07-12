package main

// https://leetcode.cn/problems/word-search-ii/description/

type node struct {
	next  [26]*node
	index int
}

func (nd *node) insert(s string, i int) {
	p := nd
	for _, v := range s {
		v -= 'a'
		if p.next[v] == nil {
			p.next[v] = &node{index: -1}
		}
		p = p.next[v]
	}
	p.index = i
}

func findWords(board [][]byte, words []string) (res []string) {
	m, n := len(board), len(board[0])
	dirs := []struct{ x, y int }{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}
	tr := &node{index: -1}
	for i, w := range words {
		tr.insert(w, i)
	}
	n1 := len(words)
	st := make([]bool, n1)
	var dfs func(int, int, *node)
	dfs = func(x, y int, p *node) {
		c := board[x][y]
		p = p.next[c-'a']
		if p == nil {
			return
		}
		board[x][y] = '.'
		if i := p.index; i != -1 && !st[i] {
			st[i] = true
			res = append(res, words[i])
		}
		for _, d := range dirs {
			nx, ny := x+d.x, y+d.y
			if nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '.' {
				dfs(nx, ny, p)
			}
		}
		board[x][y] = c
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if len(res) == n1 {
				return
			}
			dfs(i, j, tr)
		}
	}
	return
}
