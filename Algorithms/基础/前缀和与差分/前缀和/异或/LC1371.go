package main

// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
// https://leetcode.cn/problems/can-make-palindrome-from-substring/description/
// https://leetcode.cn/problems/find-longest-awesome-substring/description/?envType=daily-question&envId=2024-05-20

func findTheLongestSubstring(s string) (res int) {
	pos := make([]int, 1<<5)
	n := len(s)
	for i := range pos {
		pos[i] = n
	}
	pos[0] = -1
	pre := 0
	for i, v := range s {
		switch v {
		case 'a':
			pre ^= 1
		case 'e':
			pre ^= 2
		case 'i':
			pre ^= 4
		case 'o':
			pre ^= 8
		case 'u':
			pre ^= 16
		}
		res = max(res, i-pos[pre])
		if pos[pre] == n {
			pos[pre] = i
		}
	}
	return
}
