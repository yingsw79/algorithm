package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://atcoder.jp/contests/abc365/tasks/abc365_d

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)
	var s string
	Fscan(in, &s)

	f := make([][3]int, n+1)
	res := 0
	for i := 0; i < n; i++ {
		switch s[i] {
		case 'R':
			f[i+1][0] = max(f[i][1], f[i][2])
			f[i+1][1] = max(f[i][0], f[i][2]) + 1
		case 'P':
			f[i+1][1] = max(f[i][0], f[i][2])
			f[i+1][2] = max(f[i][0], f[i][1]) + 1
		case 'S':
			f[i+1][2] = max(f[i][0], f[i][1])
			f[i+1][0] = max(f[i][1], f[i][2]) + 1
		}
	}
	res = max(res, f[n][0])
	res = max(res, f[n][1])
	res = max(res, f[n][2])
	Fprint(out, res)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() { solve(os.Stdin, os.Stdout) }
