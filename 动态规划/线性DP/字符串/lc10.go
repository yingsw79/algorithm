package main

// https://leetcode.cn/problems/regular-expression-matching/

func isMatch(s string, p string) bool {
	n, m := len(s), len(p)
	f := make([][]bool, n+1)
	for i := range f {
		f[i] = make([]bool, m+1)
	}
	f[0][0] = true
	for i, v := range p {
		if v == '*' {
			f[0][i+1] = f[0][i-1]
		}
	}
	for i, x := range s {
		for j, y := range p {
			if x == y || y == '.' {
				f[i+1][j+1] = f[i][j]
			} else if y == '*' {
				f[i+1][j+1] = f[i+1][j-1] // 匹配零次
				if byte(x) == p[j-1] || p[j-1] == '.' {
					f[i+1][j+1] = f[i+1][j+1] || f[i][j+1] // 匹配一次或多次
				}
			}
		}
	}
	return f[n][m]
}
