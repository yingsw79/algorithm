package main

// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/

func findSubstring(s string, words []string) (res []int) {
	const B = 131
	n1 := len(s)
	n2 := len(words)
	w := len(words[0])
	m := n2 * w
	if n1 < m {
		return
	}
	h := make([]uint64, n1+1)
	p := make([]uint64, w+1)
	cnt0 := map[uint64]int{}
	p[0] = 1
	for i := 1; i <= w; i++ {
		p[i] = p[i-1] * B
	}
	for i := 1; i <= n1; i++ {
		h[i] = h[i-1]*B + uint64(s[i-1]-'a'+1)
	}
	getHash := func(l, r int) uint64 { return h[r] - h[l-1]*p[r-l+1] }
	for _, w := range words {
		x := uint64(0)
		for _, v := range w {
			x = x*B + uint64(v-'a'+1)
		}
		cnt0[x]++
	}
	// O(n1)
	for i := 1; i <= w; i++ { // O(w)
		t := 0
		cnt := map[uint64]int{}
		for j := i; j+w-1 <= n1; j += w { // O(n1/w)
			x := getHash(j, j+w-1)
			cnt[x]++
			if cnt[x] <= cnt0[x] {
				t++
			}
			if j >= i+m {
				x := getHash(j-m, j-m+w-1)
				cnt[x]--
				if cnt[x] < cnt0[x] {
					t--
				}
			}
			if t == n2 {
				res = append(res, j-m+w-1)
			}
		}
	}
	return
}
