#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/cut-off-trees-for-golf-event/

class Solution1 {  
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) {
            return 0;
        }

        int row = forest.size();
        int col = forest[0].size();
        int step = 0;
        queue<pair<int, int>> qu;
        vector<vector<bool>> visited(row, vector<bool>(col, false));  //风格1
        qu.emplace(sx, sy);
        visited[sx][sy] = true;
        while (!qu.empty()) {
            step++;
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                auto [cx, cy] = qu.front();
                qu.pop();
                for (int j = 0; j < 4; ++j) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                        if (!visited[nx][ny] && forest[nx][ny] > 0) {
                            if (nx == tx && ny == ty) {
                                return step;
                            }
                            qu.emplace(nx, ny);
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> trees;
        int row = forest.size();
        int col = forest[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i, j);
                }
            }
        }
        sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });

        int cx = 0;
        int cy = 0;
        int ans = 0;
        for (int i = 0; i < trees.size(); ++i) {
            int steps = bfs(forest, cx, cy, trees[i].first, trees[i].second);
            if (steps == -1) {
                return -1;
            }
            ans += steps;
            cx = trees[i].first;
            cy = trees[i].second;
        }
        return ans;
    }
};

class Solution2 {
public:
    struct Tree {
        int x, y, h;
        bool operator<(const Tree& t) const {
            return h < t.h;
        }
    };
    int n, m;
    vector<vector<int>> g;

    int bfs(Tree start, Tree end) {
        if (start.x == end.x && start.y == end.y) return 0;
        queue<Tree> q;
        const int INF = 1e8;
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[start.x][start.y] = 0;  //风格2
        q.push({start});
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = t.x + dx[i], y = t.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y]) {
                    if (dist[x][y] > dist[t.x][t.y] + 1) {
                        dist[x][y] = dist[t.x][t.y] + 1;
                        if (x == end.x && y == end.y) return dist[x][y];
                        q.push({x, y});
                    }
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        g = forest;
        n = g.size(), m = g[0].size();
        vector<Tree> trs;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] > 1)
                    trs.push_back({i, j, g[i][j]});
        sort(trs.begin(), trs.end());
        Tree last = {0, 0};
        int res = 0;
        for (auto& tr : trs) {
            int t = bfs(last, tr);
            if (t == -1) return -1;
            res += t;
            last = tr;
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}