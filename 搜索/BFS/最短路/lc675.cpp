#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/cut-off-trees-for-golf-event/

class Solution {
public:
    using PII = pair<int, int>;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        vector<PII> pos;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    pos.emplace_back(i, j);
                }
            }
        }
        sort(pos.begin(), pos.end(), [&](PII& a, PII& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        auto bfs = [&](int xs, int ys, int xt, int yt) -> int {
            if (xs == xt && ys == yt) {
                return 0;
            }
            queue<PII> q;
            q.emplace(xs, ys);
            vector<vector<int>> dist(m, vector<int>(n, -1));
            dist[xs][ys] = 0;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        forest[nx][ny] > 0 && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        if (nx == xt && ny == yt) {
                            return dist[nx][ny];
                        }
                        q.emplace(nx, ny);
                    }
                }
            }
            return -1;
        };
        pos.insert(pos.begin(), {0, 0});
        int res = 0;
        for (int i = 1; i < pos.size(); i++) {
            int d = bfs(pos[i - 1].first, pos[i - 1].second, pos[i].first, pos[i].second);
            if (d == -1) {
                return -1;
            }
            res += d;
        }
        return res;
    }
};
