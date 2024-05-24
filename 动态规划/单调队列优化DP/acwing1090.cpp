#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1092/

const int N = 50010;
int a[N], f[N], q[N];
int n, t;

bool check(int mid) {
    int l = 0, r = -1;
    // memset(f, 0, sizeof f);
    for (int i = 0; i <= n + 1; i++) {
        while (l <= r && i - q[l] - 1 > mid) l++;
        f[i] = f[q[l]] + a[i];
        while (l <= r && f[i] <= f[q[r]]) r--;
        q[++r] = i;
    }
    return f[n + 1] <= t;
}

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}