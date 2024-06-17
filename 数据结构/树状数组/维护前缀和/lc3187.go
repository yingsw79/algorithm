package main

// https://leetcode.cn/problems/peaks-in-array/description/

type BIT []int

func (b BIT) Update(x, v int) {
	for ; x < len(b); x += x & -x {
		b[x] += v
	}
}

func (b BIT) Query(x int) (res int) {
	for ; x > 0; x &= x - 1 {
		res += b[x]
	}
	return
}

func countOfPeaks(nums []int, queries [][]int) (res []int) {
	n := len(nums)
	st := make([]bool, n)
	tr := make(BIT, n+1)
	check := func(i int) bool { return nums[i] > nums[i-1] && nums[i] > nums[i+1] }
	for i := 1; i < n-1; i++ {
		if check(i) {
			tr.Update(i+1, 1)
			st[i] = true
		}
	}
	for _, q := range queries {
		if q[0] == 1 {
			l, r := q[1], q[2]
			if r < l+2 {
				res = append(res, 0)
			} else {
				res = append(res, tr.Query(r)-tr.Query(l+1))
			}
			continue
		}
		i, v := q[1], q[2]
		nums[i] = v
		for j := max(i-1, 1); j <= min(i+1, n-2); j++ {
			ok := check(j)
			if st[j] && !ok {
				tr.Update(j+1, -1)
			} else if !st[j] && ok {
				tr.Update(j+1, 1)
			}
			st[j] = ok
		}	
	}
	return
}
