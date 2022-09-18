#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/making-a-large-island/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        vector<int> p(n * n), sz(n * n, 1);
        for (int i = 0; i < n * n; ++i) p[i] = i;

        function<int(int)> find = [&](int x) -> int {
            return p[x] == x ? x : p[x] = find(p[x]);
        };

        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    int x = find(i * n + j);
                    res = max(res, sz[x]);
                    for (int k = 0; k < 4; ++k) {
                        int a = i + dx[k], b = j + dy[k];
                        if (a < 0 || a >= n || b < 0 || b >= n || !grid[a][b]) continue;
                        int y = find(a * n + b);
                        if (x == y) continue;
                        p[y] = x;
                        sz[x] += sz[y];
                    }
                }
            }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    int t = 1;
                    unordered_set<int> st;
                    for (int k = 0; k < 4; ++k) {
                        int a = i + dx[k], b = j + dy[k];
                        if (a < 0 || a >= n || b < 0 || b >= n || !grid[a][b]) continue;
                        st.insert(find(a * n + b));
                    }
                    for (int x : st) t += sz[x];
                    res = max(res, t);
                }
            }
        return res;
    }
};

int main() {
    

    return 0;
}