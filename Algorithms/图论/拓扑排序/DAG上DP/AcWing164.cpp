#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 30010, M = 30010;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N], q[N];
bitset<N> f[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (--d[j] == 0)
                q[++tt] = j;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }

    topsort();

    for (int i = n - 1; i >= 0; i--) {  //逆拓扑序DP
        int j = q[i];
        f[j][j] = 1;
        for (int k = h[j]; ~k; k = ne[k])
            f[j] |= f[e[k]];
    }

    for (int i = 1; i <= n; i++) printf("%d\n", f[i].count());

    return 0;
}
