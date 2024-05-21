#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-number-of-points-from-grid-queries/
// https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/description/
// https://leetcode.cn/problems/swim-in-rising-water/

class Solution {
    struct Node {
        int i, j, v;
        Node(int i, int j, int v) : i(i), j(j), v(v){};
        bool operator<(const Node& a) const { return v < a.v; }
    };

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        vector<int> p(m * n), sz(m * n, 1), idx(queries.size()), res(queries.size());
        iota(p.begin(), p.end(), 0);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return queries[i] < queries[j]; });
        function<int(int)> find = [&](int x) -> int { return p[x] == x ? x : p[x] = find(p[x]); };
        vector<Node> ns;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ns.emplace_back(i, j, grid[i][j]);
        sort(ns.begin(), ns.end());
        int i = 0;
        for (int x : idx) {
            int q = queries[x];
            for (; i < m * n && ns[i].v < q; i++) {
                auto [x, y, v] = ns[i];
                int u = find(x * n + y);
                for (int j = 0; j < 4; j++) {
                    int a = x + dx[j], b = y + dy[j];
                    if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] >= q) continue;
                    int v = find(a * n + b);
                    if (u == v) continue;
                    p[v] = u;
                    sz[u] += sz[v];
                }
            }
            if (grid[0][0] < q) res[x] = sz[find(0)];
        }
        return res;
    }
};

int main() {
    return 0;
}