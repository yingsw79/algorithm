#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3594
// 动态滑动窗口最大值

const int N = 2000010;
int w[N], q[N];
int n, d;
LL sum[N], t[N], p;

int main() {
    scanf("%d%lld%d", &n, &p, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum[i] = sum[i - 1] + w[i];
    }

    //预处理,方便后面用单调队列维护区间内t[i]的最大值
    for (int i = d; i <= n; i++) t[i] = sum[i] - sum[i - d];  

    int l = -1, r = 0, res = 0;
    for (int i = d, j = 1; i <= n; i++) {
        while (l <= r && t[q[r]] <= t[i]) r--;
        q[++r] = i;
        while (l <= r && sum[i] - sum[j - 1] - t[q[l]] > p) {
            j++;
            while (l <= r && q[l] - j + 1 < d) l++;  //边移动左端点的同时要更新已经无效的值
        }
        res = max(res, i - j + 1);
    }
    printf("%d\n", res);

    return 0;
}