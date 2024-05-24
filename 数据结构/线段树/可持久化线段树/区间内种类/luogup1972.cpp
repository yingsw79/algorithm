#pragma GCC optmize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int last[N], w[N], root[N];  
int idx = 0;
int n, m;

// https://www.luogu.com.cn/problem/P1972
// 在线求区间内不同数字的个数
// 方法一: 主席树统计区间[l,r]中每个数上一次出现在l-1前的个数和

struct node {
    int l, r;
    int sum;
} tr[N * 30];

int build(int l, int r) {
    int p = ++idx;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].sum++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].l = insert(tr[p].l, l, mid, x);
    else
        tr[q].r = insert(tr[p].r, mid + 1, r, x);
    tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
    return q;
}

int query(int p, int q, int l, int r, int x) {
    if (l == r) return tr[q].sum - tr[p].sum;
    int mid = l + r >> 1;
    int sum = tr[tr[q].l].sum - tr[tr[p].l].sum;
    if (x <= mid)
        return query(tr[p].l, tr[q].l, l, mid, x);
    else
        return sum + query(tr[p].r, tr[q].r, mid + 1, r, x);
}

void solve() {
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        w[i] = last[x];
        last[x] = i;
    }
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++)
        root[i] = insert(root[i - 1], 1, n, w[i] + 1);  // 1~n

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(root[l - 1], root[r], 1, n, l) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
}
