package main

import (
	"bufio"
	. "fmt"
	"os"
)

// https://atcoder.jp/contests/abc366/tasks/abc366_d

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, q int
	Fscan(in, &n)
	a := make([][][]int, n+1)
	sum := make([][][]int, n+1)
	for i := 0; i <= n; i++ {
		a[i] = make([][]int, n+1)
		sum[i] = make([][]int, n+1)
		for j := 0; j <= n; j++ {
			a[i][j] = make([]int, n+1)
			sum[i][j] = make([]int, n+1)
		}
	}

	for x := 1; x <= n; x++ {
		for y := 1; y <= n; y++ {
			for z := 1; z <= n; z++ {
				Fscan(in, &a[x][y][z])
			}
		}
	}

	for x := 1; x <= n; x++ {
		for y := 1; y <= n; y++ {
			for z := 1; z <= n; z++ {
				sum[x][y][z] = a[x][y][z] +
					sum[x-1][y][z] +
					sum[x][y-1][z] +
					sum[x][y][z-1] -
					sum[x-1][y-1][z] -
					sum[x-1][y][z-1] -
					sum[x][y-1][z-1] +
					sum[x-1][y-1][z-1]
			}
		}
	}

	Fscan(in, &q)
	for i := 0; i < q; i++ {
		var lx, rx, ly, ry, lz, rz int
		Fscan(in, &lx, &rx, &ly, &ry, &lz, &rz)
		res := sum[rx][ry][rz] -
			sum[lx-1][ry][rz] -
			sum[rx][ly-1][rz] -
			sum[rx][ry][lz-1] +
			sum[lx-1][ly-1][rz] +
			sum[lx-1][ry][lz-1] +
			sum[rx][ly-1][lz-1] -
			sum[lx-1][ly-1][lz-1]
		Fprintln(out, res)
	}
}
