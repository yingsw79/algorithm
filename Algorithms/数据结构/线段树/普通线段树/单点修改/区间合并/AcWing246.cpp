#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/247/

const int N = 500010;
int n, m;
LL a[N];

struct Node {
    int l, r;
    LL sum, Gcd;
} tr[N * 4];

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void pushup(Node& p, Node& l, Node& r) {
    p.sum = l.sum + r.sum;
    p.Gcd = gcd(l.Gcd, r.Gcd);
}

void pushup(int p) {
    pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}

void build(int p, int l, int r) {
    if (l == r)
        tr[p] = {l, r, a[l] - a[l - 1], a[l] - a[l - 1]};  // 用线段树维护差分序列
    else {
        tr[p] = {l, r};
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        pushup(p);
    }
}

void modify(int p, int x, LL v) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p].sum += v;
        tr[p].Gcd += v;
    } else {
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
            modify(p << 1, x, v);
        else
            modify(p << 1 | 1, x, v);
        pushup(p);
    }
}

Node query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r)
        return tr[p];
    else {
        int mid = tr[p].l + tr[p].r >> 1;
        if (r <= mid)
            return query(p << 1, l, r);
        else if (l > mid)
            return query(p << 1 | 1, l, r);
        else {
            auto left = query(p << 1, l, r), right = query(p << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    build(1, 1, n);

    char op[2];
    int l, r;
    LL d;
    while (m--) {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q') {
            auto left = query(1, 1, l);
            Node right{0, 0, 0, 0};
            if (l + 1 <= r) right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.sum, right.Gcd)));
        } else {
            scanf("%lld", &d);
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d);
        }
    }

    return 0;
}