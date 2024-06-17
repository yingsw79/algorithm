package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

// https://atcoder.jp/contests/abc358/tasks/abc358_g

const N int = 55

var (
	A    [N][N]int
	f    [N][N][N * N]int
	dirs = []struct{ i, j int }{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}
)

func max(a, b int) int { if a > b { return a }; return b }
func min(a, b int) int { if a < b { return a }; return b }

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var H, W, K int
	fmt.Fscan(in, &H, &W, &K)

	var Si, Sj int
	fmt.Fscan(in, &Si, &Sj)

	for i := 1; i <= H; i++ {
		for j := 1; j <= W; j++ {
			fmt.Fscan(in, &A[i][j])
			for k := 0; k <= H*W; k++ {
				f[i][j][k] = math.MinInt
			}
		}
	}
	f[Si][Sj][0] = 0

	res := 0
	for k := 1; k <= min(H*W, K); k++ {
		for i := 1; i <= H; i++ {
			for j := 1; j <= W; j++ {
				f[i][j][k] = f[i][j][k-1]
				for _, d := range dirs {
					a, b := i+d.i, j+d.j
					if a >= 1 && a <= H && b >= 1 && b <= W {
						f[i][j][k] = max(f[i][j][k], f[a][b][k-1])
					}
				}
				f[i][j][k] += A[i][j]
				res = max(res, f[i][j][k]+(K-k)*A[i][j])
			}
		}
	}

	fmt.Fprint(out, res)
}

func main() { solve(os.Stdin, os.Stdout) }
