#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://www.luogu.com.cn/problem/P1273

const int N = 3010;
int h[N], e[N], w[N], ne[N], idx;
int f[N][N];  //f[i][j]为以i为根的子树恰好选择j个用户的总利润(根不一定选故f[i][0]=0为合法状态)！！！
int n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    if (u > n - m) return 1;
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {  //循环的是非叶子节点,不占人数
        int v = e[i];
        int t = dfs(v);  //该组内用户数
        cnt += t;  //该组以及之前组用户数的总和,随着循环动态增加
        for (int j = cnt; j; j--)  //不能直接从用户总数m循环,会TLE!!!!!!
            for (int k = 1; k <= min(t, j); k++)  //不能直接从用户总数m循环,会TLE!!!!!!
                f[u][j] = max(f[u][j], f[u][j - k] + f[v][k] - w[i]);  //附加边权代价
    }
    return cnt;
}

int main() {
    memset(h, -1, sizeof h);
    memset(f, -0x3f, sizeof f);  

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n - m; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(i, x, y);
        }
    }
    for (int i = n - m + 1; i <= n; i++) scanf("%d", &f[i][1]);  //叶子节点初始化
    for (int i = 1; i <= n; i++) f[i][0] = 0;

    dfs(1);
    for (int i = m; i >= 0; i--)
        if (f[1][i] >= 0) {  //因为转播信号是由根节点发出的,故答案在根节点中
            printf("%d\n", i);
            break;
        }

    return 0;
}