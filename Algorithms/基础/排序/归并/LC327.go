package main

// https://leetcode.cn/problems/count-of-range-sum/description/

func mergeSort(nums []int, lower, upper int) int {
	tmp := make([]int, len(nums))

	var merge func(int, int) int
	merge = func(l, r int) (res int) {
		if l >= r {
			return
		}

		mid := (l + r) >> 1
		res = merge(l, mid) + merge(mid+1, r)

		for k, i, j := l, mid+1, mid+1; k <= mid; k++ {
			for ; j <= r && nums[j]-nums[k] < lower; j++ {
			}
			for ; i <= r && nums[i]-nums[k] <= upper; i++ {
			}
			res += i - j
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

func countRangeSum(nums []int, lower int, upper int) int {
	sum := make([]int, len(nums)+1)
	for i, v := range nums {
		sum[i+1] = sum[i] + v
	}
	return mergeSort(sum, lower, upper)
}
