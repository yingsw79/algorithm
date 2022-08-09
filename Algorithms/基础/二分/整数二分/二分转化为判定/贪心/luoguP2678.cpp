#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2678

const int N = 50010;
int a[N];
int n, m;

bool check(int mid) {  //贪心
    int last = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - last < mid)
            cnt++;
        else
            last = a[i];
    }
    return cnt <= m;
}

int main() {
    int t;
    scanf("%d%d%d", &t, &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[++n] = t;
    int l = 0, r = t;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);

    return 0;
}