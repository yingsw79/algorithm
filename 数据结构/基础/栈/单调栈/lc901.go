package main

import "math"

// https://leetcode.cn/problems/online-stock-span/description/?envType=daily-question&envId=2023-10-07

type pair struct {
	day   int
	price int
}

type StockSpanner struct {
	stack  []pair
	curDay int
}

func Constructor() StockSpanner {
	return StockSpanner{[]pair{{-1, math.MaxInt}}, -1}
}

func (s *StockSpanner) Next(price int) int {
	for price >= s.stack[len(s.stack)-1].price {
		s.stack = s.stack[:len(s.stack)-1]
	}
	s.curDay++
	s.stack = append(s.stack, pair{s.curDay, price})
	return s.curDay - s.stack[len(s.stack)-2].day
}
