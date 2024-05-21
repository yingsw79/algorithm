package main

// https://leetcode.cn/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-04-23

func maxSatisfied(customers []int, grumpy []int, minutes int) (res int) {
	sum := 0
	for i, v := range customers {
		if grumpy[i] == 0 {
			sum += v
		}
	}
	var s1, s2 int
	for i, v := range customers {
		s1 += v
		if grumpy[i] == 0 {
			s2 += v
		}
		if i >= minutes {
			s1 -= customers[i-minutes]
			if grumpy[i-minutes] == 0 {
				s2 -= customers[i-minutes]
			}
		}
		if i >= minutes-1 {
			res = max(res, s1+sum-s2)
		}
	}
	return
}
