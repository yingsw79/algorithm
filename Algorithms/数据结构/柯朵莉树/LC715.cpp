#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/range-module/

class RangeModule {
    struct Node {
        int l, r;
        mutable int v;
        Node(int _l, int _r, int _v) : l(_l), r(_r), v(_v) {}
        bool operator<(const Node& a) const {
            return l < a.l;
        }
    };
    set<Node> tr;

    auto split(int p) {
        auto it = tr.lower_bound(Node{p, 0, 0});
        if (it != tr.end() && it->l == p) return it;
        --it;
        int l = it->l, r = it->r, v = it->v;
        tr.erase(it);
        tr.emplace(l, p - 1, v);
        return tr.emplace(p, r, v).first;
    }

    void assign(int l, int r, int v) {
        auto itr = split(r + 1), itl = split(l);
        tr.erase(itl, itr);
        tr.emplace(l, r, v);
    }

    bool check(int l, int r) {
        auto itr = split(r + 1), itl = split(l);
        for (; itl != itr; ++itl) {
            if (itl->v == 0) return false;
        }
        return true;
    }

public:
    RangeModule() {
        tr.emplace(1, 1e9, 0);
    }

    void addRange(int left, int right) {
        assign(left, right - 1, 1);
    }

    bool queryRange(int left, int right) {
        return check(left, right - 1);
    }

    void removeRange(int left, int right) {
        assign(left, right - 1, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

int main() {
    return 0;
}