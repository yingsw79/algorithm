package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://atcoder.jp/contests/abc362/tasks/abc362_e

const MOD int = 998244353

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		Fscan(in, &a[i])
	}
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, n)
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < i; j++ {
			f[2][j][i] = 1
		}
	}
	for l := 3; l <= n; l++ {
		for i := 0; i < n; i++ {
			for j := 0; j < i; j++ {
				for k := 0; k < j; k++ {
					if a[i]-a[j] == a[j]-a[k] {
						f[l][j][i] = (f[l][j][i] + f[l-1][k][j]) % MOD
					}
				}
			}
		}
	}
	Fprintf(out, "%d ", n)
	for l := 2; l <= n; l++ {
		s := 0
		for i := 0; i < n; i++ {
			for j := 0; j < i; j++ {
				s = (s + f[l][j][i]) % MOD
			}
		}
		Fprintf(out, "%d ", s)
	}
}

func main() { solve(os.Stdin, os.Stdout) }
