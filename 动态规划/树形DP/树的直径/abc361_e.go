package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://atcoder.jp/contests/abc361/tasks/abc361_e

func solve(in io.Reader, out io.Writer) {
	var n int
	Fscan(in, &n)
	type pair struct{ v, w int }
	g := make([][]pair, n+1)
	s := 0
	var a, b, c int
	for i := 0; i < n-1; i++ {
		Fscan(in, &a, &b, &c)
		g[a] = append(g[a], pair{b, c})
		g[b] = append(g[b], pair{a, c})
		s += c
	}
	d := make([]int, n+1)
	mx := 0
	var dfs func(int, int)
	dfs = func(u, fa int) {
		for _, p := range g[u] {
			if v := p.v; v != fa {
				dfs(v, u)
				mx = max(mx, d[u]+d[v]+p.w)
				d[u] = max(d[u], d[v]+p.w)
			}
		}
	}
	dfs(1, 0)
	Fprint(out, s*2-mx)
}

func max(a, b int) int { if a > b { return a }; return b }

func main() { solve(bufio.NewReader(os.Stdin), os.Stdout) }
