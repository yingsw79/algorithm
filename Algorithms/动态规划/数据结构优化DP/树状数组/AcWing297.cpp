#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/299/

const int N = 1010;
int a[N], nums[N], cnt, f[N][N];
int tr[N];
int n, m;

void add(int x, int v) {
    for (; x <= cnt; x += lowbit(x)) tr[x] = (tr[x] + v) % MOD;
}

int getSum(int x) {
    int sum = 0;
    for (; x; x -= lowbit(x)) sum = (sum + tr[x]) % MOD;
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int C = 1; C <= T; C++) {
        scanf("%d%d", &n, &m);
        cnt = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), nums[cnt++] = a[i];

        sort(nums, nums + cnt);
        cnt = unique(nums, nums + cnt) - nums;
        for (int i = 1; i <= n; i++) a[i] = lower_bound(nums, nums + cnt, a[i]) - nums + 1;  // 提前离散化

        for (int i = 1; i <= n; i++) f[1][i] = 1;
        for (int i = 2; i <= m; i++) {
            memset(tr, 0, sizeof tr);
            for (int j = 1; j <= n; j++) {
                f[i][j] = getSum(a[j] - 1);
                add(a[j], f[i - 1][j]);
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) res = (res + f[m][i]) % MOD;
        printf("Case #%d: %d\n", C, res);
    }

    return 0;
}