package main

import (
	"bufio"
	"bytes"
	. "fmt"
	"index/suffixarray"
	"io"
	"os"
	"sort"
	"unsafe"
)

// https://atcoder.jp/contests/abc362/tasks/abc362_g

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var _s string
	Fscan(in, &_s)
	s := []byte(_s)
	sa := (*struct {
		_  []byte
		sa []int32
	})(unsafe.Pointer(suffixarray.New(s))).sa

	var q int
	Fscan(in, &q)
	for n := len(sa); q > 0; q-- {
		var _t string
		Fscan(in, &_t)
		t := []byte(_t)

		l := sort.Search(n, func(i int) bool {
			suf := s[sa[i]:]
			if len(suf) > len(t) {
				suf = suf[:len(t)]
			}
			return bytes.Compare(suf, t) >= 0
		})

		r := sort.Search(n, func(i int) bool {
			suf := s[sa[i]:]
			if len(suf) > len(t) {
				suf = suf[:len(t)]
			}
			return bytes.Compare(suf, t) > 0
		})

		Fprintln(out, r-l)
	}
}

func main() { solve(os.Stdin, os.Stdout) }
