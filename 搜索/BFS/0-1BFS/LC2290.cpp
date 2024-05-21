#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
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
                if (dist[a][b] > dist[x][y] + grid[a][b]) {
                    dist[a][b] = dist[x][y] + grid[a][b];
                    if (grid[a][b])
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