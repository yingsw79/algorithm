#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/248/

const int N = 200010;
int a[N];
LL tr[N];
int n, m;

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

LL getsum(int x) {
    LL sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    while (m--) {
        char op[2];
        int l, r, d;
        scanf("%s%d", op, &l);
        if (*op == 'C') {
            scanf("%d%d", &r, &d);
            add(l, d), add(r + 1, -d);  //对下标
        } else {
            printf("%lld\n", a[l] + getsum(l));
        }
    }

    return 0;
}