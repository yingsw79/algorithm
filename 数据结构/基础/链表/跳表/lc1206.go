package main

// https://leetcode.cn/problems/design-skiplist/description/

import "math/rand"

const level int = 8

type Skiplist struct {
	next [level]*Skiplist
	val  int
}

func Constructor() (s Skiplist) { return }

func (this *Skiplist) find(target int) []*Skiplist {
	pre := [level]*Skiplist{}
	p := this
	for i := level - 1; i >= 0; i-- {
		for ; p.next[i] != nil && p.next[i].val < target; p = p.next[i] {
		}
		pre[i] = p
	}
	return pre[:]
}

func (this *Skiplist) Search(target int) bool {
	pre := this.find(target)
	p := pre[0].next[0]
	return p != nil && p.val == target
}

func (this *Skiplist) Add(num int) {
	pre := this.find(num)
	x := &Skiplist{val: num}
	for i := 0; i < level; i++ {
		x.next[i] = pre[i].next[i]
		pre[i].next[i] = x
		if rand.Int31()%2 > 0 {
			break
		}
	}
}

func (this *Skiplist) Erase(num int) bool {
	pre := this.find(num)
	p := pre[0].next[0]
	if p == nil || p.val != num {
		return false
	}
	for i := 0; i < level && pre[i].next[i] == p; i++ {
		pre[i].next[i] = p.next[i]
	}
	clear(p.next[:])
	return true
}
