package main

// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/

func findKthLargest(nums []int, k int) int {
	n := len(nums)
	var qSort func(int, int) int
	qSort = func(l, r int) int {
		if l >= r {
			return nums[l]
		}
		i, j, x := l-1, r+1, nums[(l+r)>>1]
		for i < j {
			for i++; nums[i] < x; i++ {
			}
			for j--; nums[j] > x; j-- {
			}
			if i < j {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
		if n-k <= j {
			return qSort(l, j)
		}
		return qSort(j+1, r)
	}
	return qSort(0, n-1)
}
