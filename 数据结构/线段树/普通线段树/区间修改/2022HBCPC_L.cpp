#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/gym/103729

const int N = 100010;
int a[N], s[N];
int n, q;

struct Node {
    int l, r, cnt;
    LL sum, add;
} tr[N * 4];

void pushup(int p) {
    auto &u = tr[p], &L = tr[p << 1], &R = tr[p << 1 | 1];
    u.cnt = L.cnt + R.cnt;
    u.sum = L.sum + R.sum;
}

void pushdown(int p) {
    if (tr[p].add) {
        auto &u = tr[p], &L = tr[p << 1], &R = tr[p << 1 | 1];
        L.sum += L.cnt * u.add, R.sum += R.cnt * u.add;
        L.add += u.add, R.add += u.add;
        u.add = 0;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, s[l], a[l], 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void modify(int p, int x) {
    if (tr[p].l == tr[p].r)
        tr[p].cnt ^= 1;
    else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
            modify(p << 1, x);
        else
            modify(p << 1 | 1, x);
        pushup(p);
    }
}

void modify(int p, int l, int r, int v) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].sum += (LL)tr[p].cnt * v;
        tr[p].add += v;
    } else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) modify(p << 1, l, r, v);
        if (r > mid) modify(p << 1 | 1, l, r, v);
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
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);

    build(1, 1, n);

    int op, l, r, x;
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            modify(1, x);
        } else if (op == 2) {
            scanf("%d", &x);
            modify(1, x);
        } else if (op == 3) {
            scanf("%d%d%d", &l, &r, &x);
            modify(1, l, r, x);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(1, l, r));
        }
    }

    return 0;
}