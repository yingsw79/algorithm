#include <cstring>
#include <iostream>

using namespace std;

// https://www.luogu.com.cn/problem/P2015

const int N = 110, M = N << 1;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int ver = e[i];
        if (ver == father) continue;
        dfs(ver, u);
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= j - 1; k++)  //枚举体积预留一条连向父节点的边
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[ver][k] + w[i]);
    }
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    printf("%d\n", f[1][m]);  //根节点必须保留,故答案在根节点
    return 0;
}
