package main

// https://leetcode.cn/problems/lru-cache/description/

type node struct {
	key, value int
	prev, next *node
}

type LRUCache struct {
	pos      map[int]*node
	dummy    *node
	capacity int
}

func Constructor(capacity int) LRUCache {
	// 循环双链表
	dummy := &node{}
	dummy.next = dummy
	dummy.prev = dummy
	return LRUCache{pos: map[int]*node{}, dummy: dummy, capacity: capacity}
}

func (this *LRUCache) Get(key int) int {
	x := this.get(key)
	if x != nil {
		return x.value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	x := this.get(key)
	if x != nil {
		x.value = value
		return
	}
	x = &node{key: key, value: value}
	this.pos[key] = x
	this.insert(x)
	if len(this.pos) > this.capacity {
		tail := this.dummy.prev // 循环双链表
		remove(tail)
		delete(this.pos, tail.key)
	}
}

func (this *LRUCache) get(key int) *node {
	x := this.pos[key]
	if x == nil {
		return nil
	}
	remove(x)
	this.insert(x)
	return x
}

func (this *LRUCache) insert(x *node) {
	x.next = this.dummy.next
	x.prev = this.dummy
	x.prev.next = x
	x.next.prev = x
}

func remove(x *node) {
	x.prev.next = x.next
	x.next.prev = x.prev
	x.prev = nil
	x.next = nil
}
