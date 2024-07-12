package main

import "slices"

// https://leetcode.cn/problems/add-strings/description/
// https://leetcode.cn/problems/add-binary/description/
// https://leetcode.cn/problems/plus-one

func addStrings(num1 string, num2 string) string {
	res := []byte{}
	for i, j, c := len(num1)-1, len(num2)-1, byte(0); i >= 0 || j >= 0 || c > 0; {
		if i >= 0 {
			c += num1[i] - '0'
			i--
		}
		if j >= 0 {
			c += num2[j] - '0'
			j--
		}
		res = append(res, c%10+'0')
		c /= 10
	}
	slices.Reverse(res)
	return string(res)
}
