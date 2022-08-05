#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1145/

const int N = 2010, M = 10010;
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

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = 0, k = 0;
    for (int i = 1; i <= m; i++) {
        int t, u, v, w;
        scanf("%d%d%d%d", &t, &u, &v, &w);
        if (t == 1) {
            res += w;
            p[find(u)] = find(v);
        } else {
            edge[k++] = {u, v, w};
        }
    }
    sort(edge, edge + k);
    for (int i = 0; i < k; i++) {
        int a = find(edge[i].u), b = find(edge[i].v);
        if (a == b) continue;
        p[a] = b;
        res += edge[i].w;
    }
    printf("%d\n", res);

    return 0;
}