package main

import (
	"math"
	"sort"
)

// https://leetcode.cn/problems/minimum-time-to-repair-cars/

func repairCars(ranks []int, cars int) int64 {
	minR := ranks[0]
	for _, r := range ranks {
		if r < minR {
			minR = r
		}
	}
	return int64(sort.Search(minR*cars*cars, func(t int) bool {
		s := 0
		for _, r := range ranks {
			s += int(math.Sqrt(float64(t / r)))
		}
		return s >= cars
	}))
}
