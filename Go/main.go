package main

import (
	"container/heap"
	"math"
	"sort"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Pq struct{ sort.IntSlice }

func (h Pq) Less(i, j int) bool  { return h.IntSlice[i] > h.IntSlice[j] } // 加上这行变成最大堆
func (h *Pq) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *Pq) Pop() interface{} {
	a := h.IntSlice
	n := len(a)
	v := a[n-1]
	h.IntSlice = a[:n-1]
	return v
}
func (h *Pq) push(v int) { heap.Push(h, v) }
func (h *Pq) pop() int   { return heap.Pop(h).(int) } // 稍微封装一下，方便使用

func PickGifts(gifts []int, k int) (res int64) {
	pq := &Pq{gifts}
	heap.Init(pq)
	for i := 0; i < k; i++ {
		t := pq.pop()
		pq.push(int(math.Sqrt(float64(t))))
	}
	for _, v := range gifts {
		res += int64(v)
	}
	return
}

// func specialPerm(nums []int) int {

// }


