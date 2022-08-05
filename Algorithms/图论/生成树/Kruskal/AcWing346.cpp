#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/348/

const int N = 6010;
int p[N], sz[N];
int n;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& a) const {
        return w < a.w;
    }
} edge[N];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;  //n个点
    sort(edge + 1, edge + n);
    int res = 0;
    for (int i = 1; i < n; i++) {  //n-1条边
        int a = find(edge[i].u), b = find(edge[i].v);
        if (a == b) continue;
        res += (edge[i].w + 1) * (sz[a] * sz[b] - 1);
        p[a] = b;
        sz[b] += sz[a];
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        printf("%d\n", kruskal());
    }

    return 0;
}