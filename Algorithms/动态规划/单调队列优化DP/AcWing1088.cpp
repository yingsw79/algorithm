#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1090/

const int N = 2000010;
int p[N], d[N], q[N];
LL sum[N];
int n;
bool st[1000010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i], &d[i]);
        p[i + n] = p[i], d[i + n] = d[i];
    }

    for (int i = 1; i <= n * 2; i++) sum[i] = sum[i - 1] + p[i - 1] - d[i - 1];

    int l = 0, r = -1;
    for (int i = n * 2; i; i--) {
        while (l <= r && q[l] - i > n) l++;
        if (i <= n) st[i] = (sum[q[l]] >= sum[i]);
        while (l <= r && sum[i] <= sum[q[r]]) r--;
        q[++r] = i;
    }

    for (int i = n * 2; i; i--) sum[i] = sum[i + 1] + p[i + 1] - d[i];

    l = 0, r = -1;
    for (int i = 1; i <= n * 2; i++) {
        while (l <= r && i - q[l] > n) l++;
        if (i > n) st[i - n] |= (sum[q[l]] >= sum[i]);
        while (l <= r && sum[i] <= sum[q[r]]) r--;
        q[++r] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i])
            puts("TAK");
        else
            puts("NIE");
    }

    return 0;
}