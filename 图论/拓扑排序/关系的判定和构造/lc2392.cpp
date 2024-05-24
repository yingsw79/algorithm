#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/build-a-matrix-with-conditions/

class Solution {
public:
    int k;
    unordered_map<int, int> row, col;

    bool topsort(vector<vector<int>>& m, unordered_map<int, int>& mp) {
        vector<vector<int>> g(k + 1);
        vector<int> indeg(k + 1);
        int idx = 0;
        for (auto& r : m) {
            g[r[0]].push_back(r[1]);
            ++indeg[r[1]];
        }
        vector<int> q(k);
        int l = 0, r = -1;
        for (int i = 1; i <= k; ++i) {
            if (!indeg[i]) q[++r] = i;
        }
        while (l <= r) {
            int u = q[l++];
            mp[u] = idx++;
            for (auto& v : g[u]) {
                if (--indeg[v] == 0) q[++r] = v;
            }
        }
        if (r == k - 1) return true;
        return false;
    }

    vector<vector<int>> buildMatrix(int _k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        k = _k;
        if (!topsort(rowConditions, row) || !topsort(colConditions, col)) return {};
        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int i = 1; i <= k; ++i) {
            res[row[i]][col[i]] = i;
        }
        return res;
    }
};

int main() {
        return 0;
}