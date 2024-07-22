package main

import "math/bits"

// https://leetcode.cn/problems/detonate-the-maximum-bombs/description/?envType=daily-question&envId=2024-07-22

func maximumDetonation(bombs [][]int) (res int) {
	n := len(bombs)
	f := make([]Bitset, n)
	for i, b1 := range bombs {
		f[i] = make(Bitset, n)
		for j, b2 := range bombs {
			dx := b1[0] - b2[0]
			dy := b1[1] - b2[1]
			if dx*dx+dy*dy <= b1[2]*b1[2] {
				f[i].Set(j)
			}
		}
	}
	for i, fi := range f {
		for _, fj := range f {
			if fj.Has(i) {
				fj.Or(fi)
			}
		}
	}
	for _, x := range f {
		res = max(res, x.OnesCount())
	}
	return
}

const w = bits.UintSize

type Bitset []uint

func NewBitset(n int) Bitset    { return make(Bitset, (n+w-1)/w) }
func (b Bitset) Set(x int)      { b[x/w] |= 1 << (x % w) }
func (b Bitset) Has(x int) bool { return b[x/w]&(1<<(x%w)) > 0 }
func (b Bitset) Or(bs Bitset) {
	for i, v := range bs {
		b[i] |= v
	}
}
func (b Bitset) OnesCount() (res int) {
	for _, v := range b {
		res += bits.OnesCount(v)
	}
	return
}
