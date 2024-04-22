#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    using PII = pair<int, int>;
    int hash(int a, int b) {
        if (a > b) {
            swap(a, b);
        }
        return a * 256 + b;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.emplace(0, 0);
        int dist[n];
        bool st[n];
        memset(dist, 0x3f, sizeof(dist));
        memset(st, 0, sizeof(st));
        dist[0] = 0;
        unordered_map<int, vector<int>> path;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (st[u]) {
                continue;
            }

            st[u] = true;
            for (auto [v, w] : g[u]) {
                if (dist[v] > d + w) {
                    path[v] = {u};
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                } else if (dist[v] == d + w) {
                    path[v].push_back(u);
                }
            }
        }

        unordered_set<int> est;
        function<void(int)> dfs = [&](int u) {
            auto& pre = path[u];
            if (pre.empty()) {
                return;
            }

            for (auto v : pre) {
                est.insert(hash(u, v));
                dfs(v);
            }
        };
        dfs(n - 1);

        int m = edges.size();
        vector<bool> res(m, false);
        for (int i = 0; i < m; i++) {
            auto& e = edges[i];
            if (est.count(hash(e[0], e[1]))) {
                res[i] = true;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<tuple<int, int, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w, i);
            g[y].emplace_back(x, w, i);
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) {
                continue;
            }
            for (auto [y, w, _] : g[x]) {
                int new_dis = dx + w;
                if (new_dis < dis[y]) {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }

        vector<bool> ans(edges.size());
        // 图不连通
        if (dis[n - 1] == LLONG_MAX) {
            return ans;
        }

        // 从终点出发 DFS
        vector<int> vis(n);
        function<void(int)> dfs = [&](int y) {
            vis[y] = true;
            for (auto [x, w, i] : g[y]) {
                if (dis[x] + w != dis[y]) {
                    continue;
                }
                ans[i] = true;
                if (!vis[x]) {
                    dfs(x);
                }
            }
        };
        dfs(n - 1);
        return ans;
    }
};

int main() {
    return 0;
}