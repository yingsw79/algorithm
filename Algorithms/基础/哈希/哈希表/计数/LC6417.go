package main

// https://leetcode.cn/problems/frequency-tracker/

type FrequencyTracker struct {
	cnt, freq map[int]int
}

func Constructor() FrequencyTracker {
	return FrequencyTracker{cnt: map[int]int{}, freq: map[int]int{}}
}

func (this *FrequencyTracker) Add(x int) {
	this.freq[this.cnt[x]]--
	this.cnt[x]++
	this.freq[this.cnt[x]]++
}

func (this *FrequencyTracker) DeleteOne(x int) {
	if this.cnt[x] == 0 {
		return
	}
	this.freq[this.cnt[x]]--
	this.cnt[x]--
	this.freq[this.cnt[x]]++
}

func (this *FrequencyTracker) HasFrequency(frequency int) bool {
	return this.freq[frequency] > 0
}
