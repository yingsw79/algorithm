#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes/description/

class Solution {
public:
    using PII = pair<int, int>;
    const int INF = 0x3f3f3f3f;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<PII>> g(n);
        for (auto& e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }
        int dist[n];
        bool st[n];
        memset(dist, 0x3f, sizeof dist);
        memset(st, 0, sizeof st);
        dist[0] = 0;
        vector<int> res(n, -1);
        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (st[u]) {
                continue;
            }
            st[u] = true;
            for (auto& [v, w] : g[u]) {
                int nd = d + w;
                if (nd < disappear[v] && nd < dist[v]) {
                    dist[v] = nd;
                    pq.emplace(nd, v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] < INF) {
                res[i] = dist[i];
            }
        }
        return res;
    }
};

int main() {
    return 0;
}