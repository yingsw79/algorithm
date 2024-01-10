package main

// https://leetcode.cn/problems/reverse-pairs/description/

func mergeSort(nums []int) int {
	tmp := make([]int, len(nums))

	var merge func(int, int) int
	merge = func(l, r int) (res int) {
		if l >= r {
			return
		}

		mid := (l + r) >> 1
		res = merge(l, mid) + merge(mid+1, r)

		for i, j := mid+1, l; i <= r; i++ {
			for ; j <= mid && nums[i]*2 >= nums[j]; j++ {
			}
			if j > mid {
				break
			}
			res += mid - j + 1
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

		return
	}

	return merge(0, len(nums)-1)
}

func reversePairs(record []int) int {
	return mergeSort(record)
}
