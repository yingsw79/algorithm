#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://atcoder.jp/contests/dp/tasks/dp_q

const int N = 200010;
int h[N], a[N], n;
LL tr[N];

void update(int x, LL v) {
    for (; x <= n; x += lowbit(x)) tr[x] = max(tr[x], v);
}

LL query(int x) {
    LL res = 0;
    for (; x; x &= x - 1) res = max(res, tr[x]);
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    LL res = 0;
    for (int i = 1; i <= n; ++i) {
        LL v = query(h[i] - 1) + a[i];
        res = max(res, v);
        update(h[i], v);
    }
    printf("%lld\n", res);

    return 0;
}