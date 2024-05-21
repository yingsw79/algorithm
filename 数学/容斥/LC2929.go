package main

// https://leetcode.cn/problems/distribute-candies-among-children-ii/
// https://leetcode.cn/problems/distribute-candies-among-children-ii/solutions/2522969/o1-rong-chi-yuan-li-pythonjavacgo-by-end-2woj/

func c2(n int) int64 {
	if n < 2 {
		return 0
	}
	return int64(n) * int64(n-1) / 2
}

func distributeCandies(n int, limit int) int64 {
	return c2(n+2) - 3*c2(n-limit+1) + 3*c2(n-2*limit) - c2(n-3*limit-1)
}
