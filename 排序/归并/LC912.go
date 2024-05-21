package main

// https://leetcode.cn/problems/sort-an-array/description/

func mergeSort(nums []int) {
	tmp := make([]int, len(nums))

	var merge func(int, int)
	merge = func(l, r int) {
		if l >= r {
			return
		}

		mid := (l + r) >> 1
		merge(l, mid)
		merge(mid+1, r)
		if nums[mid] <= nums[mid+1] {
			return
		}

		i, j, k := l, mid+1, l
		for ; i <= mid && j <= r; k++ {
			if nums[i] <= nums[j] {
				tmp[k] = nums[i]
				i++
			} else {
				tmp[k] = nums[j]
				j++
			}
		}

		copy(tmp[k:], nums[i:mid+1])
		copy(tmp[k:], nums[j:r+1])
		copy(nums[l:], tmp[l:r+1])
	}

	merge(0, len(nums)-1)
}

func sortArray(nums []int) []int {
	mergeSort(nums)
	return nums
}
