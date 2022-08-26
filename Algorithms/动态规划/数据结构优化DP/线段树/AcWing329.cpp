#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/331/

const int N = 30010, M = 200010, base = 100005;
int n, s;
int L[N], R[N], f[N][2];

struct Node {
    int l, r, v;
    bool tag;
} tr[M * 4];  // 区间修改,单点查询

void pushdown(int p) {
    if (tr[p].tag) {
        tr[p << 1].v = tr[p << 1 | 1].v = tr[p].v;
        tr[p << 1].tag = tr[p << 1 | 1].tag = true;
        tr[p].tag = false;
    }
}

void build(int p, int l, int r) {
    tr[p] = {l, r, 0, false};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

void modify(int p, int l, int r, int v) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].v = v;
        tr[p].tag = true;
    } else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) modify(p << 1, l, r, v);
        if (r > mid) modify(p << 1 | 1, l, r, v);
    }
}

int query(int p, int x) {
    if (tr[p].l == tr[p].r) return tr[p].v;
    pushdown(p);
    int mid = tr[p].l + tr[p].r >> 1;
    if (x <= mid)
        return query(p << 1, x);
    else
        return query(p << 1 | 1, x);
}

int main() {
    scanf("%d%d", &n, &s);
    s += base;
    
    build(1, 1, M - 1);

    L[0] = R[0] = base;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &L[i], &R[i]);
        L[i] += base, R[i] += base;
        int a = query(1, L[i]), b = query(1, R[i]);
        f[i][0] = min(f[a][0] + abs(L[i] - L[a]), f[a][1] + abs(L[i] - R[a]));
        f[i][1] = min(f[b][0] + abs(R[i] - L[b]), f[b][1] + abs(R[i] - R[b]));
        modify(1, L[i], R[i], i);
    }
    int res = min(f[n][0] + abs(L[n] - s), f[n][1] + abs(R[n] - s));
    printf("%d\n", res);

    return 0;
}