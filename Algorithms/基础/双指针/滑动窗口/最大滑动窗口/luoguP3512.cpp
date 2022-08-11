#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P3512

const int N = 3000010;
int a[N], n, k;
int q1[N], q2[N], l1 = 0, r1 = -1, l2 = 0, r2 = -1;

int main() {
    scanf("%d%d", &k, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int left = 1, right = 1;
    for (; right <= n; right++) {
        while (l1 <= r1 && a[q1[r1]] <= a[right]) r1--;  //更新最大值
        q1[++r1] = right;
        while (l2 <= r2 && a[q2[r2]] >= a[right]) r2--;  //更新最小值
        q2[++r2] = right;
        if (a[q1[l1]] - a[q2[l2]] > k) {  //如果不满足左端口与右端口一起右移
            left++;
            if (l1 <= r1 && q1[l1] < left) l1++;
            if (l2 <= r2 && q2[l2] < left) l2++;
        }
    }

    printf("%d\n", right - left);

    return 0;
}