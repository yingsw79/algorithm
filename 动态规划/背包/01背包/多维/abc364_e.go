package main

import (
	"bufio"
	. "fmt"
	"io"
	"math"
	"os"
)

// https://atcoder.jp/contests/abc364/tasks/abc364_e

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, x, y int
	Fscan(in, &n, &x, &y)

	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, x+1)
		for j := range f[i] {
			f[i][j] = math.MaxInt / 2
		}
	}
	f[0][0] = 0

	var a, b int
	for i := 1; i <= n; i++ {
		Fscan(in, &a, &b)
		for j := i; j >= 1; j-- {
			for k := x; k >= a; k-- {
				f[j][k] = min(f[j][k], f[j-1][k-a]+b)
			}
		}
	}

	for i := n - 1; i >= 0; i-- {
		for j := 0; j <= x; j++ {
			if f[i][j] <= y {
				Fprint(out, i+1)
				return
			}
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() { solve(os.Stdin, os.Stdout) }
