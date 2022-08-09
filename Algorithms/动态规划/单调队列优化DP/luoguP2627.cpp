#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2627
// https://www.luogu.com.cn/problem/P2034
// 给定一行n个非负整数a[1]..a[n]。现在你可以选择其中若干个数，
// 但不能有超过k个连续的数字被选择。你的任务是使得选出的数字的和最大。
// 即相邻两个不选的数字之间间隔不能超过k

const int N = 100010;
int e[N], q[N];
LL f[N];
int n, k, l = 0, r = -1;

int main() {
    scanf("%d%d", &n, &k);
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &e[i]);
        sum += e[i];
    }
    for (int i = 0; i <= n + 1; i++) {
        while (l <= r && i - q[l] - 1 > k) l++;
        f[i] = f[q[l]] + e[i];
        while (l <= r && f[q[r]] >= f[i]) r--;
        q[++r] = i;
    }
    printf("%lld\n", sum - f[n + 1]);

    return 0;
}