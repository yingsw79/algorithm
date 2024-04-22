package main

import "math/bits"

// https://leetcode.cn/problems/count-the-number-of-special-characters-ii/description/

// 对于大写英文字母：其二进制从右往左第 6 个比特值一定是 0。
// 对于小写英文字母：其二进制从右往左第 6 个比特值一定是 1。
// 对于任何英文字母：其小写字母二进制低 5 位，一定和其大写字母二进制低 5 位相等。

func numberOfSpecialChars(word string) int {
	var lower, upper, invalid uint
	for _, c := range word {
		bit := uint(1) << (c & 31)
		if c&32 > 0 { // 小写字母
			lower |= bit
			if upper&bit > 0 { // c 也在 upper 中
				invalid |= bit // 不合法
			}
		} else { // 大写字母
			upper |= bit
		}
	}
	// 从交集 lower & upper 中去掉不合法的字母 invalid
	return bits.OnesCount(lower & upper &^ invalid)
}
