#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/shortest-path-to-get-all-keys/

class Solution {
    struct Node {
        int x, y, s;
        Node(int x, int y, int s) : x(x), y(y), s(s) {}
    };

public:
    int shortestPathAllKeys(vector<string>& g) {
        int dist[31][31][64];
        memset(dist, 0x3f, sizeof dist);
        int m = g.size(), n = g[0].size(), S = 0;
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        queue<Node> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == '@') {
                    dist[i][j][0] = 0;
                    q.emplace(i, j, 0);
                } else if (g[i][j] >= 'a' && g[i][j] <= 'z')
                    S++;
            }

        while (q.size()) {
            auto [x, y, s] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= m || b < 0 || b >= n || g[a][b] == '#') continue;
                if (g[a][b] >= 'a' && g[a][b] <= 'z') {
                    int t = s | 1 << g[a][b] - 'a';
                    if (dist[a][b][t] > dist[x][y][s] + 1) {
                        dist[a][b][t] = dist[x][y][s] + 1;
                        if (t == (1 << S) - 1) return dist[a][b][t];
                        q.emplace(a, b, t);
                    }
                } else if (g[a][b] >= 'A' && g[a][b] <= 'Z') {
                    if (s >> (g[a][b] - 'A') & 1) {
                        if (dist[a][b][s] > dist[x][y][s] + 1) {
                            dist[a][b][s] = dist[x][y][s] + 1;
                            q.emplace(a, b, s);
                        }
                    }
                } else {
                    if (dist[a][b][s] > dist[x][y][s] + 1) {
                        dist[a][b][s] = dist[x][y][s] + 1;
                        q.emplace(a, b, s);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}