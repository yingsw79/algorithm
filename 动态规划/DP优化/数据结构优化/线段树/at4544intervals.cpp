#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://atcoder.jp/contests/dp/tasks/dp_w

const int N = 200010;
vector<PII> q[N];
int n, m;

struct Node {
    int l, r;
    LL val, add;
} tr[N * 4];  // 区间加查询最值

void pushup(int p) {
    tr[p].val = max(tr[p << 1].val, tr[p << 1 | 1].val);
}

void pushdown(int p) {
    auto &u = tr[p], &lt = tr[p << 1], &rt = tr[p << 1 | 1];
    if (u.add) {
        lt.val += u.add, rt.val += u.add;
        lt.add += u.add, rt.add += u.add;
        u.add = 0;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, 0, 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

void modify(int p, int l, int r, LL d) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].val += d, tr[p].add += d;
    } else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) modify(p << 1, l, r, d);
        if (r > mid) modify(p << 1 | 1, l, r, d);
        pushup(p);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0, l, r, w; i < m; ++i) {
        scanf("%d%d%d", &l, &r, &w);
        q[r].emplace_back(l, w);
    }

    build(1, 1, n);

    for (int i = 1; i <= n; ++i) {
        modify(1, i, i, max(tr[1].val, 0ll));
        for (auto& [l, w] : q[i]) modify(1, l, i, w);
    }

    printf("%lld\n", max(tr[1].val, 0ll));

    return 0;
}