package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strings"
)

// https://atcoder.jp/contests/abc361/tasks/abc361_d

func solve(in io.Reader, out io.Writer) {
	var n int
	var s, t string
	Fscan(in, &n, &s, &t)
	res := 0
	if s == t {
		Fprint(out, res)
		return
	}
	res++
	s += ".."
	t += ".."
	st := map[string]bool{s: true}
	q := []string{s}
	for ; len(q) > 0; res++ {
		tmp := q
		q = nil
		for _, x := range tmp {
			i := strings.Index(x, "..")
			for j := 0; j < n+1; j++ {
				if j == i || j == i-1 || j == i+1 {
					continue
				}
				b := []byte(x)
				b[i] = x[j]
				b[i+1] = x[j+1]
				b[j] = '.'
				b[j+1] = '.'
				y := string(b)
				if y == t {
					Fprint(out, res)
					return
				}
				if !st[y] {
					q = append(q, y)
					st[y] = true
				}
			}
		}
	}
	Fprint(out, -1)
}

func main() { solve(bufio.NewReader(os.Stdin), os.Stdout) }
