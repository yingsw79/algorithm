package main

// https://www.luogu.com.cn/problem/P2574
// https://leetcode.cn/problems/handling-sum-queries-after-update/

type Node struct {
	l, r, sum int
	lazy      bool
}

var (
	tr   []Node
	nums []int
)

func pushup(p int) {
	tr[p].sum = tr[p<<1].sum + tr[p<<1|1].sum
}

func pushdown(p int) {
	if tr[p].lazy {
		do(p << 1)
		do(p<<1 | 1)
		tr[p].lazy = false
	}
}

func do(p int) {
	t := &tr[p]
	t.sum = t.r - t.l + 1 - t.sum
	t.lazy = !t.lazy
}

func build(p, l, r int) {
	tr[p] = Node{l: l, r: r}
	if l == r {
		tr[p].sum = nums[l]
		return
	}
	mid := (l + r) >> 1
	build(p<<1, l, mid)
	build(p<<1|1, mid+1, r)
	pushup(p)
}

func update(p, l, r int) {
	if tr[p].l >= l && tr[p].r <= r {
		do(p)
		return
	}
	pushdown(p)
	mid := (tr[p].l + tr[p].r) >> 1
	if l <= mid {
		update(p<<1, l, r)
	}
	if r > mid {
		update(p<<1|1, l, r)
	}
	pushup(p)
}

func query(p, l, r int) (res int) {
	if tr[p].l >= l && tr[p].r <= r {
		return tr[p].sum
	}
	pushdown(p)
	mid := (tr[p].l + tr[p].r) >> 1
	if l <= mid {
		res += query(p<<1, l, r)
	}
	if r > mid {
		res += query(p<<1|1, l, r)
	}
	return
}

func handleQuery(nums1 []int, nums2 []int, queries [][]int) (res []int64) {
	n := len(nums1)
	tr = make([]Node, n*4)
	nums = nums1
	build(1, 0, n-1)
	sum := int64(0)
	for _, v := range nums2 {
		sum += int64(v)
	}
	for _, q := range queries {
		if q[0] == 1 {
			update(1, q[1], q[2])
		} else if q[0] == 2 {
			sum += int64(tr[1].sum) * int64(q[1])
		} else {
			res = append(res, sum)
		}
	}
	return
}
