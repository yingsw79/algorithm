#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/297/
// https://www.acwing.com/problem/content/909/
// 区间覆盖问题

const int N = 25010, M = 1000010;
int n, m;
PII q[N];
struct Node {
    int l, r, v;
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

void update(int p, int x, int v) {
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

int query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p].v;
    int mid = tr[p].l + tr[p].r >> 1;
    int res = INF;
    if (l <= mid) res = query(p << 1, l, r);
    if (r > mid) res = min(res, query(p << 1 | 1, l, r));
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d%d", &q[i].first, &q[i].second);

    sort(q, q + n, [](PII& a, PII& b) {
        return a.second < b.second;
    });

    build(1, 0, m);
    update(1, 0, 0);

    for (int i = 0; i < n; i++)
        update(1, q[i].second, query(1, q[i].first - 1, q[i].second - 1) + 1);

    int res = query(1, m, m);
    printf("%d\n", res == INF ? -1 : res);

    return 0;
}