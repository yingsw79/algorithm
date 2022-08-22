#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1277/

const int N = 200010;
int m, p;

struct Node {
    int l, r, val;
} tr[N * 4];

void pushup(int p) {
    tr[p].val = max(tr[p << 1].val, tr[p << 1 | 1].val);
}

void build(int p, int l, int r) {
    tr[p] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void modify(int p, int x, int v) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p].val = v;
        return;
    }
    int mid = tr[p].l + tr[p].r >> 1;
    if (x <= mid)
        modify(p << 1, x, v);
    else
        modify(p << 1 | 1, x, v);
    pushup(p);
}

int query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p].val;
    int mid = tr[p].l + tr[p].r >> 1;
    int res = 0;
    if (l <= mid) res = query(p << 1, l, r);
    if (r > mid) res = max(res, query(p << 1 | 1, l, r));
    return res;
}

int main() {
    int n = 0, last = 0;
    scanf("%d%d", &m, &p);
    build(1, 1, m);

    int x;
    char op[2];
    while (m--) {
        scanf("%s%d", op, &x);
        if (*op == 'Q') {
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        } else {
            modify(1, ++n, ((LL)last + x) % p);
        }
    }

    return 0;
}