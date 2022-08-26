#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-integers-in-intervals/

class CountIntervals {
    struct Node {
        int l, r, v;
        Node(int l, int r, int v) : l(l), r(r), v(v) {}
        bool operator<(const Node& a) const { return l < a.l; };
    };
    set<Node> tr;
    int cnt;

    auto split(int p) {
        auto it = tr.lower_bound(Node{p, 0, 0});
        if (it != tr.end() && it->l == p) return it;
        --it;
        int l = it->l, r = it->r, v = it->v;
        tr.erase(it);
        tr.emplace(l, p - 1, v);
        return tr.emplace(p, r, v).first;
    }

public:
    CountIntervals() {
        tr.emplace(1, 1e9, 0);
        cnt = 0;
    }

    void add(int left, int right) {  // 统计1的个数
        auto itr = split(right + 1), itl = split(left);
        for (; itl != itr; itl = tr.erase(itl)) {  // 边删边统计
            if (!itl->v) cnt += itl->r - itl->l + 1;
        }
        tr.emplace(left, right, 1);
    }

    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main() {
    return 0;
}