#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2607

const int N = 1000010;
int h[N], e[N], ne[N], idx;
int n, w[N], rt1, rt2;
LL f[N][2];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void find(int u, int rt) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == rt) {
            rt1 = u, rt2 = j;
            return;
        }
        if (st[j]) continue;
        find(j, rt);
    }
}

LL dp(int u, int rt) {
    f[u][0] = 0, f[u][1] = w[u];
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == rt) continue;
        dp(j, rt);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
    return f[u][0];
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d%d", &w[i], &a);
        add(a, i);  //建有向外向树，方便断环和树形DP
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;
        rt1 = rt2 = 0;
        find(i, i);
        if (rt1) {
            LL t1 = dp(rt1, rt1);
            LL t2 = dp(rt2, rt2);
            res += max(t1, t2);
        }
    }
    printf("%lld\n", res);
    return 0;
}