package main

import (
	"strings"
	"unicode"
)

func strongPasswordCheckerII(password string) bool {
	n := len(password)
	if n < 8 {
		return false
	}

	var hasLower, hasUpper, hasDigit, hasSpecial bool
	for i, ch := range password {
		if i != n-1 && password[i] == password[i+1] {
			return false
		}
		if unicode.IsLower(ch) {
			hasLower = true
		} else if unicode.IsUpper(ch) {
			hasUpper = true
		} else if unicode.IsDigit(ch) {
			hasDigit = true
		} else if strings.ContainsRune("!@#$%^&*()-+", ch) {
			hasSpecial = true
		}
	}

	return hasLower && hasUpper && hasDigit && hasSpecial
}

func findingUsersActiveMinutes(logs [][]int, k int) []int {
	// mp := make(map[int]map[int]struct{})
	// mp := make(map[int]map[int]struct{}, len(logs))
	mp := map[int]map[int]struct{}{}
	for _, v := range logs {
		a, b := v[0], v[1]
		if mp[a] == nil {
			// mp[a] = make(map[int]struct{})
			mp[a] = map[int]struct{}{}
		}
		mp[a][b] = struct{}{}
	}
	res := make([]int, k)
	for _, v := range mp {
		res[len(v)-1]++
	}
	return res
}
