#include <cstring>
#include <iostream>
using namespace std;

const int N = 505, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;  // 第一个点一定在最小生成树中

    int res = 0;  // 用来存放权值之和
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;

        // 尽早跳出循环防止TLE，如果不加则需要在输出的地方更改
        if (dist[t] == INF) return INF;
        res += dist[t];
        st[t] = true;

        // 注意和dijkstra的区别
        // prim的dist是到已经生成的树的最短距离
        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF)
        cout << "impossible" << endl;   // 如果上面不及时跳出循环则在这里改为(t >= INF / 2)
    else
        cout << t << endl;

    return 0;
}
