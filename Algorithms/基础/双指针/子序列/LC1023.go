package main

import "unicode"

// https://leetcode.cn/problems/camelcase-matching/

func camelMatch(queries []string, pattern string) []bool {
	res := make([]bool, len(queries))
	for i, q := range queries {
		j := 0
		res[i] = true
		for _, c := range q {
			if j < len(pattern) && byte(c) == pattern[j] {
				j++
			} else if unicode.IsUpper(c) {
				res[i] = false
				break
			}
		}
		if j < len(pattern) {
			res[i] = false
		}
	}
	return res
}
