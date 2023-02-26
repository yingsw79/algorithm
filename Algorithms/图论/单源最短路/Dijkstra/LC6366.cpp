#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-time-to-visit-a-cell-in-a-grid/

class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minimumTime(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;  // 无法「等待」

        int dis[m][n], st[m][n];
        memset(dis, 0x3f, sizeof dis);
        memset(st, 0, sizeof st);
        dis[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        for (;;) {
            auto [d, i, j] = pq.top();
            pq.pop();

            // if (st[i][j]) continue;
            // st[i][j] = true;

            if (i == m - 1 && j == n - 1) return d;
            for (auto &q : dirs) {  // 枚举周围四个格子
                int x = i + q[0], y = j + q[1];
                if (0 <= x && x < m && 0 <= y && y < n) {
                    int nd = max(d + 1, grid[x][y]);
                    nd += (nd - x - y) % 2;  // nd 必须和 x+y 同奇偶
                    if (nd < dis[x][y]) {
                        dis[x][y] = nd;  // 更新最短路
                        pq.emplace(nd, x, y);
                    }
                }
            }
        }
    }
};

// https://leetcode.cn/problems/swim-in-rising-water/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

    }
};

int main() {
    return 0;
}