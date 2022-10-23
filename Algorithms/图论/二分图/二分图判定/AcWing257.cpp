#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 20010, M = 200010;
int h[N], e[M], w[M], ne[M], idx;
int cl[N];
int n, m;

// https://www.acwing.com/problem/content/259/

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c, int mid) {
    cl[u] = c;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (w[i] <= mid) continue;
        if (!cl[j] && !dfs(j, 3 - c, mid) || cl[j] == c) return false;
    }
    return true;
}

bool check(int mid) {
    memset(cl, 0, sizeof cl);
    for (int i = 1; i <= n; i++) {
        if (!cl[i] && !dfs(i, 1, mid)) return false;
    }
    return true;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    printf("%d\n", l);

    return 0;
}