#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
// https://www.acwing.com/problem/content/description/177/

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = N * N;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0] = 0;
    deque<PII> q;  //双端队列BFS
    q.push_back({0, 0});

    char cs[] = "\\/\\/";
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};

    while (q.size()) {
        PII t = q.front();
        q.pop_front();

        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;

        for (int i = 0; i < 4; i++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m || st[a][b]) continue;
            int ca = t.x + ix[i], cb = t.y + iy[i];

            //堆优化的dijkstra算法中dist[t.x][t.y]这项会和对应的点一起放入优先队列
            int w = (g[ca][cb] != cs[i]);  //权值
            int d = dist[t.x][t.y] + w;

            if (dist[a][b] > d) {
                dist[a][b] = d;
                //以下是与堆优化的dijkstra算法的主要区别
                //距离队头（当前代价最小状态）权值为0的点一定是下一个代价最小状态故要插队放在队头
                if (w)
                    q.push_back({a, b});
                else
                    q.push_front({a, b});
            }
        }
    }

    return dist[n][m];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) scanf("%s", g[i]);

        int t = bfs();

        if (t == 0x3f3f3f3f)
            puts("NO SOLUTION");
        else
            printf("%d\n", t);
    }

    return 0;
}
