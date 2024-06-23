#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3084

const int N = 200010;
int ls[N], rs[N], f[N];
int q[N], l = 0, r = -1;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ls[y + 1] = max(ls[y + 1], x);
        rs[y] = min(rs[y], x - 1);
    }

    for (int i = 1; i <= n + 1; i++) rs[i] = i - 1;  //一般的单调队列上界为i-1
    for (int i = 2; i <= n + 1; i++) ls[i] = max(ls[i], ls[i - 1]);
    for (int i = n; i >= 1; i--) rs[i] = min(rs[i], rs[i + 1]);

    for (int i = 1, j = 0; i <= n + 1; i++) {
        for (; j <= rs[i]; j++) {  //指针维护右边界！！！！！
            if (f[j] == -1) continue;  //非法状态不能入队
            while (l <= r && f[q[r]] <= f[j]) r--;
            q[++r] = j;
        }
        while (l <= r && q[l] < ls[i]) l++;
        if (l <= r)
            f[i] = f[q[l]] + (i != n + 1);
        else
            f[i] = -1;  //队列为空说明该状态无法转移
    }

    printf("%d\n", f[n + 1]);

    return 0;
}