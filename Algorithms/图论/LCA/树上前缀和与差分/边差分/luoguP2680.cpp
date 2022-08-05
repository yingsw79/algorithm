#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2680

const int N = 300010, M = N * 2;
int h[N], e[M], w[M], ne[M], idx;
int q[N], d[N], dist[N], fa[N][20], diff[N], p[N];
int max_t;
int n, m;

struct Task {
    int u, v, lca, t;
} tasks[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root) {
    int l = 0, r = -1;
    d[root] = 1;
    q[++r] = root;
    while (l <= r) {
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j]) continue;
            d[j] = d[t] + 1;
            p[j] = w[i];
            dist[j] = dist[t] + w[i];
            fa[j][0] = t;
            q[++r] = j;
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

void dfs(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfs(j, u);
        diff[u] += diff[j];
    }
}

bool check(int mid) {
    memset(diff, 0, sizeof diff);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (tasks[i].t > mid) {
            cnt++;
            diff[tasks[i].u]++;
            diff[tasks[i].v]++;
            diff[tasks[i].lca] -= 2;
        }
    }
    dfs(1, -1);
    int max_e = 0;
    for (int i = 1; i <= n; i++) {
        if (diff[i] == cnt) max_e = max(max_e, p[i]);
    }
    return max_t - max_e <= mid;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    bfs(1);

    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        int z = lca(x, y);
        int t = dist[x] + dist[y] - dist[z] * 2;
        max_t = max(max_t, t);
        tasks[i] = {x, y, z, t};
    }

    int l = 0, r = max_t;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);

    return 0;
}