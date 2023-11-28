#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2216

const int N = 1010;
int a[N][N], f[N][N], g[N][N], q[N];
int m, n, k;

int main() {
    scanf("%d%d%d", &m, &n, &k);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (int j = 1; j <= n; j++) {
        int l = 0, r = -1;
        for (int i = 1; i <= m; i++) {
            while (l <= r && i - q[l] + 1 > k) l++;
            while (l <= r && a[i][j] >= a[q[r]][j]) r--;
            q[++r] = i;
            if (i >= k) f[i][j] = a[q[l]][j];
        }
        l = 0, r = -1;
        for (int i = 1; i <= m; i++) {
            while (l <= r && i - q[l] + 1 > k) l++;
            while (l <= r && a[i][j] <= a[q[r]][j]) r--;
            q[++r] = i;
            if (i >= k) g[i][j] = a[q[l]][j];
        }
    }

    int res = INF;
    for (int i = k; i <= m; i++) {
        int l = 0, r = -1;
        for (int j = 1; j <= n; j++) {
            while (l <= r && j - q[l] + 1 > k) l++;
            while (l <= r && f[i][j] >= f[i][q[r]]) r--;
            q[++r] = j;
            if (j >= k) a[i][j] = f[i][q[l]];
        }
        l = 0, r = -1;
        for (int j = 1; j <= n; j++) {
            while (l <= r && j - q[l] + 1 > k) l++;
            while (l <= r && g[i][j] <= g[i][q[r]]) r--;
            q[++r] = j;
            if (j >= k) res = min(res, a[i][j] - g[i][q[l]]);
        }
    }

    printf("%d\n", res);

    return 0;
}