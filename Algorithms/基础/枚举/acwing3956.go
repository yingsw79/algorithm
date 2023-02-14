package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const N int = 1e5 + 10

var a [N]int

// https://www.acwing.com/problem/content/3959/

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, res int
	fmt.Fscan(in, &n)

	sum := int64(0)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &a[i])
		sum += int64(a[i])
	}

	if sum%3 != 0 {
		fmt.Fprintln(out, 0)
		return
	}

	t := int64(sum / 3)

	sum = 0
	cnt := 0
	for i := 1; i < n; i++ {
		sum += int64(a[i])
		if sum == t*2 {
			res += cnt
		}
		if sum == t {
			cnt++
		}
	}

	fmt.Fprintln(out, res)
}

func main() { solve(os.Stdin, os.Stdout) }
