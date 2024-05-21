#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3128

const int N = 50010, M = N * 2;
int h[N], e[M], ne[M], idx;
int q[N], d[N], fa[N][17], diff[N];
int n, m, res = -INF;

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
            fa[j][0] = t;
            q[++r] = j;
            for (int k = 1; k <= 16; k++) {
                fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = 16; i >= 0; i--) {
        if (d[fa[x][i]] >= d[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 16; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int dfs(int u, int p) {
    int t = diff[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == p) continue;
        t += dfs(j, u);
    }
    res = max(res, t);
    return t;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    bfs(1);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int c = lca(a, b);
        diff[a]++, diff[b]++, diff[c]--, diff[fa[c][0]]--;
    }
    dfs(1, -1);
    printf("%d\n", res);

    return 0;
}