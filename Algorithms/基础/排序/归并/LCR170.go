package main

// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/

func mergeSort(nums []int) int {
	tmp := make([]int, len(nums))

	var merge func(int, int) int
	merge = func(l, r int) (res int) {
		if l >= r {
			return
		}

		mid := (l + r) >> 1
		res = merge(l, mid) + merge(mid+1, r)
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
				res += mid - i + 1
			}
		}

		copy(tmp[k:], nums[i:mid+1])
		copy(tmp[k:], nums[j:r+1])
		copy(nums[l:], tmp[l:r+1])

		return
	}

	return merge(0, len(nums)-1)
}

func reversePairs(record []int) int {
	return mergeSort(record)
}
