#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/shortest-bridge/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        vector<vector<bool>> st(n, vector<bool>(n));
        function<void(int, int)> dfs = [&](int x, int y) {
            grid[x][y] = 0;
            st[x][y] = true;
            q.emplace(x, y);
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= n || grid[a][b] != 1) continue;
                dfs(a, b);
            }
        };
        auto bfs = [&]() -> int {
            int d = 0;
            while (q.size()) {
                int sz = q.size();
                while (sz--) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int a = x + dx[i], b = y + dy[i];
                        if (a < 0 || a >= n || b < 0 || b >= n || st[a][b]) continue;
                        if (grid[a][b] == 1) return d;
                        q.emplace(a, b);
                        st[a][b] = true;
                    }
                }
                d++;
            }
            return -1;
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) {
                    dfs(i, j);
                    return bfs();
                }
        return -1;
    }
};

int main() {
    return 0;
}