#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/data-stream-as-disjoint-intervals/

class SummaryRanges {
    static const int N = 10010;
    int p[N];

public:
    SummaryRanges() {
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void addNum(int val) {
        if (p[val] == val) p[val] = find(val + 1);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (int i = 0; i < N; i++) {
            if (p[i] == i) continue;
            int r = find(i) - 1;
            res.push_back({i, r});
            i = r;
        }
        return res;
    }
};

int main() {
    return 0;
}

// const N int = 10010

// type SummaryRanges []int

// func (sr SummaryRanges) find(x int) int {
// 	if sr[x] == x {
// 		return x
// 	}
// 	sr[x] = sr.find(sr[x])
// 	return sr[x]
// }

// func Constructor() SummaryRanges {
// 	sr := make([]int, N)
// 	for i := range sr {
// 		sr[i] = i
// 	}
// 	return sr
// }

// func (sr SummaryRanges) AddNum(x int) {
// 	if sr[x] == x {
// 		sr[x] = sr.find(x + 1)
// 	}
// }

// func (sr SummaryRanges) GetIntervals() (res [][]int) {
// 	for i := 0; i < N; i++ {
// 		if sr[i] == i {
// 			continue
// 		}
// 		j := sr.find(i)
// 		res = append(res, []int{i, j - 1})
// 		i = j
// 	}
// 	return
// }