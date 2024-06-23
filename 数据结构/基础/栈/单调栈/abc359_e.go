package main

// https://atcoder.jp/contests/abc359/tasks/abc359_e

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var N int
	fmt.Fscan(in, &N)
	H := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(in, &H[i])
	}
	res := make([]int, N)
	st := []int{}
	for i, v := range H {
		for len(st) > 0 && v > H[st[len(st)-1]] {
			st = st[:len(st)-1]
		}
		if len(st) > 0 {
			j := st[len(st)-1]
			res[i] = res[j] + (i-j)*v
		} else {
			res[i] = (i + 1) * v
		}
		st = append(st, i)
	}
	for _, v := range res {
		fmt.Fprintf(out, "%d ", v+1)
	}
}

func main() { solve(os.Stdin, os.Stdout) }
