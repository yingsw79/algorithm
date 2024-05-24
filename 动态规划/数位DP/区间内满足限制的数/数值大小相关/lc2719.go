package main

// https://leetcode.cn/problems/count-of-integers/description/?envType=daily-question&envId=2024-01-16

func count(num1 string, num2 string, min_sum int, max_sum int) int {
	const MOD int = 1e9 + 7
	f := make([][]int, len(num2))
	for i := range f {
		f[i] = make([]int, max_sum+1)
	}

	calc := func(s string) int {
		for _, r := range f {
			for i := range r {
				r[i] = -1
			}
		}

		var dfs func(int, int, bool, bool) int
		dfs = func(i, sum int, isLimit, isNum bool) (res int) {
			if i == len(s) {
				if isNum && sum >= min_sum {
					return 1
				}
				return 0
			}
			if isNum && !isLimit && f[i][sum] != -1 {
				return f[i][sum]
			}
			if !isNum {
				res = dfs(i+1, sum, false, false)
			}
			lo := 1
			if isNum {
				lo = 0
			}
			hi := 9
			if isLimit {
				hi = int(s[i] - '0')
			}
			for d := lo; d <= hi; d++ {
				if sum+d <= max_sum {
					res = (res + dfs(i+1, sum+d, isLimit && d == hi, true)) % MOD
				}
			}
			if isNum && !isLimit {
				f[i][sum] = res
			}
			return
		}

		return dfs(0, 0, true, false)
	}
	res := (calc(num2) - calc(num1) + MOD) % MOD
	sum := 0
	for _, v := range num1 {
		sum += int(v - '0')
	}
	if sum >= min_sum && sum <= max_sum {
		res++
	}
	return res % MOD
}
