#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/largest-color-value-in-a-directed-graph/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> g(n), f(n, vector<int>(26));
        vector<int> indeg(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        vector<int> q(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) q[++r] = i;
        }
        while (l <= r) {
            int u = q[l++];
            ++f[u][colors[u] - 'a'];
            for (auto& v : g[u]) {
                for (int i = 0; i < 26; i++)
                    f[v][i] = max(f[v][i], f[u][i]);
                if (--indeg[v] == 0) q[++r] = v;
            }
        }
        if (r < n - 1) return -1;
        int res = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 26; j++)
                res = max(res, f[i][j]);
        return res;
    }
};

signed main() {
    system("pause");
    return 0;
}