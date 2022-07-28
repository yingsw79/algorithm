#include <cstring>
#include <iostream>

using namespace std;

const int N = 5010, M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt, id[N];
int deg[N];
bool is_bridge[M];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfn[j]) {
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            //如果j走不到u或u的祖先，那么他就不构成一个环，则必然是桥
            if (dfn[u] < low[j]) {
                //无向图的两条边是两两一起存储的
                //异或上1，就能找到另一条边 01-10,00-01,10-11,11-00
                is_bridge[i] = is_bridge[i ^ 1] = true;
            }
        } else if (i != (from ^ 1)) {
            //这里是判断当前的边是不是来路的反向边
            low[u] = min(low[u], dfn[j]);
        }
    }
    if (dfn[u] == low[u]) {
        int y;
        ++dcc_cnt;
        do {
            y = stk[top--];
            id[y] = dcc_cnt;
        } while (y != u);
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    tarjan(1, -1);  //图是连通的，因此从1开始即可
    //无向图有两条边，我们传入一个from，记录来路的边

    for (int i = 0; i < idx; ++i)
        if (is_bridge[i])
            ++deg[id[e[i]]];  //只需加1边，一位正向反向边都存了，我们统一加右边

    //统计度为1的点
    int cnt = 0;
    for (int i = 1; i <= dcc_cnt; ++i)
        if (deg[i] == 1)
            ++cnt;
    cout << (cnt + 1) / 2 << endl;
    return 0;
}
