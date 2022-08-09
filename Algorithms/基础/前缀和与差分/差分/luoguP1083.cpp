#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// https://www.luogu.com.cn/problem/P1083

const int N = 1000010;
int a[N];
LL diff[N];  //会爆int
int n, m;
struct R {
    int l, r, d;
} q[N];

bool check(int mid) {
    memset(diff, 0, sizeof diff);  //每次要初始化！！！！！！
    for (int i = 1; i <= mid; i++) {
        auto [l, r, d] = q[i];
        diff[l] += d;
        diff[r + 1] -= d;
    }
    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        if (diff[i] > a[i]) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &q[i].d, &q[i].l, &q[i].r);
    int l = 1, r = m + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l == m + 1)
        puts("0");
    else
        puts("-1"), printf("%d\n", l);

    return 0;
}