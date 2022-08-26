#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2894

const int N = 50010;
int n, m;
struct Node {
    int l, r;
    int val, pre, suf;
    int tag;
} tr[N * 4];

void pushup(int p) {
    auto &u = tr[p], &lt = tr[p << 1], &rt = tr[p << 1 | 1];
    u.val = max(max(lt.val, rt.val), lt.suf + rt.pre);
    u.pre = (lt.pre == lt.r - lt.l + 1) ? lt.r - lt.l + 1 + rt.pre : lt.pre;
    u.suf = (rt.suf == rt.r - rt.l + 1) ? rt.r - rt.l + 1 + lt.suf : rt.suf;
}

void pushdown(int p) {
    auto &u = tr[p], &lt = tr[p << 1], &rt = tr[p << 1 | 1];
    if (u.tag != -1) {
        lt.val = lt.pre = lt.suf = u.tag ? 0 : lt.r - lt.l + 1;
        rt.val = rt.pre = rt.suf = u.tag ? 0 : rt.r - rt.l + 1;
        lt.tag = rt.tag = u.tag;
        u.tag = -1;
    }
}

void build(int p, int l, int r) {
    int x = r - l + 1;
    tr[p] = {l, r, x, x, x, -1};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
}

void modify(int p, int l, int r, int tag) {
    if (tr[p].l >= l && tr[p].r <= r) {
        tr[p].val = tr[p].pre = tr[p].suf = tag ? 0 : tr[p].r - tr[p].l + 1;
        tr[p].tag = tag;
    } else {
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) modify(p << 1, l, r, tag);
        if (r > mid) modify(p << 1 | 1, l, r, tag);
        pushup(p);
    }
}

int query(int p, int x) {
    if (tr[p].l == tr[p].r) return tr[p].l;
    pushdown(p);
    if (tr[p << 1].val >= x) return query(p << 1, x);
    if (tr[p << 1].suf + tr[p << 1 | 1].pre >= x)
        return (tr[p].l + tr[p].r >> 1) - tr[p << 1].suf + 1;
    return query(p << 1 | 1, x);
}

int main() {
    scanf("%d%d", &n, &m);

    build(1, 1, n);

    int op, x, y;
    while (m--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            if (tr[1].val >= x) {
                int l = query(1, x);
                printf("%d\n", l);
                modify(1, l, l + x - 1, 1);
            } else
                puts("0");
        } else {
            scanf("%d%d", &x, &y);
            modify(1, x, x + y - 1, 0);
        }
    }

    return 0;
}