package main

// https://leetcode.cn/problems/find-longest-awesome-substring/description/?envType=daily-question&envId=2024-05-20
// https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/

func longestAwesome(s string) (res int) {
	const N = 10
	pos := make([]int, 1<<N)
	n := len(s)
	for i := range pos {
		pos[i] = n
	}
	pos[0] = -1
	pre := 0
	for i, v := range s {
		pre ^= 1 << (v - '0')
		for j := 0; j < N; j++ {
			res = max(res, i-pos[pre^(1<<j)])
		}
		res = max(res, i-pos[pre])
		if pos[pre] == n {
			pos[pre] = i
		}
	}
	return
}
