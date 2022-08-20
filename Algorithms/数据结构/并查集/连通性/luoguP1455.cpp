#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1455

const int N = 10010;
int w[N], v[N], p[N], f[N];
int n, m, k;

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &v[i]);
        p[i] = i;
    }

    while (k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if (a == b) continue;
        p[a] = b;
        w[b] += w[a];
        v[b] += v[a];
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            for (int j = m; j >= w[i]; j--)  //忽略第一维
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", f[m]);

    return 0;
}