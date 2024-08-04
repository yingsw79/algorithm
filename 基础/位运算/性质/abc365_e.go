package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://atcoder.jp/contests/abc365/tasks/abc365_e

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	Fscan(in, &n)
	a := make([]int, n)
	var res, nor int
	for i := range a {
		var x int
		Fscan(in, &x)
		nor ^= x
		a[i] = nor
		res += nor
		res -= x
	}
	for i := 0; i < 31; i++ { //两两异或和
		var cnt0, cnt1 int
		for _, v := range a {
			if (v>>i)&1 > 0 {
				cnt1++
			} else {
				cnt0++
			}
		}
		res += (cnt0 * cnt1) << i
	}
	Fprint(out, res)
}

func main() { solve(os.Stdin, os.Stdout) }
