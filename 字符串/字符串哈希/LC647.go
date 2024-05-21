package main

// https://leetcode.cn/problems/palindromic-substrings/description/
// https://leetcode.cn/problems/shortest-palindrome/description/

func countSubstrings(s string) (res int) {
	const B = 131
	n := len(s)
	h1 := make([]uint64, n+1)
	h2 := make([]uint64, n+1)
	p := make([]uint64, n+1)
	p[0] = 1
	for i := 0; i < n; i++ {
		h1[i+1] = h1[i]*B + uint64(s[i])
		h2[i+1] = h2[i]*B + uint64(s[n-i-1])
		p[i+1] = p[i] * B
	}
	getHash := func(h []uint64, l, r int) uint64 {
		return h[r] - h[l-1]*p[r-l+1]
	}
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			if getHash(h1, i, j) == getHash(h2, n+1-j, n+1-i) {
				res++
			}
		}
	}
	return
}
