#include <bits/stdc++.h>
using namespace std;

// http://acm.hdu.edu.cn/showproblem.php?pid=3308

const int N = 100010;
int a[N], n, m;
struct Node {
    int l, r;
    int pre, suf, val;
} tr[N * 4];

void pushup(Node& u, Node& L, Node& R) {
    u.val = max(L.val, R.val);
    u.pre = L.pre, u.suf = R.suf;
    if (a[L.r] < a[R.l]) {
        u.val = max(u.val, L.suf + R.pre);
        if (L.pre == L.r - L.l + 1) u.pre += R.pre;
        if (R.suf == R.r - R.l + 1) u.suf += L.suf;
    }
}

void pushup(int p) {
    pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}

void build(int p, int l, int r) {
    tr[p] = {l, r, 1, 1, 1};
    if (l == r) return;
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

void modify(int p, int x, int v) {
    if (tr[p].l == tr[p].r)
        a[x] = v;
    else {
        int mid = tr[p].l + tr[p].r >> 1;
        if (x <= mid)
            modify(p << 1, x, v);
        else
            modify(p << 1 | 1, x, v);
        pushup(p);
    }
}

Node query(int p, int l, int r) {
    if (tr[p].l >= l && tr[p].r <= r) return tr[p];
    int mid = tr[p].l + tr[p].r >> 1;
    if (r <= mid)
        return query(p << 1, l, r);
    else if (l > mid)
        return query(p << 1 | 1, l, r);
    else {
        auto L = query(p << 1, l, r), R = query(p << 1 | 1, l, r);
        Node res{L.l, R.r};  // 要初始化区间端点！！！！！！！！
        pushup(res, L, R);
        return res;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        build(1, 1, n);
        char op[2];
        int x, y;
        while (m--) {
            scanf("%s%d%d", op, &x, &y);
            if (op[0] == 'Q')
                printf("%d\n", query(1, x + 1, y + 1).val);
            else
                modify(1, x + 1, y);
        }
    }

    return 0;
}