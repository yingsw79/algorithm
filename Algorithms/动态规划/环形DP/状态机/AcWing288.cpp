#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/290/

const int N = 3840;
int w[N], f[2][N][2];  //必须用滚动数组优化,否则超内存
int n, m;

void dp() {
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j][0] = max(f[i - 1 & 1][j][0], f[i - 1 & 1][j][1]);
            if (j >= 1) f[i & 1][j][1] = max(f[i - 1 & 1][j - 1][0], f[i - 1 & 1][j - 1][1] + w[i]);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);

    memset(f, 0xcf, sizeof f);
    f[1][0][0] = f[1][1][1] = 0;
    dp();
    int res = max(f[n & 1][m][0], f[n & 1][m][1]);

    memset(f, 0xcf, sizeof f);
    f[1][1][1] = w[1];  //令第1和第n个小时强制休息
    dp();
    res = max(res, f[n & 1][m][1]);

    printf("%d\n", res);
    return 0;
}