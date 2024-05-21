#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P5836

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int q[N], d[N], fa[N][18], G[N], H[N];
char s[N];
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root) {
    int l = 0, r = -1;
    q[++r] = root;
    d[root] = 1;
    if (s[root] == 'G')
        G[root] = 1;
    else
        H[root] = 1;
    while (l <= r) {
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (d[j]) continue;
            d[j] = d[t] + 1;
            G[j] = G[t] + (s[j] == 'G');
            H[j] = H[t] + (s[j] == 'H');
            fa[j][0] = t;
            q[++r] = j;
            for (int k = 1; k <= 17; k++)
                fa[j][k] = fa[fa[j][k - 1]][k - 1];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    for (int i = 17; i >= 0; i--) {
        if (d[fa[x][i]] >= d[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }

    bfs(1);
    while (m--) {
        int a, b;
        char op;
        scanf("%d%d %c", &a, &b, &op);
        int c = lca(a, b);
        int val;
        if (op == 'G')
            val = G[a] + G[b] - G[c] - G[fa[c][0]];
        else
            val = H[a] + H[b] - H[c] - H[fa[c][0]];
        if (val)
            printf("1");
        else
            printf("0");
    }

    return 0;
}