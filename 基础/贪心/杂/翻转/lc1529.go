package main

// https://leetcode.cn/problems/minimum-suffix-flips/description/
// https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
// https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
// https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/description/

func minFlips(target string) (res int) {
	for _, v := range target {
		if int(v-'0') != res%2 {
			res++
		}
	}
	return
}
