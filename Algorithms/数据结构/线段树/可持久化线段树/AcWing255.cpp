#include <bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/257/

const int N = 100010, M = 10010;
int a[N], nums[N];
int root[N], idx;
int n, m;

struct Node {
    int lc, rc, cnt;
} tr[N * 20];

int build(int l, int r) {
    int p = ++idx;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].lc = build(l, mid);
    tr[p].rc = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x) {
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r) {
        ++tr[q].cnt;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].lc = insert(tr[p].lc, l, mid, x);
    else
        tr[q].rc = insert(tr[p].rc, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].lc].cnt + tr[tr[q].rc].cnt;
    return q;
}

int query(int p, int q, int l, int r, int k) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int cnt = tr[tr[q].lc].cnt - tr[tr[p].lc].cnt;
    if (k <= cnt)
        return query(tr[p].lc, tr[q].lc, l, mid, k);
    else
        return query(tr[p].rc, tr[q].rc, mid + 1, r, k - cnt);
}

int main() {
    scanf("%d%d", &n, &m);
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        nums[t++] = a[i];
    }

    sort(nums, nums + n);
    t = unique(nums, nums + n) - nums;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(nums, nums + t, a[i]) - nums + 1;

    root[0] = build(1, t);

    for (int i = 1; i <= n; ++i)
        root[i] = insert(root[i - 1], 1, t, a[i]);

    int l, r, k;
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", nums[query(root[l - 1], root[r], 1, t, k) - 1]);
    }

    return 0;
}