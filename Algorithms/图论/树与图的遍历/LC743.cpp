#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int g[n + 1][n + 1], dist[n + 1];
        bool st[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(g, 0x3f, sizeof g);
        memset(st, 0, sizeof st);
        dist[k] = 0;
        for (auto& t : times) {
            g[t[0]][t[1]] = t[2];
        }
        for (int i = 1; i < n; i++) {
            int t = -1;
            for (int j = 1; j <= n; j++)
                if (!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
            st[t] = true;
            for (int j = 1; j <= n; j++)
                dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};

class Solution {
public:
    typedef pair<int, int> PII;
    const int INF = 0x3f3f3f3f;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<PII> g[n + 1];
        int dist[n + 1];
        bool st[n + 1];
        memset(dist, 0x3f, sizeof dist);
        memset(st, 0, sizeof st);
        for (auto& t : times) {
            g[t[0]].emplace_back(t[1], t[2]);
        }
        queue<int> q;
        q.push(k);
        st[k] = true;
        dist[k] = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            st[u] = false;
            for (auto& [v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (!st[v]) {
                        q.push(v);
                        st[v] = true;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};

signed main() {
    system("pause");
    return 0;
}