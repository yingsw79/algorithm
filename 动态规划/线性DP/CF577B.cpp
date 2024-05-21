#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://codeforces.com/problemset/problem/577/B
// 给定n个数，问是否存在子序列的和被m整除

const int N = 1010;
bool f[N][N];  // f[i][j]表示是否存在以i结尾的子序列和模数为j
int a[N], n, m;

int main() {
    scanf("%d%d", &n, &m);
    if (n > m) {  // 抽屉原理
        puts("YES");
        return 0;
    }

    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] %= m;

    for (int i = 1; i <= n; ++i) {
        f[i][a[i]] = true;
        for (int j = 0; j < m; ++j) {
            f[i][j] |= f[i - 1][j];
            f[i][(j + a[i]) % m] |= f[i - 1][j];
        }
        if (f[i][0]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}