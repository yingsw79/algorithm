package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// https://www.acwing.com/problem/content/794/

func sub(a, b string) string {
	res := []byte{}
	t := 0
	for i, j := len(a)-1, len(b)-1; i >= 0; i-- {
		t = int(a[i]-'0') - t
		if j >= 0 {
			t -= int(b[j] - '0')
			j--
		}
		res = append(res, byte((t+10)%10)+'0')
		if t < 0 {
			t = 1
		} else {
			t = 0
		}
	}
	for len(res) > 1 && res[len(res)-1] == '0' {
		res = res[:len(res)-1]
	}
	// slices.Reverse(res)
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return string(res)
}

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var a, b string
	Fscan(in, &a, &b)
	if len(a) < len(b) || len(a) == len(b) && a < b {
		Fprint(out, "-")
		Fprint(out, sub(b, a))
	} else {
		Fprint(out, sub(a, b))
	}
}

func main() { solve(os.Stdin, os.Stdout) }
