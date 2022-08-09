#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/CF1077F2
// https://codeforces.com/problemset/problem/1077/F2
// 给你一个长度为n的数列a，你需要选择m个元素，使得连续的k个元素都至少有一个被选中。
// 需要你最大化选出来的所有数的和。

const int N = 5010;
int a[N];
LL f[N][N];  //f[i][j]表示前 i ​个数一共取 j​ 个且第 i​ 个一定取
int q[N];
int n, k, m;

int main() {
    scanf("%d%d%d", &n, &k, &m);
    if (n / k > m) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int j = 1; j <= m + 1; j++) {
        int l = 0, r = -1;
        q[++r] = 0;
        for (int i = 1; i <= n + 1; i++) {
            while (l <= r && i - q[l] > k) l++;
            f[i][j] = f[q[l]][j - 1] + a[i];
            while (l <= r && f[q[r]][j - 1] <= f[i][j - 1]) r--;
            q[++r] = i;
        }
    }
    printf("%lld\n", f[n + 1][m + 1]);
    
    return 0;
}