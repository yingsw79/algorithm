#include <cstring>
#include <iostream>

using namespace std;

// https://www.acwing.com/problem/content/10/

const int N = 110;

int n, m, root;
int h[N], e[N], ne[N], idx;
int v[N], w[N];
int f[N][N];  //不超过！！！！！！

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

void dfs(int u) {
    //先枚举所有状态体积小于等于j-v[u]的所有子节点们能够获得的最大价值
    for (int i = h[u]; ~i; i = ne[i]) {
        int son = e[i];
        dfs(son);  //从下往上算，先计算子节点的状态
        //枚举所有要被更新的状态
        for (int j = m - v[u]; j >= 0; --j) {  //为根节点预留体积
            //枚举该子节点在体积j下能使用的所有可能体积数!!!!!!!!
            for (int k = 0; k <= j; ++k) {  //k=0时等价于不选可直接从1开始
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
            }
        }
    }
    //最后选上第u件物品!!!!!!!!
    for (int j = m; j >= v[u]; --j) f[u][j] = f[u][j - v[u]] + w[u];
    for (int j = 0; j < v[u]; ++j) f[u][j] = 0;  //清空没选上u的所有状态!!!!!!!!!!
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> v[i] >> w[i] >> p;
        if (p == -1)
            root = i;
        else
            add(p, i);
    }
    dfs(root);
    cout << f[root][m] << endl;  //因为根节点必选,所以答案在根节点
    return 0;
}
