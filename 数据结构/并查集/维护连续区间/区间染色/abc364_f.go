package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

// https://atcoder.jp/contests/abc364/tasks/abc364_f

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, q int
	Fscan(in, &n, &q)
	l := make([]int, q)
	r := make([]int, q)
	c := make([]int, q)
	for i := 0; i < q; i++ {
		Fscan(in, &l[i], &r[i], &c[i])
	}
	idx := make([]int, q)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return c[idx[i]] < c[idx[j]] })

	p := make([]int, n+2)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}

	res := 0
	for _, i := range idx {
		res += c[i]
		for j := find(l[i]); j < r[i]; j = find(j) {
			res += c[i]
			p[j] = find(j + 1)
		}
	}

	if find(1) < n {
		Fprint(out, -1)
	} else {
		Fprint(out, res)
	}
}

func main() { solve(os.Stdin, os.Stdout) }
