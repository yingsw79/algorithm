#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const LL INF = 1e15;

// https://www.acwing.com/problem/content/description/298/

const int N = 10010, M = 90000;
int n, m, e;
struct Range {
    int l, r, w;
    bool operator<(const Range& a) const { return r < a.r; };
} q[N];

struct Node {
    int l, r;
    LL v;
} tr[M * 4];

void pushup(int p) {
    tr[p].v = min(tr[p << 1].v, tr[p << 1 | 1].v);
}

void build(int p, int l, int r) {
    tr[p] = {l, r, INF};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

void update(int p, int x, LL v) {
    if (tr[p].l == x && tr[p].r == x)
        tr[p].v = min(tr[p].v, v);
    else {
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
            update(p << 1, x, v);
        else
            update(p << 1 | 1, x, v);
        pushup(p);
    }
}

LL query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p].v;
    int mid = tr[p].l + tr[p].r >> 1;
    LL res = INF;
    if (l <= mid) res = query(p << 1, l, r);
    if (r > mid) res = min(res, query(p << 1 | 1, l, r));
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 0; i < n; i++) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].w);

    sort(q, q + n);

    build(1, m - 1, e);
    update(1, m - 1, 0);

    for (int i = 0; i < n; i++)
        update(1, q[i].r, query(1, q[i].l - 1, q[i].r - 1) + q[i].w);

    LL res = query(1, e, e);
    printf("%lld\n", res == INF ? -1 : res);

    return 0;
}