package main

// https://leetcode.cn/problems/design-linked-list/description/

type node struct {
	prev, next *node
	val        int
}

type MyLinkedList struct {
	dummy *node
	n     int
}

func Constructor() MyLinkedList {
	dummy := &node{}
	dummy.prev = dummy
	dummy.next = dummy
	return MyLinkedList{dummy: dummy}
}

func (this *MyLinkedList) Get(index int) int {
	if index >= this.n {
		return -1
	}
	p := this.dummy.next
	for ; index > 0; index-- {
		p = p.next
	}
	return p.val
}

func (this *MyLinkedList) add(p *node, val int) {
	x := &node{val: val}
	x.next = p.next
	x.prev = p
	x.next.prev = x
	x.prev.next = x
	this.n++
}

func (this *MyLinkedList) AddAtHead(val int) { this.add(this.dummy, val) }

func (this *MyLinkedList) AddAtTail(val int) { this.add(this.dummy.prev, val) }

func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if index > this.n {
		return
	}
	if index == this.n {
		this.AddAtTail(val)
		return
	}
	p := this.dummy
	for ; index > 0; index-- {
		p = p.next
	}
	this.add(p, val)
}

func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index >= this.n {
		return
	}
	p := this.dummy.next
	for ; index > 0; index-- {
		p = p.next
	}
	p.prev.next = p.next
	p.next.prev = p.prev
	p.next = nil
	p.prev = nil
	this.n--
}
