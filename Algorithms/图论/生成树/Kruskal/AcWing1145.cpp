#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/description/1147/

const int N = 510, M = N * (N - 1) / 2;

int n, m, k;
PII q[N];
int p[N];

struct Edge {
    int a, b;
    double w;
    bool operator<(const Edge& E) const {
        return w < E.w;
    }
} edge[M];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

double get(PII a, PII b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

double kruskal() {
    if (n <= k) return 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    sort(edge, edge + m);
    int cnt = n;
    for (int i = 0; i < m; i++) {
        int a = find(edge[i].a);
        int b = find(edge[i].b);
        if (a == b) continue;
        p[a] = b;
        if (--cnt == k) return edge[i].w;
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d", &q[i].first, &q[i].second);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            edge[m++] = {i, j, get(q[i], q[j])};

    printf("%.2lf\n", kruskal());

    return 0;
}