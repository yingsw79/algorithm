#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 998244353;

// https://www.acwing.com/problem/content/4499/

const int N = 2010;
int f[N][N];
int m, n, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    f[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k && j < i; j++) {
            f[i][j] = f[i - 1][j];
            if (j) f[i][j] = (f[i][j] + f[i - 1][j - 1] * (m - 1l)) % MOD;
        }
    }
    printf("%d\n", f[n][k]);

    return 0;
}