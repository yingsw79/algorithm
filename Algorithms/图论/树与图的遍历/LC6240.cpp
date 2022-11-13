#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/most-profitable-path-in-a-tree/

class Solution {
public:
    vector<vector<int>> g;
    vector<int> p, pos, amount;

    void dfs(int u, int fa) {
        for (int v : g[u]) {
            if (v == fa) continue;
            p[v] = u;
            dfs(v, u);
        }
    }

    int dfs(int u, int fa, int t) {
        int mx = INT_MIN, val = 0;
        if (pos[u] == -1 || t < pos[u])
            val = amount[u];
        else if (t == pos[u])
            val = amount[u] / 2;
        for (int v : g[u]) {
            if (v == fa) continue;
            mx = max(mx, dfs(v, u, t + 1));
        }
        if (mx == INT_MIN) mx = 0;
        return mx + val;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& _amount) {
        amount = _amount;
        int n = amount.size();
        g.resize(n), p.resize(n), pos.resize(n, -1);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        for (int t = 0;; bob = p[bob]) {
            pos[bob] = t++;
            if (!bob) break;
        }
        return dfs(0, -1, 0);
    }
};

int main() {
    return 0;
}