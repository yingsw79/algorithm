package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://www.acwing.com/problem/content/796/

func div(a string, b int) (string, int) {
	res := []byte{}
	r := 0
	for i := 0; i < len(a); i++ {
		r = r*10 + int(a[i]-'0')
		res = append(res, byte(r/b)+'0')
		r %= b
	}
	for len(res) > 1 && res[0] == '0' {
		res = res[1:]
	}
	return string(res), r
}

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var a string
	var b int
	Fscan(in, &a, &b)
	q, r := div(a, b)
	Fprint(out, q, "\n", r)
}

func main() { solve(os.Stdin, os.Stdout) }
