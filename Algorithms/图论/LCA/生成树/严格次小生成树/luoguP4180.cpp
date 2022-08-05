#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P4180

const int N = 100010, M = 300010;
int h[N], e[200010], w[200010], ne[200010], idx;
int p[N], d[N], fa[N][18], g[N][18][2];
int q[N];
int n, m;

struct Egde {
    int u, v, w;
    bool used;
    bool operator<(const Egde& a) const {
        return w < a.w;
    }
} edge[M];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

LL kruskal() {  
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge + 1, edge + 1 + m);
    LL res = 0;
    for (int i = 1; i <= m; i++) {
        auto& [u, v, w, used] = edge[i];
        int a = find(u), b = find(v);
        if (a == b) continue;
        p[a] = b;
        used = true;
        res += w;
        add(u, v, w), add(v, u, w);  //建树
    }
    return res;
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
            g[j][0][0] = w[i];  //边的编号对应的权值
            g[j][0][1] = -INF;
            q[++r] = j;
            for (int k = 1; k <= 17; k++) {
                int pos = fa[j][k - 1];
                fa[j][k] = fa[pos][k - 1];
                g[j][k][0] = max(g[j][k - 1][0], g[pos][k - 1][0]);  //树上倍增
                if (g[j][k - 1][0] == g[pos][k - 1][0])
                    g[j][k][1] = max(g[j][k - 1][1], g[pos][k - 1][1]);
                else if (g[j][k - 1][0] > g[pos][k - 1][0])
                    g[j][k][1] = max(g[j][k - 1][1], g[pos][k - 1][0]);
                else
                    g[j][k][1] = max(g[j][k - 1][0], g[pos][k - 1][1]);
            }
        }
    }
}

int lca(int x, int y, int w) {
    if (d[x] < d[y]) swap(x, y);
    int t1 = -INF, t2 = -INF;
    for (int i = 17; i >= 0; i--) {
        if (d[fa[x][i]] >= d[y]) {
            if (t1 > g[x][i][0])
                t2 = max(t2, g[x][i][0]);
            else if (t1 == g[x][i][0])
                t2 = max(t2, g[x][i][1]);
            else
                t2 = max(t2, max(t1, g[x][i][1])), t1 = g[x][i][0];
            x = fa[x][i];
        }
    }
    if (x != y) {
        for (int i = 17; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                t1 = max(t1, max(g[x][i][0], g[y][i][0]));
                t2 = max(t2, g[x][i][0] != t1 ? g[x][i][0] : g[x][i][1]);
                t2 = max(t2, g[y][i][0] != t1 ? g[y][i][0] : g[y][i][1]);
                x = fa[x][i], y = fa[y][i];
            }
        }
        t1 = max(t1, max(g[x][0][0], g[y][0][0]));
        t2 = max(t2, g[x][0][0] != t1 ? g[x][0][0] : g[x][0][1]);
        t2 = max(t2, g[y][0][0] != t1 ? g[y][0][0] : g[y][0][1]);
    }
    return w > t1 ? w - t1 : w - t2;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        edge[i].used = false;
    }

    LL sum = kruskal();
    bfs(1);

    LL res = LLONG_MAX;
    for (int i = 1; i <= m; i++) {
        if (!edge[i].used) {
            res = min(res, sum + lca(edge[i].u, edge[i].v, edge[i].w));
        }
    }
    printf("%lld\n", res);

    return 0;
}