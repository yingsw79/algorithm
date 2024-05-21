#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int c[4] = {1, 2, 3, 4};
        int dist[m][n];
        bool st[m][n];
        memset(dist, 0x3f, sizeof dist);
        memset(st, 0, sizeof st);
        deque<pair<int, int>> dq;
        dq.emplace_back(0, 0);
        dist[0][0] = 0;
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            if (st[x][y]) continue;
            st[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= m || b < 0 || b >= n || st[a][b]) continue;
                int w = (grid[x][y] != c[i]);
                if (dist[a][b] > dist[x][y] + w) {
                    dist[a][b] = dist[x][y] + w;
                    if (w)
                        dq.emplace_back(a, b);
                    else
                        dq.emplace_front(a, b);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};

int main() {
    system("pause");
    return 0;
}