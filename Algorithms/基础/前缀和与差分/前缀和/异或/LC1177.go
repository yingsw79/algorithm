package main

import "math/bits"

// https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
// https://leetcode.cn/problems/find-longest-awesome-substring/description/?envType=daily-question&envId=2024-05-20
// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

func canMakePaliQueries(s string, queries [][]int) []bool {
	sum := make([]int, len(s)+1)
	for i, v := range s {
		sum[i+1] = sum[i] ^ (1 << (v - 'a'))
	}
	res := make([]bool, len(queries))
	for i, q := range queries {
		res[i] = q[2] >= bits.OnesCount(uint(sum[q[1]+1]^sum[q[0]]))/2
	}
	return res
}
