#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3572

const int N = 1000010;
int h[N], q[N], f[N];
int n, k, T;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &k);
        int l = 0, r = -1;
        for (int i = 1; i <= n; i++) {
            while (l <= r && i - q[l] > k) l++;
            if (l <= r) f[i] = f[q[l]] + (h[i] >= h[q[l]]);
            // while (l <= r && f[q[r]] >= f[i]) r--; 错误！要考虑两个因素！
            while (l <= r && (f[q[r]] > f[i] || f[q[r]] == f[i] && h[q[r]] <= h[i])) r--;
            q[++r] = i;
        }
        printf("%d\n", f[n]);
    }

    return 0;
}