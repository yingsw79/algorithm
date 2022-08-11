#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1273

const int N = 3010;
int h[N], e[N], w[N], ne[N], idx;
int f[N][N];  //恰好！！！！！！！
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    if (u > n - m) return 1;
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        int t = dfs(v);
        cnt += t;
        for (int j = cnt; j; j--)
            for (int k = 1; k <= min(t, j); k++)
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] - w[i]);
    }
    return cnt;
}

int main() {
    memset(h, -1, sizeof h);
    memset(f, -0x3f, sizeof f);  

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - m; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(i, x, y);
        }
    }
    for (int i = n - m + 1; i <= n; i++) scanf("%d", &f[i][1]);  //叶子节点初始化
    for (int i = 1; i <= n; i++) f[i][0] = 0;

    dfs(1);
    for (int i = m; i >= 0; i--)
        if (f[1][i] >= 0) {
            printf("%d\n", i);
            break;
        }

    return 0;
}