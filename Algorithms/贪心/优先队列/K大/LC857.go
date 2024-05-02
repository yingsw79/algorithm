package main

import (
	"container/heap"
	"slices"
	"sort"
)

type Pq struct{ sort.IntSlice }

func (p Pq) Less(i, j int) bool { return p.IntSlice[i] > p.IntSlice[j] }
func (p *Pq) Push(any)          {}
func (p *Pq) Pop() (_ any)      { return }

func mincostToHireWorkers(quality []int, wage []int, k int) float64 {
	idx := make([]int, len(quality))
	for i := range idx {
		idx[i] = i
	}
	slices.SortFunc(idx, func(i, j int) int { return wage[i]*quality[j] - wage[j]*quality[i] })
	sum := 0
	pq := &Pq{make(sort.IntSlice, k)}
	for i, v := range idx[:k] {
		sum += quality[v]
		pq.IntSlice[i] = quality[v]
	}
	heap.Init(pq)
	res := float64(sum*wage[idx[k-1]]) / float64(quality[idx[k-1]])
	for _, i := range idx[k:] {
		if quality[i] < pq.IntSlice[0] {
			sum -= pq.IntSlice[0] - quality[i]
			pq.IntSlice[0] = quality[i]
			heap.Fix(pq, 0)
			res = min(res, float64(sum*wage[i])/float64(quality[i]))
		}
	}
	return res
}
