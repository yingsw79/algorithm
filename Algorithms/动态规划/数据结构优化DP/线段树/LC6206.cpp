#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-increasing-subsequence-ii/

class Solution {
    static const int N = 100010;

    struct Node {
        int l, r, v;
    } tr[N * 4];

    void build(int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) return;
        int mid = l + r >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    }

    void update(int p, int x, int v) {
        if (tr[p].l == tr[p].r)
            tr[p].v = max(tr[p].v, v);
        else {
            int mid = tr[p].l + tr[p].r >> 1;
            if (x <= mid)
                update(p << 1, x, v);
            else
                update(p << 1 | 1, x, v);
            tr[p].v = max(tr[p << 1].v, tr[p << 1 | 1].v);
        }
    }

    int query(int p, int l, int r) {
        if (tr[p].l >= l && tr[p].r <= r) return tr[p].v;
        int mid = tr[p].l + tr[p].r >> 1;
        int res = 0;
        if (l <= mid) res = query(p << 1, l, r);
        if (r > mid) res = max(res, query(p << 1 | 1, l, r));
        return res;
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        build(1, 1, N);
        int res = 0;
        for (int x : nums) {
            int t = query(1, max(x - k, 1), x - 1) + 1;
            res = max(res, t);
            update(1, x, t);
        }
        return res;
    }
};

int main() {
    return 0;
}