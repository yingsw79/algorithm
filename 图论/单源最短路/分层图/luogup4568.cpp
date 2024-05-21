#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 10005, M = 50005 * 2, K = 11;

// https://www.luogu.com.cn/problem/P4568

struct State {
    int v, w, cnt;  // cnt 表示已经使用多少次免费通行权限
    State(int v, int w, int cnt) : v(v), w(w), cnt(cnt) {}
    bool operator<(const State &a) const { return w > a.w; }
};

int n, m, k;
int s, t;
int h[N], w[M], e[M], ne[M], idx;
int dist[N][K];
bool vis[N][K];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s][0] = 0;
    priority_queue<State> pq;
    pq.emplace(s, 0, 0);

    while (!pq.empty()) {
        auto [v, _w, cnt] = pq.top();
        pq.pop();

        if (vis[v][cnt]) continue;
        vis[v][cnt] = true;

        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (cnt < k && dist[j][cnt + 1] > _w) {  //使用一次免费通行
                dist[j][cnt + 1] = _w;
                pq.emplace(j, _w, cnt + 1);
            }
            if (dist[j][cnt] > _w + w[i]) {  //不使用免费通行
                dist[j][cnt] = _w + w[i];
                pq.emplace(j, dist[j][cnt], cnt);
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= k; i++) {
        res = min(res, dist[t][i]);
    }
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &s, &t);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    cout << dijkstra() << endl;

    return 0;
}
