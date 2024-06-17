package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// https://atcoder.jp/contests/abc358/tasks/abc358_e

const MOD int = 998244353

const N int = 1010

var fact, infact [N]int

func init() {
	fact[0] = 1
	infact[0] = 1
	for i := 1; i < N; i++ {
		fact[i] = fact[i-1] * i % MOD
		infact[i] = infact[i-1] * pow(i, MOD-2, MOD) % MOD
	}
}

func pow(a, b, p int) int {
	res := 1
	for ; b != 0; b >>= 1 {
		if b&1 == 1 {
			res = (res * a) % p
		}
		a = a * a % p
	}
	return res
}

func comb(n, k int) int { return fact[n] * infact[k] % MOD * infact[n-k] % MOD }

func min(a, b int) int { if a < b { return a }; return b }

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var K int
	fmt.Fscan(in, &K)

	C := make([]int, 26)
	for i := range C {
		fmt.Fscan(in, &C[i])
	}

	// f := make([][]int, 27)
	// for i := range f {
	// 	f[i] = make([]int, K+1)
	// }
	// f[0][0] = 1

	// for i := 1; i <= 26; i++ {
	// 	for j := 0; j <= K; j++ {
	// 		for k := 0; k <= min(C[i-1], j); k++ {
	// 			f[i][j] = (f[i][j] + f[i-1][j-k]*comb(j, k)) % MOD
	// 		}
	// 	}
	// }

	// res := 0
	// for j := 1; j <= K; j++ {
	// 	res = (res + f[26][j]) % MOD
	// }

	f := make([]int, K+1)
	f[0] = 1

	for i := 1; i <= 26; i++ {
		for j := K; j >= 1; j-- {
			for k := 1; k <= min(C[i-1], j); k++ {
				f[j] = (f[j] + f[j-k]*comb(j, k)) % MOD
			}
		}
	}

	res := 0
	for j := 1; j <= K; j++ {
		res = (res + f[j]) % MOD
	}

	fmt.Fprintln(out, res)
}

func main() { solve(os.Stdin, os.Stdout) }
