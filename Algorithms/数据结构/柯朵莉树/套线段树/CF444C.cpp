#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// https://codeforces.com/contest/444/problem/C

const int N = 100010;
int n, m;

namespace seg {
struct Node {
    int l, r;
    LL sum, add;
} tr[N * 4];

void pushup(int p) {
    tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
}

void pushdown(int p) {
    auto &u = tr[p], &lt = tr[p << 1], &rt = tr[p << 1 | 1];
    if (u.add) {
        lt.add += u.add, lt.sum += u.add * (lt.r - lt.l + 1);
        rt.add += u.add, rt.sum += u.add * (rt.r - rt.l + 1);
        u.add = 0;
    }
}

void build(int p, int l, int r) {
    if (l == r)
        tr[p] = {l, r, 0, 0};
    else {
        tr[p] = {l, r};
        int mid = l + r >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
}

void modify(int p, int l, int r, int d) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].sum += (LL)(tr[p].r - tr[p].l + 1) * d;
        tr[p].add += d;
    } else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) modify(p << 1, l, r, d);
        if (r > mid) modify(p << 1 | 1, l, r, d);
        pushup(p);
    }
}

LL query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p].sum;
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    LL res = 0;
    if (l <= mid) res = query(p << 1, l, r);
    if (r > mid) res += query(p << 1 | 1, l, r);
    return res;
}
}  // namespace seg

namespace odt {
struct Node {
    int l, r;
    mutable int v;
    Node(int _l, int _r, int _v) : l(_l), r(_r), v(_v) {}
    bool operator<(const Node& a) const { return l < a.l; };
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

void assign(int l, int r, int c) {
    auto itr = split(r + 1), it = split(l);
    for (; it != itr; it = tr.erase(it)) {
        seg::modify(1, it->l, it->r, abs(c - it->v));
    }
    tr.emplace(l, r, c);
}
}  // namespace odt

int main() {
    scanf("%d%d", &n, &m);
    seg::build(1, 1, n);
    for (int i = 1; i <= n; ++i) odt::tr.emplace(i, i, i);

    int op, l, r, x;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            odt::assign(l, r, x);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", seg::query(1, l, r));
        }
    }

    return 0;
}