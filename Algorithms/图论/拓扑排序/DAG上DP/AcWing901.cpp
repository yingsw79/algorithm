#include <bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/903/
//用记忆化搜索实现逆拓扑排序递推(DAG最长路)

const int N = 310;
int g[N][N], f[N][N];
int m, n;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y) {
    if (f[x][y] != -1) return f[x][y];
    int t = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > m || b < 1 || b > n || g[a][b] >= g[x][y]) continue;
        t = max(t, dp(a, b) + 1);
    }
    return f[x][y] = t;
}

int main() {
    memset(f, -1, sizeof f);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    int res = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            res = max(res, dp(i, j));

    printf("%d\n", res);
    return 0;
}