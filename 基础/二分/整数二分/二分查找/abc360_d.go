package main

// https://atcoder.jp/contests/abc360/tasks/abc360_d

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, t int
	fmt.Fscan(in, &n, &t)
	var s string
	fmt.Fscan(in, &s)
	a := make([]int, n)
	pos := []int{}
	for i := range a {
		fmt.Fscan(in, &a[i])
		if s[i] == '0' {
			pos = append(pos, a[i])
		}
	}
	sort.Ints(pos)
	res := 0
	for i, v := range a {
		if s[i] == '1' {
			res += sort.SearchInts(pos, v+t*2+1) - sort.SearchInts(pos, v)
		}
	}
	fmt.Fprint(out, res)
}

func main() { solve(os.Stdin, os.Stdout) }
