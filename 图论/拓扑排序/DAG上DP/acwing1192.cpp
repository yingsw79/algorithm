#include <bits/stdc++.h>
using namespace std;

// https://www.acwing.com/problem/content/1194/

const int N = 10010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N], dist[N], indeg[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//边权均为正数的差分约束可用拓扑排序解决，先判环，如无环则对得到的拓扑序列用动态规划求最长（短）路
bool topsort() {  
    int l = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) q[++r] = i;
    }
    while (l <= r) {
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (--indeg[j] == 0) q[++r] = j;
        }
    }
    return r == n - 1;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
        indeg[a]++;
    }

    if (!topsort())
        puts("Poor Xed");
    else {
        for (int i = 1; i <= n; i++) {
            dist[i] = 100;
        }
        for (int i = 0; i < n; i++) {
            int ver = q[i];
            for (int j = h[ver]; ~j; j = ne[j]) {
                int k = e[j];
                dist[k] = max(dist[k], dist[ver] + 1);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += dist[i];
        }
        printf("%d\n", res);
    }

    return 0;
}