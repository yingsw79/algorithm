#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P1137

const int N = 100010, M = 200010;
int h[N], e[M], ne[M], idx;
int q[N], indeg[N], f[N];
int n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int l = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        if (!indeg[i]) {
            q[++r] = i;
            f[i] = 1;  //递推起点初始化为1,也可以直接将f数组初始化为全1
        }
    }
    while (l <= r) {
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            f[j] = max(f[j], f[t] + 1);  //拓扑排序过程中就能递推
            if (--indeg[j] == 0) q[++r] = j;
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        indeg[b]++;
    }
    
    topsort();
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", f[i]);
    }

    return 0;
}