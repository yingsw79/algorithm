#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.acwing.com/problem/content/1148/

const int N = 310;
int dist[N], g[N][N];
bool st[N];
int n;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    int res = 0;
    for (int i = 0; i <= n; i++) {  //循环n+1轮
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
        st[t] = true;
        res += dist[t];
        for (int j = 0; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[0][i]);
        g[i][0] = g[0][i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    printf("%d\n", prim());

    return 0;
}