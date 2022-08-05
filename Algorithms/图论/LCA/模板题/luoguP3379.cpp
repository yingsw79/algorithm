#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P3379

const int N = 500010, M = 1000010;
int h[N], e[M], ne[M], idx;
int d[N], q[N], fa[N][20];
int n, m, root;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root) {
    int l = 0, r = -1;
    q[++r] = root;
    d[root] = 1;
    while (l <= r) {
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j]) continue;
            d[j] = d[t] + 1;
            q[++r] = j;
            fa[j][0] = t;
            for (int k = 1; k <= 19; k++)
                fa[j][k] = fa[fa[j][k - 1]][k - 1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (d[fa[x][i]] >= d[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    bfs(root);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}