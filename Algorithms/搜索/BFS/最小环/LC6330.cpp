#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/shortest-cycle-in-a-graph/

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);  // 建图
        }

        int dis[n];  // dis[i] 表示从 start 到 i 的最短路长度
        auto bfs = [&](int start) -> int {
            memset(dis, -1, sizeof(dis));
            dis[start] = 0;
            queue<pair<int, int>> q;
            q.emplace(start, -1);
            while (!q.empty()) {
                auto [x, fa] = q.front();
                q.pop();
                for (int y : g[x])
                    if (dis[y] < 0) {  // 第一次遇到
                        dis[y] = dis[x] + 1;
                        q.emplace(y, x);
                    } else if (y != fa)  // 第二次遇到
                        // 由于是 BFS，后面不会遇到更短的环了
                        return dis[x] + dis[y] + 1;
            }
            return INT_MAX;  // 该连通块无环
        };
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)  // 枚举每个起点跑 BFS
            ans = min(ans, bfs(i));
        return ans < INT_MAX ? ans : -1;
    }
};

int main() {
    return 0;
}