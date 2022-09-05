#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://loj.ac/p/144
// https://loj.ac/p/145

const int N = 1000010, M = N << 1;
int h[N], e[M], ne[M], idx;
int a[N], in[N], out[N], timestamp;
int n, m, root;
LL tr[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int fa) {  // 求dfs序
    in[u] = ++timestamp;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
    }
    out[u] = timestamp;
}

void update(int x, int v) {
    for (; x <= n; x += lowbit(x)) tr[x] += v;
}

LL query(int x) {
    LL res = 0;
    for (; x; x &= x - 1) res += tr[x];
    return res;
}

int main() {
    memset(h, -1, sizeof h);

    scanf("%d%d%d", &n, &m, &root);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    for (int i = 1, a, b; i < n; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(root, -1);

    for (int i = 1; i <= n; ++i) update(in[i], a[i]);

    for (int i = 0, op, x, v; i < m; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &x, &v);
            update(in[x], v);
        } else {
            scanf("%d", &x);
            printf("%lld\n", query(out[x]) - query(in[x] - 1));
        }
    }

    return 0;
}