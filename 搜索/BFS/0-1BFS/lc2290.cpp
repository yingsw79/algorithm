#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
        dist[0][0] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && dist[a][b] > dist[x][y] + grid[a][b]) {
                    dist[a][b] = dist[x][y] + grid[a][b];
                    if (grid[a][b] == 1) {
                        q.emplace_back(a, b);
                    } else {
                        q.emplace_front(a, b);
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};