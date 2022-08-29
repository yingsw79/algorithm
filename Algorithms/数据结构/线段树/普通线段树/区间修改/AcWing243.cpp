#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/244/

const int N = 100010;
int a[N], n, m;

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
        tr[p] = {l, r, a[l], 0};
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

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    build(1, 1, n);

    char op[2];
    int l, r, d;
    while (m--) {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'C') {
            scanf("%d", &d);
            modify(1, l, r, d);
        } else
            printf("%lld\n", query(1, l, r));
    }

    return 0;
}