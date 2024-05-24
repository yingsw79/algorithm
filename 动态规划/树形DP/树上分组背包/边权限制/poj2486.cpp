#include <cstring>
#include <iostream>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// http://poj.org/problem?id=2486

const int N = 110, M = N << 1;

int n, m;
int h[N], e[M], ne[M], idx;
int f[N][M][2];  // 0表示回到当前节点,1表示不回到当前节点

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int ver = e[i];
        if (ver == father) continue;
        dfs(ver, u);
        for (int j = m; j; j--)
            for (int k = 0; k <= j - 1; k++) {
                f[u][j][1] = max(f[u][j][1], f[u][j - k - 1][0] + f[ver][k][1]);
                if (k <= j - 2) {
                    f[u][j][1] = max(f[u][j][1], f[u][j - k - 2][1] + f[ver][k][0]);
                    f[u][j][0] = max(f[u][j][0], f[u][j - k - 2][0] + f[ver][k][0]);
                }
            }
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        memset(h, -1, sizeof h);
        memset(f, 0, sizeof f);
        idx = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            for (int j = 0; j <= m; j++) {
                f[i][j][0] = f[i][j][1] = x;
            }
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        dfs(1, -1);
        printf("%d\n", max(f[1][m][0], f[1][m][1]));  //从根节点开始,故答案在根节点
    }

    return 0;
}