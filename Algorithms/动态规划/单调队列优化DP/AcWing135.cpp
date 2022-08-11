#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/137/

const int N = 300010;
int n, m, q[N];
LL sum[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        sum[i] = sum[i - 1] + a;
    }
    LL res = LLONG_MIN;
    int l = 0, r = -1;
    q[++r] = 0;
    for (int i = 1; i <= n; i++) {
        while (l <= r && i - q[l] > m) l++;
        res = max(res, sum[i] - sum[q[l]]);
        while (l <= r && sum[i] <= sum[q[r]]) r--;
        q[++r] = i;
    }

    printf("%lld\n", res);

    return 0;
}