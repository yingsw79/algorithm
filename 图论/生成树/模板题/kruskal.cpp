#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int N = 100010, M = 200010;
int p[N];
int n, m;

struct Edge {
    int a, b, w;
    bool operator<(const Edge& E) const {
        return w < E.w;
    }
} edge[M];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge + 1, edge + m + 1);
    int res = 0, cnt = 0;
    for (int i = 1; i <= m; i++) {
        int a = find(edge[i].a);
        int b = find(edge[i].b);
        if (a == b) continue;
        p[a] = b;
        res += edge[i].w;
        if (++cnt == n - 1) return res;
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].w);
    }

    int res = kruskal();
    if (res == -1)
        puts("impossible");
    else
        printf("%d\n", res);

    return 0;
}