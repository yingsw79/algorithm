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

class CountIntervals {
    map<int, int> m;
    int cnt = 0;  // 所有区间长度和

public:
    CountIntervals() {}

    void add(int left, int right) {
        // 遍历所有被 [left,right] 覆盖到的区间（部分覆盖也算）
        for (auto it = m.lower_bound(left); it != m.end() && it->second <= right; m.erase(it++)) {
            int l = it->second, r = it->first;
            left = min(left, l);    // 合并后的新区间，其左端点为所有被覆盖的区间的左端点的最小值
            right = max(right, r);  // 合并后的新区间，其右端点为所有被覆盖的区间的右端点的最大值
            cnt -= r - l + 1;
        }
        cnt += right - left + 1;
        m[right] = left;  // 所有被覆盖到的区间与 [left,right] 合并成一个新区间
    }

    int count() { return cnt; }
};

int main() {
    return 0;
}