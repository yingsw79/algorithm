package main

// https://leetcode.cn/problems/dice-roll-simulation/

func dieSimulator(n int, rollMax []int) (res int) {
	const MOD int = 1e9 + 7
	f := [2][6][16]int{}
	for i := 0; i < 6; i++ {
		f[1][i][1] = 1
	}
	for i := 2; i <= n; i++ {
		t := i & 1
		for j := 0; j < 6; j++ {
			f[t][j][1] = 0
			for k, v := range rollMax {
				if k != j {
					for u := 1; u <= v; u++ {
						f[t][j][1] = (f[t][j][1] + f[t^1][k][u]) % MOD
					}
				} else {
					for u := 2; u <= v; u++ {
						f[t][j][u] = f[t^1][j][u-1]
					}
				}
			}
		}
	}
	for i, v := range rollMax {
		for j := 1; j <= v; j++ {
			res = (res + f[n&1][i][j]) % MOD
		}
	}
	return
}
