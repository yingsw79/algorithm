package main

import (
	"strconv"
)

// https://leetcode.cn/problems/making-file-names-unique/

func getFolderNames(names []string) []string {
	res := make([]string, len(names))
	mp := map[string]int{}
	for i, v := range names {
		if mp[v] == 0 {
			res[i] = v
			mp[v]++
		} else {
			j := mp[v]
			for ; mp[v+"("+strconv.Itoa(j)+")"] != 0; j++ {
			}
			t := v + "(" + strconv.Itoa(j) + ")"
			res[i] = t
			mp[t]++
			mp[v] = j + 1
		}
	}
	return res
}
