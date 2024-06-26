package main

// https://leetcode.cn/problems/design-circular-deque/description/

type MyCircularDeque struct {
	l, r int
	q    []int
}

func Constructor(k int) MyCircularDeque { return MyCircularDeque{q: make([]int, k+1)} }

func (this *MyCircularDeque) InsertFront(value int) bool {
	if this.IsFull() {
		return false
	}
	this.l = (this.l - 1 + len(this.q)) % len(this.q)
	this.q[this.l] = value
	return true
}

func (this *MyCircularDeque) InsertLast(value int) bool {
	if this.IsFull() {
		return false
	}
	this.q[this.r] = value
	this.r = (this.r + 1) % len(this.q)
	return true
}

func (this *MyCircularDeque) DeleteFront() bool {
	if this.IsEmpty() {
		return false
	}
	this.l = (this.l + 1) % len(this.q)
	return true
}

func (this *MyCircularDeque) DeleteLast() bool {
	if this.IsEmpty() {
		return false
	}
	this.r = (this.r - 1 + len(this.q)) % len(this.q)
	return true
}

func (this *MyCircularDeque) GetFront() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[this.l]
}

func (this *MyCircularDeque) GetRear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[(this.r-1+len(this.q))%len(this.q)]
}

func (this *MyCircularDeque) IsEmpty() bool { return this.l == this.r }

func (this *MyCircularDeque) IsFull() bool { return (this.r+1)%len(this.q) == this.l }
