#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P2633

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
int a[N], nums[N], n, m, tot; 
int root[N], d[N], q[N], fa[N][18], t;

struct Node {
    int ls, rs, cnt;
} tr[N * 20];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int insert(int p, int l, int r, int x) {
    int q = ++tot;
    tr[q] = tr[p];
    if (l == r) {
        ++tr[q].cnt;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].ls = insert(tr[p].ls, l, mid, x);
    else
        tr[q].rs = insert(tr[p].rs, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].ls].cnt + tr[tr[q].rs].cnt;
    return q;
}

int query(int u, int v, int p, int q, int l, int r, int k) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int cnt = tr[tr[u].ls].cnt + tr[tr[v].ls].cnt - tr[tr[p].ls].cnt - tr[tr[q].ls].cnt;
    if (k <= cnt)
        return query(tr[u].ls, tr[v].ls, tr[p].ls, tr[q].ls, l, mid, k);
    else
        return query(tr[u].rs, tr[v].rs, tr[p].rs, tr[q].rs, mid + 1, r, k - cnt);
}

void bfs() {
    d[1] = 1;
    root[1] = insert(root[0], 1, t, a[1]);  // 注意根节点也要插入！！！
    int l = 0, r = -1;
    q[++r] = 1;
    while (l <= r) {
        int x = q[l++];
        for (int i = h[x]; ~i; i = ne[i]) {
            int y = e[i];
            if (d[y]) continue;
            d[y] = d[x] + 1;
            fa[y][0] = x;
            root[y] = insert(root[x], 1, t, a[y]);  // 主席树插入
            q[++r] = y;
            for (int j = 1; j <= 17; ++j)
                fa[y][j] = fa[fa[y][j - 1]][j - 1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = 17; i >= 0; --i) {
        if (d[fa[x][i]] >= d[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        nums[t++] = a[i];
    }

    sort(nums, nums + n);
    t = unique(nums, nums + n) - nums;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(nums, nums + t, a[i]) - nums + 1;

    for (int i = 1, a, b; i < n; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bfs();

    for (int i = 0, res = 0, u, v, k, _lca; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &k);
        u ^= res;
        _lca = lca(u, v);
        res = nums[query(root[u], root[v], root[_lca], root[fa[_lca][0]], 1, t, k) - 1];
        printf("%d\n", res);
    }

    return 0;
}