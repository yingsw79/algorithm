package main

// https://leetcode.cn/problems/sort-an-array/description/

func qSort(nums []int, l, r int) {
	if l >= r {
		return
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

	qSort(nums, l, j)
	qSort(nums, j+1, r)
}

func sortArray(nums []int) []int {
	qSort(nums, 0, len(nums)-1)
	return nums
}
