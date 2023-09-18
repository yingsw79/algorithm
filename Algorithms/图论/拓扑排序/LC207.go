package main

// https://leetcode.cn/problems/course-schedule/?envType=daily-question&envId=2023-09-09

func canFinish(numCourses int, prerequisites [][]int) bool {
	g := make([][]int, numCourses)
	indeg := make([]int, numCourses)
	for _, v := range prerequisites {
		a, b := v[0], v[1]
		g[b] = append(g[b], a)
		indeg[a]++
	}
	q := []int{}
	for i, v := range indeg {
		if v == 0 {
			q = append(q, i)
		}
	}
	cnt := 0
	for len(q) > 0 {
		tmp := q
		q = nil
		for _, u := range tmp {
			cnt++
			for _, v := range g[u] {
				indeg[v]--
				if indeg[v] == 0 {
					q = append(q, v)
				}
			}
		}
	}
	return cnt == numCourses
}
