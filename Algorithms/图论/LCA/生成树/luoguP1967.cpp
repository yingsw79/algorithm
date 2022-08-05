#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1967

const int N = 10010, M = 50010;
int h[N], e[20010], w[20010], ne[20010], idx;
int p[N], d[N], fa[N][15], g[N][15];
int q[N];
int n, m, T;

struct Egde {
    int u, v, w;
    bool operator<(const Egde& a) const {
        return w > a.w;
    }
} edge[M];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void kruskal() {  //最大生成树
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = edge[i];
        int a = find(u), b = find(v);
        if (a == b) continue;
        p[a] = b;
        add(u, v, w), add(v, u, w);  //建树
    }
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
            g[j][0] = w[i];  //边的编号对应的权值
            q[++r] = j;
            for (int k = 1; k <= 14; k++) {
                int pos = fa[j][k - 1];
                fa[j][k] = fa[pos][k - 1];
                g[j][k] = min(g[j][k - 1], g[pos][k - 1]);  //树上倍增
            }
        }
    }
}

int lca(int x, int y) {
    if (find(x) != find(y)) return -1;
    if (d[x] < d[y]) swap(x, y);
    int res = INF;
    for (int i = 14; i >= 0; i--) {
        if (d[fa[x][i]] >= d[y]) {
            res = min(res, g[x][i]);
            x = fa[x][i];
        }
    }
    if (x == y) return res;
    for (int i = 14; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            res = min(res, min(g[x][i], g[y][i]));
            x = fa[x][i], y = fa[y][i];
        }
    }
    res = min(res, min(g[x][0], g[y][0]));
    return res;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);

    kruskal();
    for (int i = 1; i <= n; i++) {
        if (!d[i]) bfs(i);
    }

    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", lca(x, y));
    }
    
    return 0;
}