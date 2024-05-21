#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1010, M = 20010, K = 1010;

// https://www.luogu.com.cn/problem/P1948

int n, m, k;
int h[N], w[M], e[M], ne[M], idx;
int dist[N][K];
bool vis[N][K];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1][0] = 0;
    queue<PII> q;
    q.emplace(1, 0);
    vis[1][0] = true;

    while (!q.empty()) {
        auto [v, cnt] = q.front();
        q.pop();

        vis[v][cnt] = false;

        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (cnt < k && dist[j][cnt + 1] > dist[v][cnt]) {  //使用一次免费升级
                dist[j][cnt + 1] = dist[v][cnt];
                if (!vis[j][cnt + 1]) {
                    q.emplace(j, cnt + 1);
                    vis[j][cnt + 1] = true;
                }
            }
            if (dist[j][cnt] > max(w[i], dist[v][cnt])) {  //不使用免费升级
                dist[j][cnt] = max(w[i], dist[v][cnt]);
                if (!vis[j][cnt]) {
                    q.emplace(j, cnt);
                    vis[j][cnt] = true;
                }
            }
        }
    }

    int res = INF;
    for (int i = 0; i <= k; i++) {
        res = min(res, dist[n][i]);
    }
    return res == INF ? -1 : res;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    cout << spfa() << endl;

    return 0;
}
