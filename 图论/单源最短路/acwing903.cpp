#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int w[N][N], level[N];
int dist[N];
bool st[N];

int dijkstra(int down, int up) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    dist[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        st[t] = true;
        for (int j = 1; j <= n; j++)
            if (level[j] >= down && level[j] <= up)
                dist[j] = min(dist[j], dist[t] + w[t][j]);
    }

    return dist[1];
}

int main() {
    cin >> m >> n;

    memset(w, 0x3f, sizeof w);
    for (int i = 1; i <= n; i++) w[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        w[0][i] = min(price, w[0][i]);  //0号虚拟源点
        while (cnt--) {
            int id, cost;
            cin >> id >> cost;
            w[id][i] = min(w[id][i], cost);
        }
    }

    int res = INF;
    for (int i = level[1] - m; i <= level[1]; i++)  //枚举包括1号点在的范围
        res = min(res, dijkstra(i, i + m));

    cout << res << endl;

    return 0;
}
