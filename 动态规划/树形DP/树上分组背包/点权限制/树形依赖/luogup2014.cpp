#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2014
// https://www.acwing.com/problem/content/description/288/
// https://www.acwing.com/problem/content/10/

const int N = 310;
int h[N], e[N], ne[N], idx;
int w[N], f[N][N], n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dfs(v);
        for (int j = m - 1; j; j--)
            for (int k = 1; k <= j; k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k]);
    }
    for (int j = m; j; j--) f[u][j] = f[u][j - 1] + w[u];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    m++;
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d%d", &a, &w[i]);
        add(a, i);
    }
    dfs(0);
    printf("%d\n", f[0][m]);

    return 0;
}