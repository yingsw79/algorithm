#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P2330

// 无向图的瓶颈生成树是这样的一个生成树，它的最大的边权值在的所有生成树中最小。
// 性质:最小生成树是瓶颈生成树的充分不必要条件。 即最小生成树一定是瓶颈生成树，而瓶颈生成树不一定是最小生成树。

const int N = 310, M = 100010;
int p[N];
int n, m;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& a) const {
        return w < a.w;
    }
} edge[M];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge + 1, edge + 1 + m);
    int res;
    for (int i = 1; i <= m; i++) {
        int a = find(edge[i].u), b = find(edge[i].v);
        if (a == b) continue;
        p[a] = b;
        res = edge[i].w;
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    printf("%d %d\n", n - 1, kruskal());

    return 0;
}