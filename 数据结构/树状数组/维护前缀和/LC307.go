package main

// https://leetcode.cn/problems/range-sum-query-mutable/description/?envType=daily-question&envId=2023-11-13

type NumArray struct {
	nums, tr []int
}

func Constructor(nums []int) NumArray {
	tr := make([]int, len(nums)+1)
	for i, v := range nums {
		i++
		tr[i] += v
		if j := i + i&-i; j < len(tr) { // O(n)建树
			tr[j] += tr[i]
		}
	}
	return NumArray{nums: nums, tr: tr}
}

func (this *NumArray) Update(x int, v int) {
	this.add(x+1, v-this.nums[x])
	this.nums[x] = v
}

func (this *NumArray) SumRange(left int, right int) int {
	return this.query(right+1) - this.query(left)
}

func (this *NumArray) add(x int, v int) {
	for ; x < len(this.tr); x += x & -x {
		this.tr[x] += v
	}
}

func (this *NumArray) query(x int) (res int) {
	for ; x > 0; x &= x - 1 {
		res += this.tr[x]
	}
	return
}
