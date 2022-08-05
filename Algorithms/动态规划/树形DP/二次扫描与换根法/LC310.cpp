#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-height-trees/

class Solution {
public:
    vector<vector<int>> g;
    vector<int> d1, d2, p, up;

    void dfs_d(int u, int fa) {
        for (auto& v : g[u]) {
            if (v == fa) continue;
            dfs_d(v, u);
            int d = d1[v] + 1;
            if (d >= d1[u])
                d2[u] = d1[u], d1[u] = d, p[u] = v;
            else if (d > d2[u])
                d2[u] = d;
        }
    }

    void dfs_u(int u, int fa) {
        for (auto& v : g[u]) {
            if (v == fa) continue;
            if (p[u] == v)
                up[v] = max(up[u], d2[u]) + 1;
            else
                up[v] = max(up[u], d1[u]) + 1;
            dfs_u(v, u);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        d1 = d2 = p = up = vector<int>(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs_d(0, -1);
        dfs_u(0, -1);
        int min_d = n;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = max(d1[i], up[i]);
            min_d = min(min_d, d[i]);
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (d[i] == min_d) res.push_back(i);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}