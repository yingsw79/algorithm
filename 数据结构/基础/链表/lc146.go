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
	nd := this.get(key)
	if nd != nil {
		return nd.value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	nd := this.get(key)
	if nd != nil {
		nd.value = value
		return
	}
	nd = &node{key: key, value: value}
	this.pos[key] = nd
	this.insert(nd)
	if len(this.pos) > this.capacity {
		tail := this.dummy.prev // 循环双链表
		remove(tail)
		delete(this.pos, tail.key)
	}
}

func (this *LRUCache) get(key int) *node {
	nd := this.pos[key]
	if nd == nil {
		return nil
	}
	remove(nd)
	this.insert(nd)
	return nd
}

func (this *LRUCache) insert(nd *node) {
	nd.next = this.dummy.next
	nd.prev = this.dummy
	nd.prev.next = nd
	nd.next.prev = nd
}

func remove(nd *node) {
	nd.prev.next = nd.next
	nd.next.prev = nd.prev
}
