package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

// https://atcoder.jp/contests/abc364/tasks/abc364_d

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, q int
	Fscan(in, &n, &q)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &a[i])
	}
	sort.Ints(a)
	for ; q > 0; q-- {
		var b, k int
		Fscan(in, &b, &k)
		res := sort.Search(1e9, func(mid int) bool {
			return sort.SearchInts(a, b+mid+1)-sort.SearchInts(a, b-mid) >= k
		})
		Fprintln(out, res)
	}
}

func main() { solve(os.Stdin, os.Stdout) }
